// Track state of power filter and led button, turn it off with button, automaticallyturn it on after 5 minutes

int LEDPIN=13;
int BUTTONPIN=2;

unsigned long FIVEMINUTES=300000; // millis
unsigned long INTERVAL=FIVEMINUTES;

unsigned long currentTime=0;
unsigned long startTime=0;

void setup() {                
  pinMode(LEDPIN, OUTPUT);  
  pinMode(BUTTONPIN, INPUT);  
  motorOn();  
}

void loop() {
  currentTime=millis();
  if(isButtonPushed()) {
    setTimer();
    motorOff();
  }
  if(isTimerExpired()) {
    resetTimer();
    motorOn();
  }
  if(isQuarterTime() || isHalfTime() || isThreeQuartersTime()) {
    blinkLed();
  }
}

void resetTimer() {
  startTime=0;
}
boolean isButtonPushed() {
  return (HIGH==digitalRead(BUTTONPIN));
}
boolean isTimerExpired() {
  return (isTimerOn() && currentTime-startTime>INTERVAL);
}
boolean isHalfTime() {
  return checkTime(1,2);
}
boolean checkTime(unsigned int nominator, unsigned int divisor) {
  if(isTimerOn()) {
    unsigned int lowerLimit=INTERVAL*nominator/divisor;
    unsigned int upperLimit=lowerLimit+100;
    unsigned int elapsedTime=currentTime-startTime;
    return (lowerLimit<elapsedTime && elapsedTime<upperLimit);
  } else {
    return false;
  }
}
boolean isQuarterTime() {
  return checkTime(1,4);
}
boolean isThreeQuartersTime() {
  return checkTime(3,4);
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
void setTimer() {
  startTime=millis();
}
void timerOff() {
  startTime=0;
}
boolean isTimerOn() {
  return (0<startTime);
}