const int tempPin = A0;
int incomingByte;// incoming data
 
void setup() {
  Serial.begin(9600); // initialization
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.println("Press 1 to LED ON or 0 to LED OFF...");
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
}
 
void loop() {
  int val = analogRead(tempPin);
  float volt = (val/1024.0) * 5.0;
  float temperature = (volt - .5) * 100;
  Serial.print(temperature);
  Serial.print("C \n");
  if (Serial.available() > 0) {  // if the data came
    incomingByte = Serial.read(); // read byte
    //Serial.println(incomingByte);
  
    if(incomingByte == '0') {
       digitalWrite(LED_BUILTIN, LOW);  // if 1, switch LED Off
       //Serial.println("LED OFF. Press 1 to LED ON!");  // print message
    }
    if(incomingByte == '1') {
       digitalWrite(LED_BUILTIN, HIGH); // if 0, switch LED on
       //Serial.println("LED ON. Press 0 to LED OFF!");
    }
  }
}
