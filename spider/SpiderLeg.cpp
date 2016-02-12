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
  servoRotate->setBounds(60,120);
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
  this->servoTip->setAngle(20);
  this->servoMid->setAngle(140);
  this->servoRotate->setAngle(90);
 }
 

