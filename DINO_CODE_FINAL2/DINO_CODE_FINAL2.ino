#include <Servo.h> 
#define unpress_angle 60
#define press_angle 39


int stretchThreshold =360;
int forceThreshold = 850;
Servo servo1;
Servo servo2;
bool trig=true;

void setup() {
  // put your setup code here, to run once:
  servo1.attach(10);
  servo2.attach(11);
  servo1.write(unpress_angle);
  servo2.write(unpress_angle);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int stretchValue = analogRead(A1);
  int forceValue = analogRead(A2);
  servo1.write(unpress_angle);
  servo2.write(unpress_angle);

  Serial.print("stretch: ");
  Serial.print(stretchValue);
  Serial.print(" force: ");
  Serial.println(forceValue);

  if(stretchValue < stretchThreshold){
    digitalWrite(LED_BUILTIN, HIGH);
    servo1.write(press_angle);  
    delay(200);
    digitalWrite(LED_BUILTIN, LOW);
  }

  if(forceValue < forceThreshold){
    digitalWrite(LED_BUILTIN, HIGH);
    servo2.write(press_angle);
    delay(200);  
    digitalWrite(LED_BUILTIN, LOW);
  }

}                          
