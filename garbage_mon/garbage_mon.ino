/*AUTHOR :- SHWETA AND KARTIK
  DATE :- 20/11/2019
  CODE :- GARBAGE MONITORING SYSTEM
*/


int trigpin=9;
int echopin=10;
int led=7;
int buzzer=4;


void setup() {
 Serial.begin(9600);
 pinMode(led,OUTPUT);
 pinMode(buzzer,OUTPUT);
 pinMode(trigpin,OUTPUT);
 pinMode(echopin,INPUT);
 

}

void loop() {
 long duration,distance;
 digitalWrite(trigpin,HIGH);
 delayMicroseconds(100);
 digitalWrite(trigpin,LOW);
 duration=pulseIn(echopin,HIGH);
 distance=(duration/2)/29.1;
 Serial.print(distance);
 Serial.print("CM\n");
 if((distance<15 && distance>7))
 {
  digitalWrite(led,LOW);
  Serial.print("led is off\n");
  analogWrite(buzzer,LOW);
  Serial.print("buzzer is off\n");
 }
 else if(distance<5)
 {
  digitalWrite(led,HIGH);
  Serial.print("led is on\n");
  analogWrite(buzzer,HIGH);
  Serial.print("Buzzer is on");
 }
 }
 
