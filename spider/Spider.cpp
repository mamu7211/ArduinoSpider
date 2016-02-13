#include "Spider.h"

Spider::Spider() {
  _frontRight = SpiderLeg::createRightLeg("FRONT",22);
  _frontLeft = SpiderLeg::createLeftLeg("FRONT",26);
  _midRight = SpiderLeg::createRightLeg("MID",30);
  _midLeft = SpiderLeg::createLeftLeg("MID",34);
  _backRight = SpiderLeg::createRightLeg("BACK",38);
  _backLeft = SpiderLeg::createLeftLeg("BACK",42);
}

Spider* Spider::create() {
  return new Spider();
}

void Spider::calibrate(){
  _frontRight->calibrate();
    delay(50);
  _frontLeft->calibrate();
    delay(50);
  _midRight->calibrate();
    delay(50);
  _midLeft->calibrate();
    delay(50);
  _backRight->calibrate();
    delay(50);
  _backLeft->calibrate();
}

void Spider::ease(){
  _frontRight->ease();
  delay(50);
  _frontLeft->ease();
    delay(50);
  _midRight->ease();
    delay(50);
  _midLeft->ease();
    delay(50);
  _backRight->ease();
    delay(50);
  _backLeft->ease();
}

void Spider::prepare(){
  _frontRight->prepare();
  delay(50);
  _frontLeft->prepare();
  delay(50);
  _midRight->prepare();
  delay(50);
  _midLeft->prepare();
  delay(50);
  _backRight->prepare();
  delay(50);
  _backLeft->prepare();
}

void Spider::stand(){
  _frontRight->stand();
  delay(50);
  _frontLeft->stand();
  delay(50);
  _midRight->stand();
  delay(50);
  _midLeft->stand();
  delay(50);
  _backRight->stand();
  delay(50);
  _backLeft->stand();
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

