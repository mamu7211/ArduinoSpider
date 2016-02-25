#include <Arduino.h>
#include "SpiderServo.h"

/**
 * SpiderServo Factory
 */
SpiderServo* SpiderServo::create(String prefix, int pin, bool reverseAngle) {
  SpiderServo *servo =  new SpiderServo(prefix, pin,reverseAngle);
  return servo;
}

SpiderServo::SpiderServo(String prefix, int pin, bool reverseAngle) {
  _name = prefix;
  _reverseAngle = reverseAngle;
  _servo.attach(pin);
}

/**
 * 
 */
void SpiderServo::setAngle(int angle) {
  int actualAngle = _reverseAngle ? 180 - angle : angle;
  actualAngle = constrain(actualAngle,this->_minAngle,this->_maxAngle);
  _desiredAngle = actualAngle;
}

void SpiderServo::update(int deltaT) {

  int increment = _currentAngle < _desiredAngle ? _angleTreshold/3*2 : -_angleTreshold/3*2;

  if ( isMotionFinished() ) {
    return;
  }

  _currentAngle += increment;
  
  _servo.write(_currentAngle);

  delay(deltaT);
}

bool SpiderServo::isMotionFinished() {
  return _currentAngle >= _desiredAngle - _angleTreshold
  && _currentAngle <= _desiredAngle + _angleTreshold;
}

void SpiderServo::setBounds(int minAngle, int maxAngle) {

  _minAngle = constrain(min(minAngle,maxAngle),10,170);
  _maxAngle = constrain(max(minAngle,maxAngle),10,170);
  
  Serial.print("Bounds for " + _name + " [");
  Serial.print(_minAngle,DEC);
  Serial.print(", ");
  Serial.print(_maxAngle,DEC);
  Serial.println("]");
}

