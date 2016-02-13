#include "SpiderServo.h"
#include <Arduino.h>
#include <WString.h>

class SpiderLeg {

  // Members --------------------------
  private:
  String name;
  SpiderServo *servoTip;
  SpiderServo *servoMid;
  SpiderServo *servoRotate;

  // Construction ----------------------
  private: 
  SpiderLeg(String prefix,int firstPin, bool isInverted);

  // Methods --------------------------
  public:
  void calibrate();
  void ease();
  void stand();
  void prepare();
  void up();
  void forward();  
  void back();

  void forwardMotion();

  // Static Factory Methods
  public:
  static SpiderLeg* createLeftLeg(String prefix, int firstPin);
  static SpiderLeg* createRightLeg(String prefix, int firstPin);
};

