#include "SpiderLeg.h"

// Construction and Factory Methods -------------------

/**
 * Creates a SpiderLeg instance.
 */
SpiderLeg::SpiderLeg(String prefix, int firstPin, bool isInverted) {
  servoTip = SpiderServo::create(prefix + "_TIP", firstPin, !isInverted);
  servoMid = SpiderServo::create(prefix + "_MID", firstPin+1, isInverted);
  servoRotate = SpiderServo::create(prefix + "_ROT", firstPin+2, isInverted);

  servoTip->setBounds(0,180);
  servoMid->setBounds(0,180);
  servoRotate->setBounds(65,115);
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
  this->servoTip->setAngle(90);
  this->servoMid->setAngle(135);
  this->servoRotate->setAngle(90);
 }

 void SpiderLeg::calibrate() {
  this->servoTip->setAngle(90);
  this->servoMid->setAngle(90);
  this->servoRotate->setAngle(90);
 }

void SpiderLeg::storage() {
  this->servoTip->setAngle(0);
  this->servoMid->setAngle(90);
  this->servoRotate->setAngle(90);
}

void SpiderLeg::prepare() {
  this->servoTip->setAngle(0);
  this->servoMid->setAngle(90);
  this->servoRotate->setAngle(90);
 }

 void SpiderLeg::stand() {
  this->servoTip->setAngle(145);
  this->servoMid->setAngle(0);
 }

 void SpiderLeg::halfStand() {
  this->servoMid->setAngle(120);
  this->servoTip->setAngle(40);
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

 void SpiderLeg::setTip(int angle) {
  this->servoTip->setAngle(angle);
 }

 void SpiderLeg::setMid(int angle) {
  this->servoMid->setAngle(angle);
 }

 void SpiderLeg::setRotate(int angle) {
  this->servoRotate->setAngle(angle);
 }

 void SpiderLeg::update(int deltaT) {
  updateTip(deltaT);
  updateMid(deltaT);
  updateRotate(deltaT);
 }

void SpiderLeg::updateTip(int deltaT) {
  this->servoTip->update(deltaT);  
}

void SpiderLeg::updateMid(int deltaT) {
  this->servoMid->update(deltaT);
}

void SpiderLeg::updateRotate(int deltaT) {
  this->servoRotate->update(deltaT);
}

bool SpiderLeg::isMotionFinished() {
  return this->servoTip->isMotionFinished() &&
    this->servoMid->isMotionFinished() &&
    this->servoRotate->isMotionFinished();
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

