//#include<Ultrasonic.h>
//Ultrasonic ultrasonic(2,3);
const int trigpin=2;
const int echopin=3;
long duration;
int distance;
int LED1=8;
int LED2=9;
int LED3=10;
void setup() {
  pinMode(trigpin,OUTPUT);
  pinMode(echopin,INPUT);
  pinMode(LED1,OUTPUT);
   pinMode(LED2,OUTPUT);
    pinMode(LED3,OUTPUT);
Serial.begin(9600);
}


void loop() {
 // distance=Ultrasonic.Ranging(CM);
 digitalWrite(trigpin,LOW);
  delayMicroseconds(2);

   digitalWrite(trigpin,HIGH);
  delayMicroseconds(10);
   digitalWrite(trigpin,LOW);


   duration =pulseIn(echopin,HIGH);
   distance=duration*0.034/2;
   
  Serial.print("distance : ");
  Serial.print(distance);
  Serial.println(" cm");
    if(distance<=30 && distance>=26){
      digitalWrite(LED1,HIGH);
      digitalWrite(LED2,LOW);
      digitalWrite(LED3,LOW);
    }else if(distance<=25 && distance>=15){
      digitalWrite(LED2,HIGH);
      digitalWrite(LED1,LOW);
      digitalWrite(LED3,LOW);
    }else if(distance<=14 && distance>=5){
      digitalWrite(LED3,HIGH);
      digitalWrite(LED2,LOW);
      digitalWrite(LED1,LOW);
    }else{
      digitalWrite(LED1,LOW);
      digitalWrite(LED2,LOW);
      digitalWrite(LED3,LOW);
    }
}
