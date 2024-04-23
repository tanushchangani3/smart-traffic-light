//Light senosr module
int analogPin = A2;

int val = 0;        // Variable to store the analog value

 

void setup() {

  Serial.begin(9600); // Initialize serial communication

}

 

void loop() {

  val = analogRead(analogPin); // Read the analog value

  float voltage = val * (5.0 / 1024.0); // Convert to voltage

  Serial.print("Analog reading: ");

  Serial.print(val); // Print the raw analog reading

  Serial.print(" - Voltage: ");

  Serial.println(voltage, 2); // Print the voltage (rounded to 2 decimal places)

  delay(500); // Delay for stability

}
