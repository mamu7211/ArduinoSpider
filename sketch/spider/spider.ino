#include "Spider.h"

Spider *spider;

void setup() {
  Serial.begin(9600);
  spider = Spider::create();
  spider->ease();
}

void loop() {
  //spider->updateSequence();
  spider->update(0);
  //commands();
}

void commands() {
  if (Serial.available()) {
    String cmd = Serial.readStringUntil(':');
    cmd.toLowerCase();
    cmd.trim();
    Serial.println("CMD = " + cmd);
    if (cmd.equals("ease")) {
      spider->ease();
    }else if (cmd.equals("stand")) {
      spider->stand();
    }else if (cmd.equals("calibrate")) {
      spider->calibrate();
    }else if (cmd.equals("prepare")) {
      spider->prepare();
    }else if (cmd.equals("store")) {
      spider->storage();
    }else if (cmd.startsWith("l")) {
      select(cmd);
    }else if(cmd.startsWith("t") || cmd.startsWith("m") || cmd.startsWith("r")) {
      set(cmd);
    }else if(cmd.startsWith("hs")) {
      spider->halfStandLeft();
    }
  }

  spider->update(1);
  //delay(10);
}

void select(String cmd) {
  String leg = cmd;
  leg.replace("l","");
  int legNumber = leg.toInt();
  spider->selectLeg(legNumber);
}

void set(String cmd) {
  String servo = cmd;
  int angle;
  if (servo.startsWith("t")) {
    servo.replace("t","");
    angle = servo.toInt();
    spider->_selectedLeg->setTip(angle);
  }
  
  if (servo.startsWith("m")) {
    servo.replace("m","");
    angle = servo.toInt();
    spider->_selectedLeg->setMid(angle);
  }
  
  if (servo.startsWith("r")) {
    servo.replace("r","");
    angle = servo.toInt();
    spider->_selectedLeg->setRotate(angle);
  }
}

void wave(String cmd) {
  spider->wave();
}

