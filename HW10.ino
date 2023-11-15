const int ledPins[] = {3,5,6,9,10,11}; // Define LED pin array
const int numLEDs = 6; // LED number
const unsigned long interval = 1000; // updated every second

unsigned long previousMillis = 0; // Store the time of the last update
int binaryCounter = 0; // Record the current six-digit binary number

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < numLEDs; i++) {
    pinMode(ledPins[i], OUTPUT); // Set LED pin as output
  }
}

void loop() {
  unsigned long currentMillis = millis(); // Get current time

  if (currentMillis - previousMillis >= interval) {
    // If a time interval of one second has elapsed

    // Update time of last update
    previousMillis = currentMillis;

    // Increment binary counter
    binaryCounter++;

    // If the counter reaches 60, it is reset to 0
    if (binaryCounter == 60) {
      binaryCounter = 0;
      // clear display
      clearDisplay();
    }

    // Update LED display
    updateLEDs(binaryCounter);
  }
}
void updateLEDs(int value) {
  // Convert the integer value to a six-digit binary number and update the LED display
  for (int i = 0; i < numLEDs; i++) {
    int rest=value / pow(2, i);
    digitalWrite(ledPins[i], rest % 2);
  }
  for (int i = numLEDs-1; i >=0; i--) {
    int rest=value / pow(2, i);
    Serial.print(rest%2);
  }
  Serial.print(".   ");
  Serial.println(value);
}

void clearDisplay() {
  // Turn off all LEDs
  for (int i = 0; i < numLEDs; i++) {
    digitalWrite(ledPins[i], LOW);
  }
}
