

#include <Keyboard.h>


int stretchThreshold = 990;
int forceThreshold = 1000;

void setup() {
  // put your setup code here, to run once:
  Keyboard.begin();
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int stretchValue = analogRead(A1);
  int forceValue = analogRead(A2);

  Serial.print("stretch: ");
  Serial.print(stretchValue);
  Serial.print(" force: ");
  Serial.println(forceValue);

  if(stretchValue < stretchThreshold){
    digitalWrite(LED_BUILTIN, HIGH);
    Keyboard.press(KEY_DOWN_ARROW);  
    delay(200);
    digitalWrite(LED_BUILTIN, LOW);
  }

  if(forceValue < forceThreshold){
    digitalWrite(LED_BUILTIN, HIGH);
    Keyboard.press(' ');
    delay(200);  
    digitalWrite(LED_BUILTIN, LOW);
  }

  Keyboard.releaseAll();
}
