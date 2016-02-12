#include <Arduino.h>
#include "SpiderServo.h"

/**
 * SpiderServo Factory
 */
SpiderServo* SpiderServo::create(String prefix, int pin, bool reverseAngle) {
  return new SpiderServo(prefix, pin,reverseAngle);
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
  _servo.write(actualAngle);
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

