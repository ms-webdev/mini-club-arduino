/*

#include <Arduino.h>
#include <Timer.h>


const int buttonPin = 14; // A0
const int ledPin = 6;

// LED-Button
bool ledState = false;
int currentBtnState = LOW;
int lastBtnState    = LOW;
// Button debounce
int freezed = 0;
int debounce = 1;

// Laufzeit-Steuerung (Wie lange soll der Zug fahren)
int intervalTime = 5; // Sekunden
int resetTime = 0;
int currentTime = 0;

void setup() {  
  Serial.begin(9600);
  Serial.println("Start");
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // aktuelle Taster-Stellung
  currentBtnState = getBtnState();

  // Serial.println(currentBtnState); // ca. 200 - 1023  

  if(currentBtnState == HIGH && lastBtnState == LOW && (secis() - freezed > debounce)) {      
    ledState = !ledState; // Umkehr
    freezed = secis();
    // reset timer
    resetTime = secis();
  }

  // Hole aktuellen Taster-Status
  lastBtnState = currentBtnState;


  // Timer?
  currentTime = secis();
  if(isTimeReached()) ledState = false;

  // STROM?
  if (ledState) startTrain(); else stopTrain();
}


void startTrain() {
  digitalWrite(ledPin, HIGH);
}
void stopTrain() {
  digitalWrite(ledPin, LOW);
}

int getBtnState() {  
  if(analogRead(buttonPin) > 1000) return HIGH;  // max. 1023
  return LOW; 
}

bool isTimeReached() {
  return ((currentTime - resetTime) > intervalTime);
}

int secis() {
  return millis()/1000;
}



*/


/*
TIMER

const int ledBuiltin = 2; //13;

int ledState = HIGH;
Timer timer = Timer(5000);

int loopCount = 0;


void setup() {
  Serial.begin(9600);
  pinMode(ledBuiltin, OUTPUT);
  timer.start();
}

void loop() {
  // check timer
  if(timer.isReached()) {
    if(ledState == HIGH) ledState = LOW; else ledState = HIGH;
    timer.reset();
    Serial.println(loopCount++);
  }

  digitalWrite(ledBuiltin, ledState);
}

*/






/*
LED-Button

const int buttonPin = A8;
const int ledPin = 6;

// LED-Button
bool ledState = false;
int currentBtnState = LOW;
int lastBtnState    = LOW;
// Button debounce
int freezed = 0;
int debounce = 1;

// Laufzeit-Steuerung (Wie lange soll der Zug fahren)
int intervalTime = 5; // Sekunden
int resetTime = 0;
int currentTime = 0;

void setup() {  
  Serial.begin(9600);
  Serial.println("Start");
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // aktuelle Taster-Stellung
  currentBtnState = getBtnState();

  // Serial.println(currentBtnState); // ca. 200 - 1023  

  if(currentBtnState == HIGH && lastBtnState == LOW && (secis() - freezed > debounce)) {      
    ledState = !ledState; // Umkehr
    freezed = secis();
    // reset timer
    resetTime = secis();
  }

  // Hole aktuellen Taster-Status
  lastBtnState = currentBtnState;


  // Timer?
  currentTime = secis();
  if(isTimeReached()) ledState = false;

  // STROM?
  if (ledState) startTrain(); else stopTrain();
}


void startTrain() {
  digitalWrite(ledPin, HIGH);
}
void stopTrain() {
  digitalWrite(ledPin, LOW);
}

int getBtnState() {  
  if(analogRead(buttonPin) > 1000) return HIGH;  // max. 1023
  return LOW; 
}

bool isTimeReached() {
  return ((currentTime - resetTime) > intervalTime);
}

int secis() {
  return millis()/1000;
}


*/



/*
IBT2 - Motor

// IBT2 - Motor
const int PIN_motorRight = 9; // ~
const int PIN_motorLeft = 10; // ~

const int VMAX = 128; // max. 255

void setup() {
  // IBT2 - PINS
  pinMode(PIN_motorRight, OUTPUT);
  pinMode(PIN_motorLeft, OUTPUT);
  // IBT2 - INIT
  digitalWrite(PIN_motorRight, LOW);
  digitalWrite(PIN_motorLeft, LOW);
}

void loop() {
  // Right
  digitalWrite(PIN_motorLeft, LOW);
  analogWrite(PIN_motorRight, VMAX);
  delay(2000);
  // Pause
  digitalWrite(PIN_motorLeft, LOW);
  digitalWrite(PIN_motorRight, LOW);
  delay(2000);
  // Left
  digitalWrite(PIN_motorRight, LOW);
  analogWrite(PIN_motorLeft, VMAX);
  delay(2000);
  // Pause
  digitalWrite(PIN_motorLeft, LOW);
  digitalWrite(PIN_motorRight, LOW);
  delay(2000);
}






*/



