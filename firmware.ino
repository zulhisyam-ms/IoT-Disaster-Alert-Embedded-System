#include <Servo.h>

int Lpwm_pin = 5; //pin of controlling speed---- ENA of motor driver board
int Rpwm_pin = 6; //pin of controlling speed---- ENB of motor driver board
int pinLB=8;      //pin of controlling turning---- IN1 of motor driver board (left rear wheel)
int pinLF=7;      //pin of controlling turning---- IN2 of motor driver board (left front wheel)
int pinRB=2;      //pin of controlling turning---- IN3 of motor driver board(right rear wheel)
int pinRF=4;      //pin of controlling turning---- IN4 of motor driver board (right front wheel)
Servo myservo;
volatile int DL; //detect left obstacle
volatile int DM; //detect middle obstacle
volatile int DR; //detect right obstacle

float checkdistance() {
  digitalWrite(A1, LOW);
  digitalWrite(A1, HIGH);
  digitalWrite(A1, LOW);
  float distance = pulseIn(A0, HIGH) / 27.50;
  delay(100);
  return distance;
}

void Detect_obstacle_distance()
{
  myservo.write(150);
  for (int i = 0; i < 3; i = i + 1)
  {
    DL = checkdistance();
    delay(1000);
  }
  
  myservo.write(10);
  for (int i = 0; i<3; i = i + 1)
  {
    DR = checkdistance();
    delay(1000);
  }
}

void setup()
{
  Serial.begin(9600);
  myservo.attach(A2);
  pinMode(A1, OUTPUT);
  pinMode(A0, INPUT);
  pinMode(pinLB,OUTPUT); // /pin 2
  pinMode(pinLF,OUTPUT); // pin 4
  pinMode(pinRB,OUTPUT); // pin 7
  pinMode(pinRF,OUTPUT);  // pin 8
  pinMode(Lpwm_pin,OUTPUT);  // pin A5 (PWM) 
  pinMode(Rpwm_pin,OUTPUT);  // pin A4

  analogWrite(Lpwm_pin,110);
  analogWrite(Rpwm_pin,110);
  myservo.write(60);

  delay(2000);
}

void loop()
{
  
  myservo.write(47);

  //Set_Speed(100);
  delay(700);

  DM = checkdistance();
  Serial.println("--MIDDLE DISTANCE : --");
  Serial.println(DM);

  if (DM < 100) {

    stopp();
    // Set_Speed(0);

    Detect_obstacle_distance();
    Serial.println("Distance Left : ");
    Serial.println(DL);

    Serial.println("Distance Right : ");
    Serial.println(DR);

    // // if there is an object either left or right
    // if (DL < 50 || DR < 50) 
    // {
    delay(900);

    if (DL > DR) 
    {
        analogWrite(Lpwm_pin,132);

        turnL();
        delay(200);
        advance();
        //DL = 0;
        //DR = 0;
    
    } 
    else if (DR > DL)
    {
        analogWrite(Lpwm_pin,132);
        turnR();
        delay(200);
        advance();
       // DL = 0;
        //DR = 0;
    }

    // } 

  } 
  // if there is no obstacle left and right
  else 
  {
    advance();
  }

}


void Set_Speed(unsigned char pwm) //function of setting speed
{
  analogWrite(Lpwm_pin,pwm);
  analogWrite(Rpwm_pin,pwm);
}


void advance()    //  going forward
{
  digitalWrite(pinRF,LOW);
  digitalWrite(pinLF,LOW);
  digitalWrite(pinLB,HIGH); // making motor move towards left rear
  digitalWrite(pinRB,HIGH); // making motor move towards right rear
    
}


void turnL()        //turning right(dual wheel)
{
  delay(50);
  Serial.println("----MOVING LEFT----");
  digitalWrite(pinRF,LOW);  //making motor move towards right rear
  digitalWrite(pinLB,LOW);  //making motor move towards left front as of 17/1/2023 1.45pm left turning using this link https://projecthub.arduino.cc/aakash11/obstacle-avoiding-robot-8018ae

  digitalWrite(pinRB,HIGH);
  digitalWrite(pinLF,HIGH);
}

void turnR()         //turning left(dual wheel)
{
  delay(50);
  Serial.println("----MOVING RIGHT----");
  digitalWrite(pinRB,LOW);
  digitalWrite(pinLF,LOW);
  digitalWrite(pinRF,HIGH);   //making motor move towards right front
  digitalWrite(pinLB,HIGH);   //making motor move towards left rear
}

void stopp()        //stop
{
  delay(50);
  digitalWrite(pinRB,HIGH);
  digitalWrite(pinRF,HIGH);
  digitalWrite(pinLB,HIGH);
  digitalWrite(pinLF,HIGH);
    
}

void back()         //back up
{
  delay(50);
  digitalWrite(pinRF,HIGH);  //making motor move towards right rear     
  digitalWrite(pinLB,LOW);  //making motor move towards left rear
  digitalWrite(pinLF,HIGH);
  digitalWrite(pinRB,LOW);
      
}
