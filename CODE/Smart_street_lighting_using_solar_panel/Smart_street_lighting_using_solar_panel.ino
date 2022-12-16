#include <Servo.h> //includes the servo library
Servo myservo;//creating object


#define ldr1 A1 // set ldr 1 Analog input pin of East ldr as an integer
#define ldr2 A0 // set ldr 2 Analog input pin of West ldr as an integer
const int trigpin=2;//defining pin number
const int echopin=3;//defining pin number
long duration;//declaration
int distance;//declaration
int LED1=5;//defining pin number
int LED2=6;//defining pin number
int LED3=11;//defining pin number
int threshold=40;//set a limit
int tolerance=15;//difference between 2 LDRs
int pos=90; // initial position of the Horizontal movement controlling servo motor


void setup(){
myservo.attach(4); // attaches the servo on digital pin 2 to the horizontal movement servo motor 
pinMode(ldr1, INPUT); //set East ldr pin as an input
pinMode(ldr2, INPUT); //set West ldr pin as an input
  pinMode(trigpin,OUTPUT);//set trig pin as an output
  pinMode(echopin,INPUT); //set trig pin as an input
myservo.write(pos); // write the starting position of the horizontal movement servo motor 

      
   pinMode(LED1,OUTPUT);//set led as an output
   pinMode(LED2,OUTPUT);//set led as an output
   pinMode(LED3,OUTPUT);//set led as an output
  delay(1000); // 1 second delay to allow the solar panel to move to its staring position before comencing solar tracking
Serial.begin(9600);
}


void loop(){      
int val1 = analogRead(ldr1); // read the value of ldr 1
Serial.print("ldr1=");//print ldr1
Serial.println(val1);//print ldr1 value
int val2 = analogRead(ldr2); // read the value of ldr 2
Serial.print("ldr2=");//print ldr2
Serial.println(val2);//print ldr2 value
int diff1= abs(val1 - val2);   
  int diff2= abs(val2 - val1);
  Serial.print("diff1=");
  Serial.println(diff1);
delay(500);
if(val1>threshold && val2>threshold) {//no servo motor horizontal movement will take place if the ldr value is within given range
   
   
   //servo motor code
     analogWrite(LED1,LOW);//switch off the led
     analogWrite(LED2,LOW);//switch off the led
     analogWrite(LED3,LOW);//switch off the led



if((diff1 <= tolerance) || (diff2 <= tolerance)) {
    //does nothing
  } else {
    
 if(val1 > val2) // if ldr1 senses more light than ldr2 
  {
    pos = pos+2; // decrement the 90 degree poistion of the horizontal servo motor - this will move the panel position Eastward
   }
   if(val1 < val2) // if ldr2 senses more light than ldr1
   {
  pos = pos-2; // increment the 90 degree position of the horizontal motor - this will move the panel position Westward
    }
  }
     
if(pos > 180) {pos = 180;} // reset the horizontal postion of the motor to 180 if it tries to move past this point
if(pos < 0) {pos = 0;} // reset the horizontal position of the motor to 0 if it tries to move past this point
myservo.write(pos); // write the starting position to the horizontal motor
delay(50);

} else {

    analogWrite(LED1,20);//switch on the led
    analogWrite(LED2,20);//switch off the led
    analogWrite(LED3,20);//switch off the led


//ULTRASONIC CODE
  digitalWrite(trigpin,LOW);//switch off the trigger pin
  delayMicroseconds(2);//delay

  digitalWrite(trigpin,HIGH);//switch on the trigger pin
  delayMicroseconds(10);//delay
  digitalWrite(trigpin,LOW);//switch off the trigger pin


  duration =pulseIn(echopin,HIGH);//calculating the duration 
  distance=duration*0.034/2;//calculating the distance
   
  Serial.print("distance : ");//print the distance
  Serial.print(distance);//print the distance value 
  Serial.println(" cm");//print cm
      if(distance<=36 && distance>=26){
      digitalWrite(LED1,255);//switch on the led1 to maximum intensity


      }else if(distance<=25 && distance>=15){
      digitalWrite(LED2,255);//switch on the led2 to maximum intensity


      }else if(distance<=14 && distance>=4){
      digitalWrite(LED3,255);//switch on the led3 to maximum intensity
    }

  }
}
