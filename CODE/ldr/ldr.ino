#include<Servo.h>
Servo s;
void setup() 
{
 pinMode(A0,INPUT);
  pinMode(A2,INPUT);
Serial.begin(9600); 
/*pinMode(8,OUTPUT);
pinMode(9,OUTPUT);
*/
s.attach(8);

}
void loop() {
Serial.print("LDR1 = ");
int i=analogRead(A0);
Serial.println(i);
Serial.print("LDR2 = ");
int j=analogRead(A2);
Serial.println(j);
delay(500);
/*if(i>j) {
digitalWrite(8,1); 
digitalWrite(9,0);
delay(500); 
}else {
digitalWrite(9,1); 
digitalWrite(8,0); 
delay(500);
}


/*s.write(18  0);
delay(1000);
}else{
s.write(0);
delay(1000);
}
*/

/*for(int i=0;i<=90;i++){
  s.write(i);
  delay(15);
}
for(int i=90;i>=0;i--){
  s.write(i);
  delay(15);
}*/
}
