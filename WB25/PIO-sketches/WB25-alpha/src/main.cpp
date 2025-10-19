#include <Arduino.h>
#include <Timer.h>

// IBT2 - Motor
const int PIN_motorRight = 9; // ~
const int PIN_motorLeft = 10; // ~

const int VMAX = 105; // max. 255

// Relay - Doppel
const int PIN_relay1 = 7;
const int PIN_relay2 = 8;

// LED-Button
const int buttonPin = 14; // A0
const int ledPin = 12;

bool ledState = false;
int currentBtnState = LOW;
int lastBtnState    = LOW;
// Button debounce
Timer debounce = Timer(1000);
int freezed = 0;
// int debounce = 1;

// Laufzeit-Steuerung (Wie lange soll der Zug fahren)
Timer timer = Timer(20000);
int intervalTime = 3000;
int resetTime = 0;
int currentTime = 0;

void setup() {
  Serial.begin(9600);
  // Serial.println("Start");

  // IBT2 - PINS
  pinMode(PIN_motorRight, OUTPUT);
  pinMode(PIN_motorLeft, OUTPUT);
  // IBT2 - INIT
  digitalWrite(PIN_motorRight, LOW);
  digitalWrite(PIN_motorLeft, LOW);

  // Relay - PINS
  pinMode(PIN_relay1, OUTPUT);
  pinMode(PIN_relay2, OUTPUT);
  // Relay - INIT
  digitalWrite(PIN_relay1, HIGH);
  digitalWrite(PIN_relay2, LOW);
  
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);

  // start timer
  timer.start();
  debounce.start();
}

void startTrain() {
  // LED: ON
  digitalWrite(ledPin, HIGH);
  // Motor-Right: ON
  digitalWrite(PIN_motorLeft, LOW);
  analogWrite(PIN_motorRight, VMAX);  
}
void stopTrain() {
  // LED: OFF
  digitalWrite(ledPin, LOW);
  // Motor: OFF
  digitalWrite(PIN_motorLeft, LOW);
  digitalWrite(PIN_motorRight, LOW);
}

int getBtnState() {  
  // Serial.println(analogRead(buttonPin));
  if(analogRead(buttonPin) >= 1023) return HIGH;  // max. 1023
  return LOW; 
}

void loop() {
  // aktuelle Taster-Stellung
  currentBtnState = getBtnState();  

  if(currentBtnState == HIGH && lastBtnState == LOW && debounce.isReached()) {
    ledState = !ledState; // Umkehr
    // reset timer
    timer.reset();
    debounce.reset();
  }

  // Hole aktuellen Taster-Status
  lastBtnState = currentBtnState;

  // Timer?
  if(timer.isReached()) ledState = false;

  // STROM?
  if (ledState) startTrain(); else stopTrain();  
}

