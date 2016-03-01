// Include the BLE library
#include <SimbleeBLE.h>

/*
  SimBLESmartLight
  A Simple BLE RGB Light
  */

// TODO: 
//    1. Review the code until you understand how it works.
//    2. Complete the two TODO items in the setup()
//    3. Upload this file and run it!
//    4. Use a BLE Browser to interact with the device. Write 3 bytes to characteristic 2D30C083-F39F-4CE6-923F-3484EA480596
//    5. Add a single-byte off-command (and single byte turns the light off).
//
// CHALLENGE TODOs: 
//    Also allow a 4 byte "fade" pattern. The first three bytes will be the color to 
//    fade to and the last byte will be the time to fade. 
//    (Hints: You'll need to persistently keep track of colors.  
//            The current use of local variables won't suffice. 
//            The "millis()" function can be used to get the number of milliseconds
//            since the Simblee was powered on.

  
// Define where each color LED is connected
const int led_red = 2;
const int led_green = 3;
const int led_blue = 4;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pins as outputs.
  pinMode(led_red, OUTPUT);     
  pinMode(led_green, OUTPUT);     
  pinMode(led_blue, OUTPUT);     

  // TODO: Add your 3-4 letter Advertising String and end the quotes:
  //       (This will help you identify and work with your device)
  SimbleeBLE.advertisementData = "rgb-      
  SimbleeBLE.deviceName = "rgb-

  // Start the BLE stack
  SimbleeBLE.begin();
}

// the loop routine runs over and over again forever:
void loop() {
 // Sleep when not processing radio messages
 Simblee_ULPDelay(INFINITE);
}

void SimbleeBLE_onConnect() {
  // Things to do when a phone connects
}

void SimbleeBLE_onDisconnect() {
  // Things to do when a phone disconnects
}

void SimbleeBLE_onReceive(char data[], int len) {
  // If the message has three bytes, use them to control the RGB colors
  if (len == 3) {
    // get the R value and use it to control the LED intensity
    uint8_t r = data[0];
    // Analog write: writes a value from 0-255.  
    // This controls the amount of time the LED is on and, consequently, the
    // amount of the color that is perceived.
    analogWrite(led_red, r);

    // get the G value and use it to control the LED intensity
    uint8_t g = data[1];
    analogWrite(led_green, g);
    
    uint8_t b = data[2];
    analogWrite(led_blue, b);
  }
}



