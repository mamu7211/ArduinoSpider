#include "SpiderServo.h"
#include <Arduino.h>
#include <WString.h>

class SpiderLeg {

    // Members --------------------------
  private:
    String name;
    int _roll;
    bool _isInverted;    
    SpiderServo *servoTip;
    SpiderServo *servoMid;
    SpiderServo *servoRotate;

    static int SafeTipBounds[][2];
    static int CenterAngles[][2];

    // Construction ----------------------
  private:
    SpiderLeg(String prefix, int firstPin, bool isInverted);

    // Methods --------------------------

  private:
    void updateBounds();
    void updateTip(int deltaT);
    void updateMid(int deltaT);
    void updateRotate(int deltaT);

  public:
    void calibrate();
    void ease();
    void storage();
    void diagnostics();
    void stand();
    void halfStand();
    void prepare();
    void up();
    void forward();
    void back();

    void setTip(int angle);
    void setMid(int);
    void setRotate(int);
    void setRoll(int);

    void setHeight(int height);
    
    void update(int deltaT);

    bool isMotionFinished();

    void forwardMotion();

    // Static Factory Methods
  public:
    static SpiderLeg* createLeftLeg(String prefix, int firstPin);
    static SpiderLeg* createRightLeg(String prefix, int firstPin);
};

