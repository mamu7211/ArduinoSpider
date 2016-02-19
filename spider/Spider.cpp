#include "Spider.h"
#include <Arduino.h>

Spider::Spider() {
  _frontRight = SpiderLeg::createRightLeg("FRONT",22);
  _midRight = SpiderLeg::createRightLeg("MID",25);
  _backRight = SpiderLeg::createRightLeg("BACK",28);
  
  _frontLeft = SpiderLeg::createLeftLeg("FRONT",31);
  
  _midLeft = SpiderLeg::createLeftLeg("MID",34);
  
  _backLeft = SpiderLeg::createLeftLeg("BACK",37);

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
    delay(250);
  _frontLeft->calibrate();
    delay(250);
  _midRight->calibrate();
    delay(250);
  _midLeft->calibrate();
    delay(250);
  _backRight->calibrate();
    delay(250);
  _backLeft->calibrate();
}

void Spider::ease(){
  _frontRight->ease();
  delay(500);
  _frontLeft->ease();
    delay(500);
  _midRight->ease();
    delay(500);
  _midLeft->ease();
    delay(500);
  _backRight->ease();
    delay(500);
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
  delay(50);
  _backRight->stand();
  delay(50);
  _backLeft->stand();
  delay(250);
  _frontRight->stand();
  delay(50);
  _frontLeft->stand();
  delay(50);
  _midRight->stand();
  delay(50);
  _midLeft->stand();

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

