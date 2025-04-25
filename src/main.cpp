#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"
#include "audio.h"
#include "state_machine.h"

#define YES_BUTTON_PIN 2
#define NO_BUTTON_PIN 3

int buttonToggle = 0;
int previousButtonState = 0; 

SoftwareSerial mySoftwareSerial(/*rx=*/10, /*tx=*/11);
DFRobotDFPlayerMini myDFPlayer;
StateMachine sm;

void setup()
{
  pinMode(YES_BUTTON_PIN, INPUT);
  pinMode(NO_BUTTON_PIN, INPUT);

  mySoftwareSerial.begin(9600);
  Serial.begin(115200);

  if (!myDFPlayer.begin(mySoftwareSerial, true, false)) {
    Serial.println(F("Unable to begin:"));
    Serial.println(F("1.Please recheck the connection!"));
    Serial.println(F("2.Please insert the SD card!"));
    while (true);
  }

  Serial.println(F("DFmyDFPlayer Mini online."));

  sm.init(&myDFPlayer);
}

void loop()
{
  // Audio event
  if (myDFPlayer.available()) {
    uint8_t type = myDFPlayer.readType();
    if (type == DFPlayerPlayFinished) {
      sm.update(EVENT_AUDIO_FINISHED);
    }
  }

  // Button handling (edge detection)
  static int lastYes = 0;
  static int lastNo = 0;
  int yes = digitalRead(YES_BUTTON_PIN);
  int no = digitalRead(NO_BUTTON_PIN);
  if (yes && !lastYes) {
    sm.update(EVENT_BUTTON_YES);
  }
  if (no && !lastNo) {
    sm.update(EVENT_BUTTON_NO);
  }
  lastYes = yes;
  lastNo = no;
}
