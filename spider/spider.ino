
#include "SpiderLeg.h"

SpiderLeg *frontRight;
SpiderLeg *frontLeft;

void setup() {
  Serial.begin(9600);
  frontRight = SpiderLeg::createRightLeg("FRONT",22);
  frontLeft = SpiderLeg::createLeftLeg("FRONT",26);
}

void loop() {
  // put your main code here, to run repeatedly:
  frontRight->ease();
  frontLeft->ease();
  delay(1000);
}
