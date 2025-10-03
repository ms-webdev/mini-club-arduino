
const int buttonPin = A8;//2;
const int ledPin = 6; 

// variables
bool ledState = false;
int currentBtnState = LOW;
int lastBtnState    = LOW;

unsigned long freezed = 0;
unsigned long debounce = 2000UL;

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

  if(currentBtnState == HIGH && lastBtnState == LOW && (millis() - freezed > debounce)) {
      
    ledState = !ledState; // Umkehr
    Serial.println("PRESSED");

    freezed = millis();
  }
  
  lastBtnState = currentBtnState;

  // STROM?
  if (ledState) {
    // AN
    digitalWrite(ledPin, HIGH);
    //analogWrite(ledPin, 100); // 0-255
    //Serial.println("AN");
  } else {
    // AUS
    digitalWrite(ledPin, LOW);
    //analogWrite(ledPin, 0); // 0-255
    //Serial.println("AUS");
  }
}


int getBtnState() {
  
  if(analogRead(buttonPin) > 1000) return HIGH;  // max. 1023

  return LOW;  
  
}
