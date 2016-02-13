#include "SpiderLeg.h"

class Spider {
  public:
    static Spider* create();

  private:
    SpiderLeg* _frontRight;
    SpiderLeg* _frontLeft;
    SpiderLeg* _midRight;
    SpiderLeg* _midLeft;
    SpiderLeg* _backRight;
    SpiderLeg* _backLeft;
    
    Spider();

  public:
    void calibrate();
    void ease();
    void stand();
    void prepare();
    void storage();
    void forward();
};

