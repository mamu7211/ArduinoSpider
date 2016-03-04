#include "Spider.h"

Spider *spider;

void setup() {
  Serial.begin(9600);
  spider = Spider::create();
  spider->setState(Init);
}

void loop() {
  spider->update(1);
  commands();
  delay(10);
}

void commands() {
  if (Serial.available() && spider->isMotionFinished()) {
    String cmd = Serial.readStringUntil(':');
    cmd.toLowerCase();
    cmd.trim();
    Serial.println("CMD = " + cmd);
    if (cmd.startsWith("dly")) {
    }else if (cmd.startsWith("state")) {
      setState(cmd);
    } else if (cmd.equals("dia")) {
      spider->diagnostics();
    } else if (cmd.startsWith("height")) {
      setHeight(cmd);
    } else if (cmd.startsWith("rotate")) {
      setRotation(cmd);
    } else if (cmd.startsWith("set")) {
      set(cmd);
    }
  }

  spider->update(0);
}

void setState(String cmd) {
  cmd.replace("state", "");
  cmd.trim();
  if (cmd.equals("init")) {
    spider->setState(Init);
  }
  if (cmd.equals("idle")) {
    spider->setState(Idle);
  }
  if (cmd.equals("bootallup")) {
    spider->setState(BootAllUp);
  }
  if (cmd.equals("preparetostandup")) {
    spider->setState(PrepareToStandUp);
  }
  if (cmd.equals("standlow")) {
    spider->setState(StandLow);
  }
  if (cmd.equals("standhigh")) {
    spider->setState(StandHigh);
  }
}

void setHeight(String cmd) {
  int i = 0;
  String servo = cmd;
  servo.replace("height", "");
  int height = servo.toInt();
  spider->setHeight(height);
}

void setRotation(String cmd) {
  int i = 0;
  cmd.replace("rotate", "");
  int angle = cmd.toInt();
  spider->setRotation(angle);
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

