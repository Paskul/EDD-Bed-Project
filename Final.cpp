#include <Servo.h>
//#define REFRESH_INTERVAL    20000
//#define REFRESH_INTERVAL    67

#include <EEPROM.h>
Servo motor;

int motorMaxForward = 6;
int motorSlowForward = 89;
//int motorMaxReverse = 141;
int motorMaxReverse = 120;
int motorSlowReverse = 97;
int motorStop = 00;

int motorSpeed = 0;


void setup()
{
  Serial.begin(9600);

  motor.attach(11);
  //pinMode(11, OUTPUT);
  //digitalWrite(11, LOW);
  //set up the serial monitor
  
  pinMode(3, INPUT);
  //First LMS

  pinMode(9, INPUT);
  //Second LMS

  pinMode(5, INPUT);
  //On-Off

  //Serial.println(EEPROM.read(0));
  //pinMode(motorPinGreen, OUTPUT);
  //motor.attach(motorPinGreen);

  //Speed Controller Pins
}

int percentCalculator(int x) {
  //Serial.print(255*(0.01 * x));
  return (255*(0.01 * x));
}

void motorWritting(int y) {
  //analogWrite(11, percentCalculator(y));
  motor.write(y);
}

void loop()
{
  // motor.write(motorSlowForward);
  // motor.write(motorSpeed);
  if ((digitalRead(3) == LOW) && (digitalRead(5) == HIGH)) {
    Serial.print("ON + FORWARD");
    //motorWritting(90);
    // KEEP MESSING WITH SPEED, CHANGE -180 TO DIF VALUES
    motorWritting(-180);
  }
  if ((digitalRead(9) == LOW) && (digitalRead(5) == HIGH)) {
    Serial.print("ON + BACKWARD");
    motorWritting(180);
    //https://makecode.adafruit.com/reference/pins/servo-write
  }
  else {
    Serial.print("OFF");
    motorWritting(0);
    //motorWritting(0);
    //motor.write(90);
    //motor.writeMicroseconds(1500);
  }

    
  
  //Serial.println("Restarted");
  //bool button1 = digitalRead(lsw);
  //Serial.println(button1);
  //while(button1 == true){
    //button1 = digitalRead(lsw);
    //Serial.println(button1);
}
