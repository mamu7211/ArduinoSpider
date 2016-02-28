#include <Arduino.h>
#include "SpiderServo.h"

/**
   SpiderServo Factory
*/
SpiderServo* SpiderServo::create(String prefix, int pin, bool reverseAngle) {
  SpiderServo *servo =  new SpiderServo(prefix, pin, reverseAngle);
  return servo;
}

SpiderServo::SpiderServo(String prefix, int pin, bool reverseAngle) {
  _name = prefix + "-Servo";
  _reverseAngle = reverseAngle;
  _servo.attach(pin);
}

/**

*/
void SpiderServo::setAngle(int angle) {
  _desiredAngle = angle;
  constrainDesiredAngle();
}

void SpiderServo::setDelta(int angle) {

}

void SpiderServo::update(int deltaT) {
  constrainDesiredAngle();

  int increment = (_desiredAngle - _currentAngle ) / 10.0f;
  if ( isMotionFinished() ) {
    return;
  }

  _currentAngle += increment;
  int realAngle = _reverseAngle ? 180 - _currentAngle: _currentAngle;
  _servo.write(realAngle);
  delay(deltaT);
}

void SpiderServo::constrainDesiredAngle() {
  _desiredAngle = constrain(_desiredAngle, _minAngle, _maxAngle);
}

bool SpiderServo::isMotionFinished() {
  return _currentAngle >= _desiredAngle - _angleTreshold
         && _currentAngle <= _desiredAngle + _angleTreshold;
}

int SpiderServo::getDesiredAngle() {
  return _desiredAngle;
}

int SpiderServo::getCurrentAngle() {
  return _currentAngle;
}

void SpiderServo::setBounds(int minAngle, int maxAngle) {
  _minAngle = constrain(min(minAngle, maxAngle), 0, 180);
  _maxAngle = constrain(max(minAngle, maxAngle), 0, 180);
  constrainDesiredAngle();
}

void SpiderServo::diagnostics() {
  Serial.print("\t\t[" + _name + ":cur=");
  Serial.print(_currentAngle, DEC);
  Serial.print(":des=");
  Serial.print(_desiredAngle, DEC);
  Serial.print(":min=");
  Serial.print(_minAngle, DEC);
  Serial.print(":max=");
  Serial.print(_maxAngle, DEC);
  Serial.println("]");
}

