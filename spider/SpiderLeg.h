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
  void storage();
  
  void stand();
  void halfStand();
  void prepare();
  void up();
  void forward();  
  void back();

  void setTip(int angle);
  void setMid(int);
  void setRotate(int);
  void update(int deltaT);
  void updateTip(int deltaT);
  void updateMid(int deltaT);
  void updateRotate(int deltaT);

  bool isMotionFinished();

  void forwardMotion();

  // Static Factory Methods
  public:
  static SpiderLeg* createLeftLeg(String prefix, int firstPin);
  static SpiderLeg* createRightLeg(String prefix, int firstPin);
};

