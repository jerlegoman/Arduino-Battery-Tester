/*
  ReadAnalogVoltage and
  Battery Tester
  Reads an analog input on pin A2, converts it to voltage, and prints the result to the serial monitor.
  Attach the center pin of a potentiometer to pin A2, and the outside pins to +5V and ground.
  If the voltage is greater than 1.40 it will light up the green LED indicating that the battery is Good
  If the voltage is less than 1.40 and higher than 1.28 then, 
  I built this on an ATTINY85 chip from atmel that i got from amazon.com 
 This example code is in the public domain.
 */
int green = 0; // green is equal to pin 0
int yellow = 1; // yellow is equal to pin 1
int red = 2; // and red is equal to pin

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  pinMode(green, OUTPUT); //green is an output
  pinMode(yellow, OUTPUT); //yellow is an output
  pinMode(red, OUTPUT); // and red is also an output
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(A2);
  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  float voltage = sensorValue * (5.0 / 1023.0);
  // print out the value you read:
  if (voltage > 1.40)
  {
    digitalWrite(green, HIGH); //green LED on
    digitalWrite(yellow, LOW); //yellow LED off
    digitalWrite(red, LOW); //red LED off
  }
  else if (1.40 >= voltage && voltage > 1.28)
  {
    digitalWrite(green, LOW); //green led off
    digitalWrite(yellow, HIGH); // yellow LED on
    digitalWrite(red, LOW); //red led off
  }
  else if (1.28 >= voltage)
  {
    digitalWrite(green, LOW); //green LED off
    digitalWrite(yellow, LOW); // yellow LED off
    digitalWrite(red, HIGH); //red LED on
  }
  

}
