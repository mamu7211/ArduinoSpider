#include "Spider.h"
#include <Arduino.h>

Spider::Spider() {
  _frontRight = SpiderLeg::createRightLeg("FRONT",37);
  delay(250);
  _midRight = SpiderLeg::createRightLeg("MID",34);
  delay(250);
  _backRight = SpiderLeg::createRightLeg("BACK",31);
  delay(250);
  _frontLeft = SpiderLeg::createLeftLeg("FRONT",28);
  delay(250);
  _midLeft = SpiderLeg::createLeftLeg("MID",25);
  delay(250);
  _backLeft = SpiderLeg::createLeftLeg("BACK",22);
  delay(250);

  _legs[0] = _frontRight;
  _legs[1] = _frontLeft;
  _legs[2] = _midRight;
  _legs[3] = _midLeft;
  _legs[4] = _backRight;
  _legs[5] = _backLeft;

  _selectedLeg = _frontRight;
}

Spider* Spider::create() {
  Spider *spider = new Spider();
  return spider;
}

void Spider::updateSequence() {

  if (!isMotionFinished()) {
    return;
  }

  if (_sequence.equals("ease")) {
    _sequence = "prepare";
    prepare();
  }else if (_sequence.equals("prepare")) {
    _sequence = "standback";
    standBack();
  }else if(_sequence.equals("standback")) {
    _sequence = "standfront";
    standFront();
  }else if(_sequence.equals("standfront")) {
    _sequence = "stand";
    stand();
  }else if(_sequence.equals("stand")) {
    _sequence = "standleft";
    halfStandLeft();
  }else if(_sequence.equals("standleft")) {
    halfStandRight();
    _sequence = "standright";
  }else if(_sequence.equals("standright")) {
    halfStandLeft();
    _sequence = "standleft";
  }
  delay(150);
}

bool Spider::isMotionFinished() {
  return _frontRight->isMotionFinished() &&
    _frontLeft->isMotionFinished() &&
    _backRight->isMotionFinished() &&
    _backLeft->isMotionFinished() &&
    _midRight->isMotionFinished() &&
    _midLeft->isMotionFinished();
}


void Spider::update(int deltaT) {

  _frontRight->updateRotate(deltaT);
  _frontLeft->updateRotate(deltaT);
  _backRight->updateRotate(deltaT);
  _backLeft->updateRotate(deltaT);
  _midRight->updateRotate(deltaT);
  _midLeft->updateRotate(deltaT);

  
  _frontRight->updateTip(deltaT);
  _frontLeft->updateTip(deltaT);
  _backRight->updateTip(deltaT);
  _backLeft->updateTip(deltaT);
  _midRight->updateTip(deltaT);
  _midLeft->updateTip(deltaT);

  
  _frontRight->updateMid(deltaT);
  _frontLeft->updateMid(deltaT);
  _backRight->updateMid(deltaT);
  _backLeft->updateMid(deltaT);
  _midRight->updateMid(deltaT);
  _midLeft->updateMid(deltaT);
}


void Spider::halfStandRight() {
  _frontRight->halfStand();
  _midRight->halfStand();
  _backRight->halfStand();

  _frontLeft->stand();
  _midLeft->stand();
  _backLeft->stand();
}

void Spider::halfStandLeft() {
  _frontLeft->halfStand();
  _midLeft->halfStand();
  _backLeft->halfStand();
  
  _frontRight->stand();
  _midRight->stand();
  _backRight->stand();
}

void Spider::selectLeg(int leg) {
  int selection = constrain(leg,0,5);
  _selectedLeg = _legs[selection];
}

void Spider::wave() {
  _selectedLeg->up();
  delay(500);
  _selectedLeg->stand();
  delay(500);
}

void Spider::calibrate(){
  _frontRight->calibrate();
  _frontLeft->calibrate();
  _midRight->calibrate();
  _midLeft->calibrate();
  _backRight->calibrate();
  _backLeft->calibrate();
}

void Spider::ease(){
  _frontRight->ease();
  _frontLeft->ease();
  _midRight->ease();
  _midLeft->ease();
  _backRight->ease();
  _backLeft->ease();
}

void Spider::prepare(){
  _frontRight->prepare();
  _frontLeft->prepare();
  _midRight->prepare();
  _midLeft->prepare();
  _backRight->prepare();
  _backLeft->prepare();
}

void Spider::stand(){
  _backRight->stand();
  _backLeft->stand();
  _frontRight->stand();
  _frontLeft->stand();
  _midRight->stand();
  _midLeft->stand();
}

void Spider::standBack() {
  _backRight->stand();
  _backLeft->stand();
}

void Spider::standFront() {
  _frontRight->stand();
  _frontLeft->stand();
}

void Spider::storage() {
  _frontRight->storage();
}

void Spider::forward() {
  _frontRight->up();
  delay(200);
  _midLeft->up();
  delay(200);
  _backRight->up();
  delay(200);

  _frontLeft->back();
  _midRight->back();
  _backLeft->back();
  delay(200);
  
  _frontRight->forward();
  delay(200);  
  _midLeft->forward();
  delay(200);  
  _backRight->forward();
  delay(200);
  
  _frontRight->stand();
  delay(200);  
  _midLeft->stand();
  delay(200);  
  _backRight->stand();
  delay(200);
  
  _frontLeft->up();
  delay(200);  
  _midRight->up();
  delay(200);  
  _backLeft->up();
  delay(200);


  _frontLeft->forward();
  delay(200);
  _midRight->forward();
  delay(200);
  _backRight->forward();
  delay(200);
  _frontRight->back();
  _midLeft->back();
  _backRight->back();
  
  delay(200);
  _frontLeft->stand();
  _midRight->stand();
  _backLeft->stand();
}
