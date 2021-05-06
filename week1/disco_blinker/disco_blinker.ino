unsigned long previousMillis = 0;        // will store last time LED was updated
long OnTime = 250;           // milliseconds of on-time
int discoDirection = 0;             // ledState used to set the LED
int myPins[] = {HIGH, LOW, LOW, LOW, LOW, LOW, LOW};  // ledState used to set the LED

class Flashers
{
    // Class Member Variables
    // These are initialized at startup
    long OnTime;     // milliseconds of on-time
    int pinIdx = 0;
    int toRight = true;
    // These maintain the current state
    unsigned long previousMillis;   // will store last time LED was updated

    // Constructor - creates a Flasher
    // and initializes the member variables and state
  public:
    Flashers(long on)
    {
      OnTime = on;
      previousMillis = 0;
    }

    void changeTime(int on)
    {
      if ( on <= 10 ) {
        OnTime = 10;
      } else {

        OnTime = on;
      }
    }
    void setToRight(int isRight) {
      toRight = isRight;
    }
    void updateLight()
    {
      // check to see if it's time to change the state of the LED
      unsigned long currentMillis = millis();

      if ((currentMillis - previousMillis >= OnTime) && toRight)
      {
        previousMillis = currentMillis;  // Remember the time
        lightUp(pinIdx + 1); // Update the actual LED
        goRight();
      } else if ((currentMillis - previousMillis >= OnTime) && !toRight)
      {
        previousMillis = currentMillis;  // Remember the time
        lightUp(pinIdx + 1); // Update the actual LED
        goLeft();
      }
    }

    void goLeft() {
      if ( pinIdx == 0 ) {
        pinIdx = 7;
      } else {
        pinIdx--;
      }
    }
    void goRight() {
      if ( pinIdx == 7 ) {
        pinIdx = 0;
      } else {
        pinIdx++;
      }
    }
    void lightUp(int idx) {
      for (byte i = 1; i < 9; i = i + 1) {
        digitalWrite(i, LOW);  // Update the actual LED
      }
      digitalWrite(idx, HIGH);  // Update the actual LED
    }
};

Flashers led(OnTime);

void setup() {
  // put your setup code here, to run once:
  // make a port that detect the coin
  // initialize serial communication at 9600 bits per second:
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  discoDirection = analogRead(A0);
  Serial.println(discoDirection);
  if (discoDirection <= 512) {
    led.setToRight(true);
    led.changeTime(discoDirection);
    led.updateLight();
  } else {
    led.setToRight(false);
    led.changeTime(1024 - discoDirection);
    led.updateLight();
  }
}
