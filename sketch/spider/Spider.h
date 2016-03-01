#include "SpiderLeg.h"

class Spider {
    // Attributes =====================================
  public:
    SpiderLeg* _selectedLeg;

  private:
    SpiderLeg* _legs[4];
    SpiderLeg* _frontRight;
    SpiderLeg* _frontLeft;
    SpiderLeg* _backRight;
    SpiderLeg* _backLeft;

    // Construction ===================================
  private:
    Spider();

  public:
    static Spider* create();

    // Methods ========================================
  public:
    void diagnostics();
    void setHeight(int height);
    void selectLeg(int legNumber);
    void update(int deltaT);
};

