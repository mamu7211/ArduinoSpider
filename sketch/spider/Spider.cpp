#include "Spider.h"
#include <Arduino.h>


Spider* Spider::create() {
  Spider *spider = new Spider();
  return spider;
}

Spider::Spider() {
  _frontRight = SpiderLeg::createRightLeg("Front", 38);  
  delay(250);
  _backRight = SpiderLeg::createRightLeg("Back", 26);
  delay(250);
  _frontLeft = SpiderLeg::createLeftLeg("Front", 42);
  delay(250);
  _backLeft = SpiderLeg::createLeftLeg("Back", 22);
  delay(250);  

  _legs[0] = _frontRight;
  _legs[1] = _frontLeft;
  _legs[2] = _backRight;
  _legs[3] = _backLeft;

  _selectedLeg = _frontRight;
}

void Spider::setHeight(int height) {
  _frontRight->setHeight(height);
  _frontLeft->setHeight(height);
  _backRight->setHeight(height);
  _backLeft->setHeight(height);
}

void Spider::diagnostics() {
  Serial.println("[SPIDER:");
  _frontRight->diagnostics();
  _frontLeft->diagnostics();
  _backRight->diagnostics();
  _backLeft->diagnostics();
  Serial.println("]");
}

void Spider::update(int deltaT) {
  _frontRight->update(deltaT);
  _frontLeft->update(deltaT);
  _backRight->update(deltaT);
  _backLeft->update(deltaT);
}

void Spider::selectLeg(int leg) {
  int selection = constrain(leg, 0, 5);
  _selectedLeg = _legs[selection];
}


