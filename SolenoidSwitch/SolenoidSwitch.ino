// XIAO ESP32-C3 Pin Control
#define PIN_ON 5    // GPIO5
#define PIN_OFF 21  // GPIO21

void setup() {
  // Set GPIO5 as output and turn it ON
  pinMode(PIN_ON, OUTPUT);
  digitalWrite(PIN_ON, HIGH);
  
  // Set GPIO21 as output and turn it OFF
  pinMode(PIN_OFF, OUTPUT);
  digitalWrite(PIN_OFF, LOW);
}

void loop() {
  // Nothing needed in loop since pins stay constant
}