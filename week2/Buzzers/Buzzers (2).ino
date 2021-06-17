const int INPUT_PIN = 8;
const int RED_PIN = 2;
const int GREEN_PIN = 3;
const int BLUE_PIN = 4;
const int BUZZER_PIN=11;
int last_state = HIGH;
int led_state = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(INPUT_PIN, INPUT_PULLUP);
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  Serial.begin(9600);
}

void led(int r, int g, int b){
  digitalWrite(RED_PIN, r);
  digitalWrite(GREEN_PIN, g);
  digitalWrite(BLUE_PIN, b);
}

void led_color(int led_state){
  if(led_state==0){
    led(HIGH, LOW, LOW);
  }
  else if(led_state==1){
    led(LOW, HIGH, LOW);
  }
  else if(led_state==2){
    led(LOW, LOW, HIGH);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  int data = digitalRead(INPUT_PIN);

  if(last_state==HIGH && data==LOW){ //falling edge
    //Serial.println(led_state);
    delay(50);
    data = digitalRead(INPUT_PIN);
    if(data == LOW){ // fall edge and stays low
      led_state = (led_state+1)%3;
      led_color(led_state);
      digitalWrite(BUZZER_PIN, HIGH);
      delay(100);
      digitalWrite(BUZZER_PIN, LOW);
    }
  } 
  last_state = data;
}
