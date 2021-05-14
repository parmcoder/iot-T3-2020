/**
   CLOCK
   Using Milli() to do async stuff
   1. Sound system
    - We can make it using passive buzzer
   2. Temperature and humidity
    - We can make it using the blue box
   3. Remote Control
    - Infrared one can work on it
   4. Time
    - Using timer

*/

#define DECODE_NEC          // Includes Apple and Onkyo
#define DHTPIN 5     // Digital pin connected to the DHT sensor
#define DHTTYPE DHT11   // DHT 11
#define MODE_DATE 1
#define MODE_TEMP 2
#define MODE_DAY 3
#define TONE_USE_INT
#define TONE_PITCH 440

#include <Arduino.h>

#include <IRremote.h>
#include <DS1302.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "DHT.h"
#include "PinDefinitionsAndMore.h"
#include <Pitch.h>


LiquidCrystal_I2C lcd(0x27, 16, 2);
DHT dht(DHTPIN, DHTTYPE);
// Init the DS1302
DS1302 rtc(2, 3, 4);



void setup()
{
  Serial.begin(9600);
  pinMode(8, OUTPUT);
  // Set the clock to run-mode, and disable the write protection
  rtc.halt(false);
  rtc.writeProtect(false);
  lcd.init();
//  lcd.backlight();
  // Setup Serial connection
  dht.begin();
  Serial.println(F("START " __FILE__ " from " __DATE__ "\r\nUsing library version " VERSION_IRREMOTE));
  // The following lines can be commented out to use the values already stored in the DS1302
  //  rtc.setDOW(FRIDAY);        // Set Day-of-Week to FRIDAY
  //  rtc.setTime(14, 57, 0);     // Set the time to 12:00:00 (24hr format)
  //  rtc.setDate(14, 5, 2021);   // Set the date to August 6th, 2010
  IrReceiver.begin(7, ENABLE_LED_FEEDBACK, USE_DEFAULT_FEEDBACK_LED_PIN);

  Serial.print(F("Ready to receive IR signals at pin "));
  Serial.println(7);
}

void hourIncrement() {
  Time t = rtc.getTime();
  if ( t.hour == 23 ) {
    rtc.setTime(0, t.min, t.sec);   // Set the time to the incremented time
  } else {
    rtc.setTime(t.hour  + 1, t.min, t.sec);   // Set the time to the incremented time
  }
}
void hourDecrement() {
  Time t = rtc.getTime();
  if ( t.hour == 0 ) {
    rtc.setTime(23, t.min, t.sec);   // Set the time to the incremented time
  } else {
    rtc.setTime(t.hour  - 1, t.min, t.sec);   // Set the time to the incremented time
  }
}
void minuteIncrement() {
  Time t = rtc.getTime();
  if ( t.min == 59 ) {
    rtc.setTime(t.hour, 0, t.sec);   // Set the time to the incremented time
    hourIncrement();

  } else {
    rtc.setTime(t.hour, t.min + 1, t.sec);   // Set the time to the incremented time
  }
}

void minuteDecrement() {
  Time t = rtc.getTime();
  if ( t.min == 0 ) {
    rtc.setTime(t.hour, 59, t.sec);   // Set the time to the incremented time
    hourDecrement();

  } else {
    rtc.setTime(t.hour, t.min - 1, t.sec);   // Set the time to the incremented time
  }
}

void displayTime() {
  lcd.setCursor(0, 0);

  lcd.print(rtc.getDateStr());
  lcd.setCursor(0, 1);
  lcd.print(rtc.getTimeStr());

  delay(100); //Change to milli
}

void displayTemperature() {
  // Wait a few seconds between measurements.
  delay(200);

  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();

  lcd.setCursor(0, 0); // Cursor Display
  lcd.print("H:");
  lcd.setCursor(2, 0);
  lcd.print(h);
  lcd.print(" %");

  lcd.setCursor(0, 1); // Cursor Display
  lcd.print("T:");
  lcd.print(t);
  lcd.print(" ");
  lcd.print((char)0xDF);
  lcd.print("C");
}

void displayDay() {
  lcd.setCursor(0, 0);
  lcd.print("Today is ");
  lcd.setCursor(0, 1);

  lcd.print(rtc.getDOWStr());
}


int state = MODE_DATE;
int gotCommand = false;

void playSound() {
  digitalWrite(8, HIGH);
  delay(10);
  digitalWrite(8, LOW);
}

void loop() {
  /*
     Check if received data is available and if yes, try to decode it.
     Decoded result is in the IrReceiver.decodedIRData structure.

     E.g. command is in IrReceiver.decodedIRData.command
     address is in command is in IrReceiver.decodedIRData.address
     and up to 32 bit raw data in IrReceiver.decodedIRData.decodedRawData
  */
  if (IrReceiver.decode()) {

    // Print a short summary of received data
    IrReceiver.printIRResultShort(&Serial);
    if (IrReceiver.decodedIRData.protocol == UNKNOWN) {
      // We have an unknown protocol here, print more info
      IrReceiver.printIRResultRawFormatted(&Serial, true);
    }
    Serial.println();

    /*
       !!!Important!!! Enable receiving of the next value,
       since receiving has stopped after the end of the current received data packet.
    */
    IrReceiver.resume(); // Enable receiving of the next value

    /*
       Finally, check the received data and perform actions according to the received command
    */
    if (IrReceiver.decodedIRData.command == 0xC) {
      state = MODE_DATE;
      lcd.clear();
      gotCommand = !gotCommand;
    } else if (IrReceiver.decodedIRData.command == 0x18) {
      state = MODE_TEMP;
      lcd.clear();
      gotCommand = !gotCommand;

    } else if (IrReceiver.decodedIRData.command == 0x5E) {
      state = MODE_DAY;
      lcd.clear();
      gotCommand = !gotCommand;

    } else if (IrReceiver.decodedIRData.command == 0x15) {
      minuteIncrement();
      gotCommand = !gotCommand;

    } else if (IrReceiver.decodedIRData.command == 0x7) {
      minuteDecrement();
      gotCommand = !gotCommand;

    } else if (IrReceiver.decodedIRData.command == 0x40) {
      hourIncrement();
      gotCommand = !gotCommand;

    } else if (IrReceiver.decodedIRData.command == 0x44) {
      hourDecrement();
      gotCommand = !gotCommand;

    }
  }

  if (gotCommand) {
    playSound();
    gotCommand = !gotCommand;
  }
  if (state == MODE_TEMP) {
    displayTemperature();
  } else if (state == MODE_DATE) {
    displayTime();
  } else if (state == MODE_DAY) {
    displayDay();
  }
}
