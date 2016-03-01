#include "Spider.h"

Spider *spider;

void setup() {
  Serial.begin(9600);
  spider = Spider::create();
}

void loop() {
  spider->update(1);
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
    } else if (cmd.startsWith("height")) {
      setHeight(cmd);
    } else if (cmd.startsWith("set")) {
      set(cmd);
    }
  }

  spider->update(1);
}

void setHeight(String cmd) {
  int i = 0;
  String servo = cmd;
  servo.replace("height", "");
  int height = servo.toInt();
  spider->setHeight(height);
}

void set(String cmd) {
  int angle;
  if (cmd.startsWith("set-leg ")) {
    cmd.replace("set-leg", "");
    cmd.trim();
    int legNumber = cmd.toInt();
    spider->selectLeg(legNumber);
  } else if (cmd.startsWith("set-tip")) {
    cmd.replace("set-tip", "");
    cmd.trim();
    angle = cmd.toInt();
    spider->_selectedLeg->setTip(angle);
  } else  if (cmd.startsWith("set-mid")) {
    cmd.replace("set-mid", "");
    cmd.trim();
    angle = cmd.toInt();
    spider->_selectedLeg->setMid(angle);
  } else  if (cmd.startsWith("set-rot")) {
    cmd.replace("set-rot", "");
    cmd.trim();
    angle = cmd.toInt();
    spider->_selectedLeg->setRotate(angle);
  }
}

