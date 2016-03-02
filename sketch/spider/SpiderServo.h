#include <Servo.h>
#include <WString.h>

#define SERVO_NOT_INVERTED false
#define SERVO_INVERTED true

class SpiderServo {

    // Attributes =====================================
  private:
    Servo _servo;
    String _name;
    int _desiredAngle = 90;
    int _currentAngle = 90;
    int _angleTreshold = 0;
    int _pin = -1;
    int _minAngle = 5;
    int _maxAngle = 170;
    bool _reverseAngle = false;

    // Construction ===================================
  private:
    SpiderServo(String name, int pin, bool reverseAngle, int startAngle);
  public:
    static SpiderServo* create(String name, int pin, bool reverseAngle, int startAngle);

    // Methods ========================================
  private:
    void writeAngle(int angle);
    int getRealAngle(int angle);
    int allowedAngle();
    
  public:
    void setAngle(int angle);
    void setAngleImmed(int angle);    
    int getDesiredAngle();
    int getCurrentAngle();
    void update(int deltaT);
    void setBounds(int minAngle, int maxAngle);
    bool isMotionFinished();
    void diagnostics();
};

