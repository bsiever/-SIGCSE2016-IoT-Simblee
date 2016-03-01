/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
  */

// TODO: 
//    1. Review the code until you understand how it works.
//    2. Upload this file and run it!
//    3. Change the blink pattern --- leave green on for 2 seconds and off for 1.
//    4. There is a Red led on pin 2.  Have it blink green for 2 seconds then red for 1 second.
//    5. Practice using log messages for debugging:
//    6. Add the following lines in setup():
//          Serial.begin(9600);
//          Serial.println("Hello from setup()");
//       then add the following lines in loop():
//          Serial.println("Looping");
//       Be sure to open the serial monitor (from the Tools menu or the magnifying glass
//       icon in the upper right of this window).  Upload your sketch and observe 
//       the messages.   What happens if you add more println()s to the loop()?
//
// CHALLENGE TODO: Make the LEDs blink a rhythm


// Pin 3 on the Shield is connected to a green LED.
const int led_green = 3;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(led_green, OUTPUT);     
}

// the loop routine runs over and over again forever:
void loop() {
  digitalWrite(led_green, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                     // wait for a 1000mS (1 second)
  digitalWrite(led_green, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                     // wait for a 1000mS (1 second)
}

