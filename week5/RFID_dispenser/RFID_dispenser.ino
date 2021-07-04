#include "SPI.h"
#include "MFRC522.h"
#include <Servo.h>

// twelve servo objects can be created on most boards

#define SS_PIN 10
#define RST_PIN 9
#define SP_PIN 8

MFRC522 rfid(SS_PIN, RST_PIN);
Servo myservo;  // create servo object to control a servo

MFRC522::MIFARE_Key key;

void setup() {
  myservo.attach(2);  // attaches the servo on pin 9 to the servo object
  myservo.write(0);              // tell servo to go to position in variable 'pos'
  Serial.begin(115200);
  SPI.begin();
  rfid.PCD_Init();
}

int isOpen = false;
unsigned long currentTime;
unsigned long lastTime;
unsigned long resetTime;

void loop() {
  currentTime = millis();
  if (currentTime > resetTime) {
    myservo.write(1);
    isOpen = false;

  }
  if (!rfid.PICC_IsNewCardPresent() || !rfid.PICC_ReadCardSerial())
    return;

  // Serial.print(F("PICC type: "));
  MFRC522::PICC_Type piccType = rfid.PICC_GetType(rfid.uid.sak);
  // Serial.println(rfid.PICC_GetTypeName(piccType));

  // Check is the PICC of Classic MIFARE type
  if (piccType != MFRC522::PICC_TYPE_MIFARE_MINI &&
      piccType != MFRC522::PICC_TYPE_MIFARE_1K &&
      piccType != MFRC522::PICC_TYPE_MIFARE_4K) {
    Serial.println(F("Your tag is not of type MIFARE Classic."));
    return;
  }

  String strID = "";
  for (byte i = 0; i < 4; i++) {
    strID +=
      (rfid.uid.uidByte[i] < 0x10 ? "0" : "") +
      String(rfid.uid.uidByte[i], HEX) +
      (i != 3 ? ":" : "");
  }
  strID.toUpperCase();
  Serial.print("Tap card key: ");
  Serial.println(strID);

  if (strID == "50:AE:73:30" && !isOpen) {                         // waits for the servo to get there
    Serial.print("Correct, get your gift! Owner of ");
    Serial.println(strID);

    myservo.write(30);              // tell servo to go to position in variable 'pos'
    isOpen = true;
    //    delay(80);                           // waits for the servo to get there
    resetTime = millis() + 75;
  }

  rfid.PICC_HaltA();
  rfid.PCD_StopCrypto1();
}
