#include "Spider.h"

Spider *spider;

void setup() {
  Serial.begin(19600);
  spider = Spider::create();
  spider->ease();
}

void loop() {
  //spider->updateSequence();
  spider->update(0);
  commands();
}

void commands() {
  if (Serial.available()) {
    String cmd = Serial.readStringUntil(':');
    cmd.toLowerCase();
    cmd.trim();
    Serial.println("CMD = " + cmd);
    if (cmd.equals("dia")) {
      spider->diagnostics();
    }else if (cmd.startsWith("height")){
      setHeight(cmd);
    }else if (cmd.startsWith("roll")) {
      setRoll(cmd);
    }
  }

  spider->update(1);
  //delay(10);
}

void setHeight(String cmd) {
  int i = 0;
  String servo = cmd;
  servo.replace("height", "");
  int height = servo.toInt();
  spider->setHeight(height);
}

void setRoll(String cmd) {
  int i = 0;
  String servo = cmd;
  servo.replace("roll", "");
  int roll = servo.toInt();
  spider->setRoll(roll);
}


void doit(String cmd) {
  int i = 0;
  String servo = cmd;
  servo.replace("g", "");
  for (int i = 0; i < 6; i++) {
    int angle = servo.toInt();
    spider->selectLeg(i);
    spider->_selectedLeg->setTip(angle);
    spider->_selectedLeg->setMid(angle);
  }
}

void select(String cmd) {
  String leg = cmd;
  leg.replace("l", "");
  int legNumber = leg.toInt();
  spider->selectLeg(legNumber);
}

void set(String cmd) {
  String servo = cmd;
  int angle;
  if (servo.startsWith("t")) {
    servo.replace("t", "");
    angle = servo.toInt();
    spider->_selectedLeg->setTip(angle);
  }

  if (servo.startsWith("m")) {
    servo.replace("m", "");
    angle = servo.toInt();
    spider->_selectedLeg->setMid(angle);
  }

  if (servo.startsWith("r")) {
    servo.replace("r", "");
    angle = servo.toInt();
    spider->_selectedLeg->setRotate(angle);
  }
}

void wave(String cmd) {
  spider->wave();
}

