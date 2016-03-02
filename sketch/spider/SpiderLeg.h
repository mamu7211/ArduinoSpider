#include "SpiderServo.h"
#include <Arduino.h>
#include <WString.h>

class SpiderLeg {

    // Attributes =====================================
  private:
    String name;
    int _roll;
    bool _isInverted;
    SpiderServo *servoTip;
    SpiderServo *servoMid;
    SpiderServo *servoRotate;

    static int SafeTipBounds[][2];

    // Construction ===================================
  private:
    SpiderLeg(String prefix, int firstPin, bool isInverted);
  public:
    static SpiderLeg* createLeftLeg(String prefix, int firstPin);
    static SpiderLeg* createRightLeg(String prefix, int firstPin);

    // Methods ========================================
  private:
    void updateBounds();
    void updateTip(int deltaT);
    void updateMid(int deltaT);
    void updateRotate(int deltaT);

  public:
    void diagnostics();
    void setHeight(int height);
    void doBootAllUp();
    void prepareToStandUp();
    
    void setTip(int angle);
    void setMid(int);
    void setRotate(int);
    void setRoll(int);

    void doRotation(int);

    void update(int deltaT);
    bool isMotionFinished();
};

