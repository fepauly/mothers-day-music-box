#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"
#include "audio.h"
#include "state_machine.h"


SoftwareSerial mySoftwareSerial(/*rx=*/10, /*tx=*/11);
DFRobotDFPlayerMini myDFPlayer;
StateMachine sm;

void setup()
{
  mySoftwareSerial.begin(9600);
  Serial.begin(115200);

  if (!myDFPlayer.begin(mySoftwareSerial, true, false)) {
    Serial.println(F("Unable to begin:"));
    Serial.println(F("1.Please recheck the connection!"));
    Serial.println(F("2.Please insert the SD card!"));
    while (true);
  }

  Serial.println(F("myDFPlayer Mini online."));

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
}
