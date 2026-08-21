#include <TimerOne.h>

// Phase Output Pins
const int phaseA = 2, phaseA_inv = 5;
const int phaseB = 3, phaseB_inv = 6;
const int phaseC = 4, phaseC_inv = 7;

const int battPin = A0;
const float battDividerRatio = 11.0; 
const float lowCutOff = 10.5;

// Variables
volatile bool inverterActive = true; 
volatile int step = 0;

// 6-Step Symmetrical Sequence
const bool sequence[6][3] = {
  {1,0,0}, {1,1,0}, {0,1,0}, {0,1,1}, {0,0,1}, {1,0,1}
};

void setup() {
  pinMode(phaseA, OUTPUT); pinMode(phaseA_inv, OUTPUT);
  pinMode(phaseB, OUTPUT); pinMode(phaseB_inv, OUTPUT);
  pinMode(phaseC, OUTPUT); pinMode(phaseC_inv, OUTPUT);

  delay(1000); 

  // Initialize Timer1 for 50Hz (3333 microseconds per step)
  Timer1.initialize(3333); 
  Timer1.attachInterrupt(driveInverter);
}

void loop() {
  float voltage = (analogRead(battPin) * 5.0 / 1023.0) * battDividerRatio;

  if (voltage < lowCutOff) {
    inverterActive = false;
  } else {
    inverterActive = true; 
  }
}

void driveInverter() {
  if (!inverterActive) {
    digitalWrite(phaseA, LOW); digitalWrite(phaseA_inv, LOW);
    digitalWrite(phaseB, LOW); digitalWrite(phaseB_inv, LOW);
    digitalWrite(phaseC, LOW); digitalWrite(phaseC_inv, LOW);
    return;
  }

  digitalWrite(phaseA, sequence[step][0]);
  digitalWrite(phaseA_inv, !sequence[step][0]);
  
  digitalWrite(phaseB, sequence[step][1]);
  digitalWrite(phaseB_inv, !sequence[step][1]);
  
  digitalWrite(phaseC, sequence[step][2]);
  digitalWrite(phaseC_inv, !sequence[step][2]);

  step = (step + 1) % 6;
}
