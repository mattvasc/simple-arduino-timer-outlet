#define RELAY_PIN 2


/*
 * D2 2
 * D3 3
 * D4 4
 * D5 5
 */

// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(9600);
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(RELAY_PIN, OUTPUT);

  Serial.print("Testing relay on pin number: ");
  Serial.println(RELAY_PIN);
  
  
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(RELAY_PIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(RELAY_PIN, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second
}
