/*
  TwoMotorSpeed

  Monitor speed of two motors using quadrature encoders.

  Connect Channel A and Channel B of left motor to D2 and D3
  Connect Channel A and Channel B of right motor to D4 and D5

  modified 26 Jan 2022
  by LinZhangUCA
  
*/


// define variables
const byte leftEncA = 2;  // D2 reads left encoder's Ch.A
const byte leftEncB = 3;  // D3 reads left encoder's Ch.B
const byte rightEncA = 4;  // D4 reads right encoder's Ch.A
const byte rightEncB = 5;  // D5 reads right encoder's Ch.B
const byte leftVcc = 8;  // D8 serves as Vcc for left encoder
const byte rightVcc = 9;  // D9 serves as Vcc for right encoder
int motorDir = 0;  // looking from motor shaft, clockwise: 1, ccw: -1
int leftCounts = 0;
int rightCounts = 0;
int leftStateA = 0;
int leftStateB = 0;
int rightStateA = 0;
int rightStateB = 0;
int prevLeftStateA = 0;
int prevLeftStateB = 0;
int prevRightStateA = 0;
int prevRightStateB = 0;


void setup() {
  // setup pin modes
  pinMode(leftVcc, OUTPUT);
  pinMode(rightVcc, OUTPUT);
  digitalWrite(leftVcc, HIGH);
  digitalWrite(rightVcc, HIGH);
  //set baudrate
  Serial.begin(9600);
  // announce interrupt pins
  attachInterrupt(digitalPinToInterrupt(leftEncA), ISR_leftA, CHANGE);
  attachInterrupt(digitalPinToInterrupt(leftEncB), ISR_leftB, CHANGE);
  attachInterrupt(digitalPinToInterrupt(rightEncA), ISR_rightA, CHANGE);
  attachInterrupt(digitalPinToInterrupt(rightEncB), ISR_rightB, CHANGE);
  // init interrupt pins states
  leftStateA = digitalRead(leftEncA);
  leftStateB = digitalRead(leftEncB);
  rightStateA = digitalRead(leftEncA);
  rightStateB = digitalRead(leftEncB);
  prevLeftStateA = leftStateA;
  prevLeftStateB = leftStateB;
  prevRightStateA = rightStateA;
  prevRightStateB = rightStateB;
}

void ISR_leftA() {
  prevLeftStateA = leftStateA;
  leftStateA = !leftStateA;
  if (prevLeftStateA == 0) {
    if (prevLeftStateB == 0) {
      motorDir = -1; // prev states: {0,0}, present states: {1,0}
    }
    else {
      motorDir = 1;  // prev states: {0,1}, present states: {1,1}
    }
  }
  else {
    if (prevLeftStateB == 0) {
      motorDir = 1; // prev states: {1,0}, present states: {0,0}
    }
    else {
      motorDir = -1;  // prev states: {1,1}, present states: {0,1}
    }
  }
  leftCounts += motorDir;
  motorDir = 0;
}

void ISR_leftB() {
  prevLeftStateB = leftStateB;
  leftStateB = !leftStateB;
  if (prevLeftStateA == 0) {
    if (prevLeftStateB == 0) {
      motorDir = 1; // prev states: {0,0}, present states: {0,1}
    }
    else {
      motorDir = -1;  // prev states: {0,1}, present states: {0,0}
    }
  }
  else {
    if (prevLeftStateB == 0) {
      motorDir = -1; // prev states: {1,0}, present states: {1,1}
    }
    else {
      motorDir = 1;  // prev states: {1,1}, present states: {1,0}
    }
  }
  leftCounts += motorDir;
  motorDir = 0;
}

void ISR_rightA() {
  prevRightStateA = rightStateA;
  rightStateA = !rightStateA;
  if (prevRightStateA == 0) {
    if (prevRightStateB == 0) {
      motorDir = -1; // prev states: {0,0}, present states: {1,0}
    }
    else {
      motorDir = 1;  // prev states: {0,1}, present states: {1,1}
    }
  }
  else {
    if (prevRightStateB == 0) {
      motorDir = 1; // prev states: {1,0}, present states: {0,0}
    }
    else {
      motorDir = -1;  // prev states: {1,1}, present states: {0,1}
    }
  }
  rightCounts += motorDir;
  motorDir = 0;
}

void ISR_rightB() {
  prevRightStateB = rightStateB;
  rightStateB = !rightStateB;
  if (prevRightStateA == 0) {
    if (prevRightStateB == 0) {
      motorDir = 1; // prev states: {0,0}, present states: {0,1}
    }
    else {
      motorDir = -1;  // prev states: {0,1}, present states: {0,0}
    }
  }
  else {
    if (prevRightStateB == 0) {
      motorDir = -1; // prev states: {1,0}, present states: {1,1}
    }
    else {
      motorDir = 1;  // prev states: {1,1}, present states: {1,0}
    }
  }
  rightCounts += motorDir;
  motorDir = 0;
}


void loop() {
  // main loop
  Serial.print(leftCounts);
  Serial.print(",");
  Serial.println(rightCounts);
  leftCounts = 0;
  rightCounts = 0;
  delay(10);  // 100Hz
}
