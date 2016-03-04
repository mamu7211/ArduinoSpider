#include "Spider.h"
#include <Arduino.h>

String SPIDER_STATE_ENUM_STRING[] {
  "INIT",
  "IDLE",
  "BOUP",
  "PTSU",
  "STLO",
  "STHI",
  "ROPL",
  "ROLE"
};

Spider* Spider::create() {
  Spider *spider = new Spider();
  return spider;
}

Spider::Spider() {
  _frontRight = SpiderLeg::createRightLeg("Front", 38);
  delay(250);
  _midRight = SpiderLeg::createRightLeg("Mid", 30);
  delay(250);
  _backRight = SpiderLeg::createRightLeg("Back", 26);
  delay(250);
  
  _frontLeft = SpiderLeg::createLeftLeg("Front", 42);
  delay(250);
  _midLeft = SpiderLeg::createLeftLeg("Mid", 34);
  delay(250);
  _backLeft = SpiderLeg::createLeftLeg("Back", 22);
  delay(250);



  _legs[0] = _frontRight;
  _legs[1] = _frontLeft;  
  _legs[2] = _midRight;
  _legs[3] = _midLeft;
  _legs[4] = _backRight;
  _legs[5] = _backLeft;
  
  _selectedLeg = _frontRight;
}

void Spider::setHeight(int height) {
  for (int i = 0; i < LEG_COUNT; i++) {
    _legs[i]->setHeight(height);
  }
}

void Spider::setRotation(int rotation) {
  for (int i = 0; i < LEG_COUNT; i++) {
    _legs[i]->setRotate(rotation);
  }
}

void Spider::diagnostics() {
  Serial.println("[SPIDER:");
  for (int i = 0; i < LEG_COUNT; i++) {
    _legs[i]->diagnostics();
  }
  Serial.println("]");
}

bool Spider::isMotionFinished() {
  for (int i = 0; i < LEG_COUNT; i++) {
    if (false == _legs[i]->isMotionFinished())
      return false;
  }
  return true;
}

void Spider::update(int deltaT) {
  updatePosition();
  updateState();
  for (int i = 0; i < LEG_COUNT; i++) {
    _legs[i]->update(deltaT);
  }
}

void Spider::updateState() {
  if (isMotionFinished() == false) {
    return;
  }
  switch (_state) {
    case Init:
      _state = BootAllUp;
      break;
    case BootAllUp:
      _state = PrepareToStandUp;
      break;
    case PrepareToStandUp:
      _state = StandLow;
      break;
    case StandLow:
      _state = StandHigh;
      break;
    case StandHigh:
      _state = Idle;
      break;
  }
  if (_lastState != _state) {
    Serial.println(":CHST=" + SPIDER_STATE_ENUM_STRING[_state]);
    _lastState = _state;
  }
}

void Spider::updatePosition() {
  switch (_state) {
    case BootAllUp:
      doBootAllUp();
      break;
    case PrepareToStandUp:
      prepareToStandUp();
      break;
    case StandLow:
      standLow();
      break;
    case StandHigh:
      standHigh();
      break;
  }
}

void Spider::setState(SpiderState state) {
  _state = state;
  updateState();
}

void Spider::doBootAllUp() {
  for (int i = 0; i < LEG_COUNT; i++) {
    _legs[i]->doBootAllUp();
  }
}

void Spider::prepareToStandUp() {
  for (int i = 0; i < LEG_COUNT; i++) {
    _legs[i]->prepareToStandUp();
  }
}

void Spider::standLow() {
  setHeight(20);
}

void Spider::standHigh() {
  setHeight(100);

}

void Spider::selectLeg(int leg) {
  _selectedLeg = _legs[constrain(leg, 0, LEG_COUNT)];
}


