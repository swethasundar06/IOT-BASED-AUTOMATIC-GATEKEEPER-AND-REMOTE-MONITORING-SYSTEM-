#define BLYNK_TEMPLATE_ID "TMPL3Av3EjalH" 
#define BLYNK_TEMPLATE_NAME "servo motor control" 
#define BLYNK_AUTH_TOKEN "b0hnhpZsYxrXcYvHID4RBV7olzxzqUz_" 
#include <Servo.h> 
#include <ESP8266WiFi.h>   
#include <BlynkSimpleEsp8266.h>   
#define IR_SENSOR_PIN D5   
#define SERVO_PIN D6       
char ssid[] = "Swetha Sundar"; 
char pass[] = "swetha66"; 
Servo myservo;   
BlynkTimer timer; 
int gaugePin = V2;   
int sliderPin = V0;   
void setup() { 
  Serial.begin(9600); 
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass); 
  myservo.attach(SERVO_PIN); 
  pinMode(IR_SENSOR_PIN, INPUT); 
  timer.setInterval(1000L, checkSensor);} 
void loop() { 
  Blynk.run();   
  timer.run(); } 
BLYNK_WRITE(V0) { 
  int sliderValue = param.asInt();   
  myservo.write(sliderValue);        
  Serial.print("Servo position: "); 
  Serial.println(sliderValue); 
  Blynk.virtualWrite(gaugePin, sliderValue); 
} 
void checkSensor() { 
  int sensorValue = digitalRead(IR_SENSOR_PIN); 
  Serial.print("IR Sensor Value: "); 
  Serial.println(sensorValue); 
  if (sensorValue == HIGH) { 
    Serial.println("Object detected"); 
  } else { 
    Serial.println("No object detected"); 
  } 
}
