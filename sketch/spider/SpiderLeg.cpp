#include "SpiderLeg.h"

// Construction and Factory Methods -------------------

#define BOUNDS_SAFETIP 5
int SpiderLeg::SafeTipBounds[BOUNDS_SAFETIP][2] = {
  {95, 5},
  {75, 25},
  {65, 45},
  {55, 65},
  {45, 75}
};

#define BOUNDS_CENTER 7
int SpiderLeg::CenterAngles[BOUNDS_CENTER][2] = {
  {100,30},
  {90,40},
  {80,60},
  {70,80},
  {60,100},
  {50,120},
  {40,140}
};

/**
   Creates a SpiderLeg instance.
*/
SpiderLeg::SpiderLeg(String prefix, int firstPin, bool isInverted) {
  _isInverted = isInverted;
  name = prefix + "-Leg";

  servoRotate->setBounds(65, 115);
  servoRotate = SpiderServo::create(prefix + "-Rotate", firstPin, isInverted);
  servoRotate->setAngle(80);
  delay(100);
  
  servoMid = SpiderServo::create(prefix + "-Mid", firstPin + 1, isInverted);
  servoMid->setBounds(40, 180);
  servoMid->setAngle(160);
  delay(100);
  
  servoTip = SpiderServo::create(prefix + "-Tip", firstPin + 2, !isInverted);
  servoTip->setBounds(0, 180);  
  servoTip->setAngle(160);
  delay(100);
}

void SpiderLeg::setHeight(int height) {
  float factor = constrain(height,0,100)/100.0f;
  int angle = 100 - 60*factor;
  servoMid->setAngle(angle+_roll);
  servoTip->setAngle(140*factor);
}

void SpiderLeg::setRoll(int roll) {
  //servoMid->setDelta(roll * (_isInverted?-1:1));
}

void SpiderLeg::diagnostics() {
  Serial.println("\t[" + name);
  servoTip->diagnostics();
  servoMid->diagnostics();
  servoRotate->diagnostics();
  Serial.println("\t]");
}

/**
   Creates a SpiderLeg instance for a left leg.
*/
SpiderLeg* SpiderLeg::createLeftLeg(String prefix, int firstPin) {
  return new SpiderLeg(prefix + "-Left", firstPin, SERVO_INVERTED);
}

/**
   Creates a SpiderLeg instance for a right leg.
*/
SpiderLeg* SpiderLeg::createRightLeg(String prefix, int firstPin) {
  return new SpiderLeg(prefix + "-Right", firstPin, SERVO_NOT_INVERTED);
}

/*
   Methods
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
  this->servoTip->setAngle(20);
  this->servoMid->setAngle(180);
  this->servoRotate->setAngle(90);
}

void SpiderLeg::stand() {
  this->servoTip->setAngle(160);
  this->servoMid->setAngle(30);
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
  updateBounds();
}

void SpiderLeg::setMid(int angle) {
  this->servoMid->setAngle(angle);
  updateBounds();
}

void SpiderLeg::setRotate(int angle) {
  this->servoRotate->setAngle(angle);
  updateBounds();
}

void SpiderLeg::update(int deltaT) {
  updateBounds();
  updateTip(deltaT);
  updateMid(deltaT);
  updateRotate(deltaT);
}

void SpiderLeg::updateBounds() {

  int val = 0; 
  int i = 0;
  for (i = 0; i < BOUNDS_SAFETIP; i++) {
    if (this->servoMid->getCurrentAngle() <= SafeTipBounds[i][0]) {
      val = SafeTipBounds[i][1];
    }
  }
  this->servoTip->setBounds(val, 180);
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

