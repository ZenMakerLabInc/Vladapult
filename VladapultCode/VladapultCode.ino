/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep
*/

#include <Servo.h>
#define RANGE 50
#define MAX_TIME 3000
#define MOTOR_PIN 3

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position

void setup() {
  myservo.attach(13);  // attaches the servo on pin 9 to the servo object
  pinMode(6, OUTPUT);
}

void loop() {
  SweepIn();
  PullBack();
  delay(3000);
  SweepOut();
  delay(1000);
}

void PullBack(){
   digitalWrite(MOTOR_PIN, HIGH);
   delay(MAX_TIME);
   digitalWrite(MOTOR_PIN, LOW);
}

void LetGo(){
   digitalWrite(MOTOR_PIN, LOW);
   delay(MAX_TIME);
   digitalWrite(MOTOR_PIN, HIGH);
}

void SweepOut(){
    for (pos = 0; pos <= RANGE; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
}

void SweepIn(){
  for (pos = RANGE; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
}
