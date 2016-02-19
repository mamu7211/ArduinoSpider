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
    
    Spider();

  public:
   SpiderLeg* _selectedLeg;

  public:
    void calibrate();
    void ease();
    void storage();
    void stand();
    void prepare();
    void forward();

    void wave();
    
    void selectLeg(int legNumber);
};

