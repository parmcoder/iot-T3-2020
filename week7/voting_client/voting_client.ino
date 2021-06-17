#include <WiFi.h>
#include <HTTPClient.h>
 

const char* ssid = "Parmmy";
const char* password = "hotspotkuy";
const char* url = "http://192.168.43.238:5000/";

const int b1Pin = 18;
const int b2Pin = 19;
int b1LastState = HIGH;
int b2LastState = HIGH;

void setup() {
  pinMode(b1Pin, INPUT_PULLUP);
  pinMode(b2Pin, INPUT_PULLUP);
  Serial.begin(115200);
  delay(4000);   //Delay needed before calling the WiFi.begin
 
  WiFi.begin(ssid, password); 
 
  while (WiFi.status() != WL_CONNECTED) { //Check for the connection
    delay(1000);
    Serial.println("Connecting to WiFi..");
  }
 
  Serial.println("Connected to the WiFi network");
 
}

void sendData(const char* msg) {
   if(WiFi.status()== WL_CONNECTED){   //Check WiFi connection status
 
   HTTPClient http;   
 
   http.begin(url);  //Specify destination for HTTP request
   http.addHeader("Content-Type", "application/json");             //Specify content-type header
 
   int httpResponseCode = http.POST(msg);   //Send the actual POST request
 
   if(httpResponseCode>0){
 
    String response = http.getString();                       //Get the response to the request
 
    Serial.println(httpResponseCode);   //Print return code
    Serial.println(response);           //Print request answer
 
   }else{
 
    Serial.print("Error on sending POST: ");
    Serial.println(httpResponseCode);
 
   }
 
   http.end();  //Free resources
 
 }else{
 
    Serial.println("Error in WiFi connection");   
 
 }
} 


void loop() {
  const int b1State = digitalRead(b1Pin);
  const int b2State = digitalRead(b2Pin);

  if(b1State == LOW && b1LastState == HIGH){
    sendData("{\"sender\": \"parm\",\"vote\": \"a\"}");
  }

  if(b2State == LOW && b2LastState == HIGH){
    sendData("{\"sender\": \"parm\",\"vote\": \"b\"}");
  }

  b1LastState = b1State;
  b2LastState = b2State;
  delay(10);  //Send a request every 10 seconds
 
}
