#include "SpiderLeg.h"
#include "SpiderState.h"

#define LEG_COUNT 6

class Spider {
    // Attributes =====================================
  public:
    SpiderLeg* _selectedLeg;

  private:
    SpiderLeg* _legs[LEG_COUNT];
    
    SpiderLeg* _frontRight;
    SpiderLeg* _frontLeft;
    SpiderLeg* _midRight;
    SpiderLeg* _midLeft;
    SpiderLeg* _backRight;
    SpiderLeg* _backLeft;
    
    SpiderState _state = Init;
    SpiderState _lastState = Init;
    
    // Construction ===================================
  private:
    Spider();

  public:
    static Spider* create();

    // Methods ========================================
  public:
    // Service
    void diagnostics();    
    bool isMotionFinished();
    void selectLeg(int legNumber);
    void update(int deltaT);
    void updateState();
    void updatePosition();
    void setState(SpiderState state);
    
    // Action
    void setHeight(int height);    
    void setRotation(int rotation);
    void prepareToStandUp();
    void doBootAllUp();
    void standLow();
    void standHigh();
};

