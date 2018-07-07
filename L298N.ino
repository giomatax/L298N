#include <Stepper.h>

const int stepsPerRevolution = 500;  // სიჩქარე თითო საფეხურისთვის


// initialize the stepper library on pins 8 through 11:
Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);

int stepCount = 0;         // რაოდენობა რამდენი ნაბიჯი გააკეთა ძრავმა
int dirStep = 1; //თავიდან მიმართულება
void setup() {
  // initialize the serial port:
  Serial.begin(9600);
}

void loop() {
 
  myStepper.step(dirStep);
  Serial.print("ნაბიჯი:");
  Serial.println(stepCount);
  stepCount++;

  if( stepCount > 500){
      stepCount = 0;
      if( dirStep == 1) dirStep = -1;
      else dirStep = 1;
   
  }
    Serial.print(dirStep);

  delayMicroseconds(50);
}
