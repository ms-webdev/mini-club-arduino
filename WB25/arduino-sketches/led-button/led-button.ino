
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
