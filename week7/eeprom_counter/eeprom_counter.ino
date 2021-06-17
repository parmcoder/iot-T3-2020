/***
    eeprom_put example.

    This shows how to use the EEPROM.put() method.
    Also, this sketch will pre-set the EEPROM data for the
    example sketch eeprom_get.

    Note, unlike the single byte version EEPROM.write(),
    the put method will use update semantics. As in a byte
    will only be written to the EEPROM if the data is actually
    different.

    Written by Christopher Andrews 2015
    Released under MIT licence.
***/

#include <EEPROM.h>
const int incPin =  7;      // the number of the LED pin
const int resetPin =  8;      // the number of the LED pin
int incLastState = HIGH;
int resetLastState = HIGH;
const int address = 0;

void setup() {

  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  setFloat(0.00f);
  pinMode(incPin, INPUT_PULLUP);
  pinMode(resetPin, INPUT_PULLUP);
  
  /** Put is designed for use with custom structures also. **/
}

void setFloat(float f) {
  int eeAddress = 0;   //Location we want the data to be put.

  //One simple call, with the address first and the object second.
  EEPROM.put(eeAddress, f);

  Serial.println("Written float data type!");

}

float getFloat(){
  float f = 0.00f;   //Variable to store data read from EEPROM.
  int eeAddress = 0; //EEPROM address to start reading from
  Serial.print("Read float from EEPROM: ");

  //Get the float data from the EEPROM at position 'eeAddress'
  EEPROM.get(eeAddress, f);
  Serial.println(f, 3);    //This may print 'ovf, nan' if the data inside the EEPROM is not a valid float.
  return f;
}

void increment(){
  float f = getFloat();
  setFloat(f+1.00f);
}

void reset(){
  setFloat(0.00f);
}

void loop() {
  /* Empty loop */
  const int incState = digitalRead(incPin);
  const int resetState = digitalRead(resetPin);

  if(incState == LOW && incLastState==HIGH){
    const int counter = getFloat();
    setFloat(counter + 1.00f);
  }
  if(resetState == LOW && resetLastState == HIGH){
    setFloat(0.00f);
  }

  incLastState = incState;
  resetLastState = resetState;
  delay(10);
  
  
}
