const int LEDPIN=13;
const int BUTTONPIN=2;

const unsigned long FIVEMINUTES=300000; // millis
const unsigned long TIMERINTERVAL=FIVEMINUTES;
const unsigned long FLASHINTERVAL=5000;
const unsigned long FLASHLENGTH=300;

unsigned long currentTime=0;
unsigned long startTime=0;

enum timer {on,off}; 
timer t;

void setup() {                
  pinMode(LEDPIN, OUTPUT);  
  pinMode(BUTTONPIN, INPUT);  
  motorOn();  
  clearTimer();
}

void loop() {
  currentTime=millis();
  if(isButtonPushed()) {
    startTimer();
    motorOff();
  }
  else if(isTimerOn()) {
    if(isTimerExpired()) {
      clearTimer();
      motorOn();
    } else {
      doLed();
    }
  }
}

void doLed() {
  unsigned long divisor=elapsed() % FLASHINTERVAL;
  if(0<divisor && divisor<FLASHLENGTH) {
    ledOn();
  } else {
    ledOff();
  }
}
unsigned long elapsed() {
  return (currentTime-startTime);
}
void startTimer() {
  t=on;
  startTime=millis();
}
void clearTimer() {
  t=off;
}
boolean isButtonPushed() {
  return (HIGH==digitalRead(BUTTONPIN));
}
boolean isTimerExpired() {
  return (elapsed()>TIMERINTERVAL);
}
void ledOn() {
  digitalWrite(LEDPIN, HIGH);
}
void ledOff() {
  digitalWrite(LEDPIN, LOW);
}
void motorOn() {
  ledOn();
  // turn relay on
}
void motorOff() {
  ledOff();
  // turn relay off
}
boolean isTimerOn() {
  return (on==t);
}
