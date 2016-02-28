#include "SpiderLeg.h"

class Spider {
  public:
    static Spider* create();

  private:
    SpiderLeg* _legs[6];
    SpiderLeg* _frontRight;
    SpiderLeg* _frontLeft;
    SpiderLeg* _midRight;
    SpiderLeg* _midLeft;
    SpiderLeg* _backRight;
    SpiderLeg* _backLeft;
    String _sequence = "ease";
    
    Spider();

  public:
   SpiderLeg* _selectedLeg;

  public:
    void calibrate();
    void ease();
    void storage();
    void stand();
    void standBack();
    void standFront();
    void halfStandRight();
    void halfStandLeft();
    void prepare();
    void forward();
    void diagnostics();

    void wiggle();
    void wave();

    void setHeight(int height);
    void setRoll(int angle);
    
    void selectLeg(int legNumber);

    void update(int deltaT);
    bool isMotionFinished();
    void updateSequence();
};

