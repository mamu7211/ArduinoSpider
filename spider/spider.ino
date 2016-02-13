
#include "Spider.h"

Spider *spider;

void setup() {
  Serial.begin(9600);
  spider = Spider::create();
  spider->ease();
  delay(1000);
  spider->prepare();
  delay(1000);
  spider->stand();
}

void loop() {

  if (Serial.available()) {
    String cmd = Serial.readString();
    cmd.trim();
    cmd.toLowerCase();
    Serial.println("CMD = " + cmd);
    
    if (cmd.equals("cal")) {
      spider->calibrate();
    }

    if (cmd.equals("eas")) {
      spider->ease();
    }

    if (cmd.equals("pre")) {
      spider->prepare();
    }

    if (cmd.equals("std")) {
      spider->stand();
    }

    if (cmd.equals("fwd")) {
      spider->forward();
      delay(100);
      spider->forward();
      delay(100);
      spider->forward();
      delay(100);
      spider->forward();
      delay(100);
      spider->forward();
      delay(100);
    }
  }
  delay(10);
}
