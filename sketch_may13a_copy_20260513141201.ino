#include <Servo.h>

Servo myServo; 
const int trigPin = 2;
const int echoPin = 3;

void setup() {
  myServo.attach(9); 
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 
  myServo.write(0); // শুরুতে ঢাকনা বন্ধ
  Serial.begin(9600); 
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  long duration = pulseIn(echoPin, HIGH);
  int distance = duration * 0.034 / 2;
  
  Serial.print("Distance: ");
  Serial.println(distance); 
  
  // দূরত্ব ৫ সেমি বা তার কম হলে ঢাকনা খুলবে
  if (distance > 0 && distance <= 5) { 
    myServo.write(90);  // ঢাকনা খুলবে
    delay(1000);         // 1 সেকেন্ড খোলা থাকবে
  } else {
    myServo.write(0);   // ৫ সেমি থেকে হাত দূরে গেলেই বন্ধ
    delay(30);          
  }
}
