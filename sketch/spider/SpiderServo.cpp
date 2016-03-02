#include <Arduino.h>
#include "SpiderServo.h"

/**
   SpiderServo Factory
*/
SpiderServo* SpiderServo::create(String prefix, int pin, bool reverseAngle, int startAngle) {
  SpiderServo *servo =  new SpiderServo(prefix, pin, reverseAngle, startAngle);
  return servo;
}

SpiderServo::SpiderServo(String prefix, int pin, bool reverseAngle, int startAngle) {
  _name = prefix + "-Servo";
  _reverseAngle = reverseAngle;
  _servo.attach(pin);
  setAngleImmed(startAngle);
}

/**

*/
void SpiderServo::setAngle(int angle) {
  _desiredAngle = angle;
}

void SpiderServo::setAngleImmed(int angle) {
  Serial.print("IMMED");
  Serial.println(angle,DEC);
  _desiredAngle = angle;
  _currentAngle = angle;
  writeAngle(angle);
}

void SpiderServo::update(int deltaT) {
  int increment = allowedAngle() < _currentAngle ? -1 : 1; 
  if ( isMotionFinished() ) {
    return;
  }
  _currentAngle += increment;
  writeAngle(_currentAngle);
  delay(deltaT);
}

void SpiderServo::writeAngle(int angle) {
  _servo.write(getRealAngle(_currentAngle));
}

int SpiderServo::getRealAngle(int angle) {
  return _reverseAngle ? 180 - _currentAngle: _currentAngle;
}

int SpiderServo::allowedAngle() {
  return constrain(_desiredAngle, _minAngle, _maxAngle);
}

bool SpiderServo::isMotionFinished() {
  return _currentAngle >= allowedAngle() - _angleTreshold
         && _currentAngle <= allowedAngle() + _angleTreshold;
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

