// XIAO ESP32-C3 UART to GPIO Control
#define GPIO2 2   // GPIO2 pin
#define PASSWORD "18922601"

// Buffer to store incoming UART data
char receivedData[32];
int dataIndex = 0;

void setup() {
  // Initialize GPIO2 as output
  pinMode(GPIO2, OUTPUT);
  digitalWrite(GPIO2, LOW); // Start with GPIO2 LOW

  // Initialize Serial for debugging (USB)
  Serial.begin(115200);

  // Initialize UART2 for communication
  Serial1.begin(115200, SERIAL_8N1, RX, TX);

  Serial.println("XIAO ESP32-C3 UART Reader Started");
}

void loop() {

  while (Serial1.available()) {
    char incomingChar = Serial1.read();
    Serial.print("incoming char:");
    Serial.println(incomingChar);
    Serial.print("received data:");
    Serial.println(receivedData);

    // Check for message end or buffer limit
    if (incomingChar == '\n' || incomingChar == '\r' || dataIndex >= 31) {
      receivedData[dataIndex] = '\0'; // Null terminate the string

      // Check if message contains PASSWORD
      if (strstr(receivedData, PASSWORD) != NULL) {
        digitalWrite(GPIO2, HIGH);
        Serial.println("GPIO2 set HIGH - correct password");
        delay(500);
        digitalWrite(GPIO2, LOW);
      }

      // Reset buffer and index
      dataIndex = 0;
      memset(receivedData, 0, sizeof(receivedData));
    } 
    else {
      // Store character in buffer
      receivedData[dataIndex] = incomingChar;
      dataIndex++;
    }
  }
}