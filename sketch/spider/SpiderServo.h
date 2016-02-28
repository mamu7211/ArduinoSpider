#include <Servo.h>
#include <WString.h>

#define SERVO_NOT_INVERTED false
#define SERVO_INVERTED true

class SpiderServo {

  // Factory Method ------------------
  public:
  static SpiderServo* create(String name, int pin, bool reverseAngle);

  // Construction --------------------
  private: 
  SpiderServo(String name, int pin, bool reverseAngle);

  // Members --------------------------
  private:
  Servo _servo;
  String _name;
  int _desiredAngle = 90;
  int _currentAngle = 90;
  int _angleTreshold = 1;
  int _pin = -1;
  int _minAngle = 5;
  int _maxAngle = 170;
  bool _reverseAngle = false;
  
  // Methods
  private:
  void constrainDesiredAngle();
  public:
  void setAngle(int angle);
  int getDesiredAngle();
  int getCurrentAngle();
  void update(int deltaT);
  void setBounds(int minAngle, int maxAngle);
  bool isMotionFinished();
  void setDelta(int angle);
  void diagnostics();
};

