#include "SpiderLeg.h"

// Construction and Factory Methods -------------------

/**
 * Creates a SpiderLeg instance.
 */
SpiderLeg::SpiderLeg(String prefix, int firstPin, bool isInverted) {
  servoTip = SpiderServo::create(prefix + "_TIP", firstPin, isInverted);
  servoMid = SpiderServo::create(prefix + "_MID", firstPin+1, isInverted);
  servoRotate = SpiderServo::create(prefix + "_ROT", firstPin+2, isInverted);

  servoTip->setBounds(10,170);
  servoMid->setBounds(10,170);
  servoRotate->setBounds(70,110);
}

/**
 * Creates a SpiderLeg instance for a left leg.
 */
SpiderLeg* SpiderLeg::createLeftLeg(String prefix, int firstPin) {
  return new SpiderLeg(prefix + "_RIGHT", firstPin,SERVO_INVERTED);
}

/**
 * Creates a SpiderLeg instance for a right leg.
 */
SpiderLeg* SpiderLeg::createRightLeg(String prefix, int firstPin) {
  return new SpiderLeg(prefix + "_LEFT", firstPin,SERVO_NOT_INVERTED);
}

/* 
 * Methods
 */

 void SpiderLeg::ease() {
  this->servoTip->setAngle(140);
  this->servoMid->setAngle(10);
  this->servoRotate->setAngle(90);
 }

 void SpiderLeg::calibrate() {
  this->servoTip->setAngle(90);
  this->servoMid->setAngle(90);
  this->servoRotate->setAngle(90);
 }

void SpiderLeg::prepare() {
  this->servoTip->setAngle(170);
  this->servoMid->setAngle(170);
  this->servoRotate->setAngle(90);
 }

 void SpiderLeg::stand() {
  this->servoTip->setAngle(0);
  this->servoMid->setAngle(10);
 }

 void SpiderLeg::up() {
  this->servoTip->setAngle(160);
  this->servoMid->setAngle(160);
 }

 void SpiderLeg::back() {
  this->servoRotate->setAngle(70);
 }

 void SpiderLeg::forward() {
  this->servoRotate->setAngle(110);
 }

void SpiderLeg::forwardMotion() {
  up();
  delay(800);
  forward();
  delay(800);
  stand();
  delay(800);
  back();
  delay(800);
}

