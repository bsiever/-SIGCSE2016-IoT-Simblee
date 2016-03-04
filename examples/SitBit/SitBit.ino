/*
 * A SimbleeForMobile sketch for a primitive fitness tracker
 * 
 */

// TODO:
//    1. Review the code
//    2. Complete the two TODO items in the setup()
//    3. Upload this file and run it!
//    4. Use te SimbleeForMobile app to see the readings from your fitness counter
//    5. Steps are being overcounted.  Develop an algorithm that more 
//       accurately counts steps
//    6. Add a calorie counter that would translate a (correct) step count into calories
//       (Review the sketch for details of how labels are added)
//    7. Update the hardware:  Disconnect the USB cord, remove the Shields,
//                             replace the USB shield with the battery shield, 
//                             and try it out)
//
// CHALLENGE TODOs: 
//    a. When disconnecting and reconnecting the number of steps isn't shown correctly.
//       Update it so it works correctly.
//    b. Use an actual accelerometer (like: https://www.sparkfun.com/products/11446)
//    c. Add a button to the app that will reset the step counter and calorie counter
#include <SimbleeForMobile.h>

// Use pin 6 for a switch (tilt switch)
const int switchPin = 6;

int stepCount = 0;
int stepsLabelId = 0;

void setup() {
  Serial.begin(9600);

  // button press / step sensor
  pinMode(switchPin, INPUT_PULLUP);

  // TODO: Add your 3-4 letter Advertising String and end the quotes:
  //       (This will help you identify and work with your device)
  SimbleeForMobile.advertisementData = "Sit-
  SimbleeForMobile.deviceName = "Sit-
  
  // use a shared cache
  SimbleeForMobile.domain = "siever.info";

  // Start SimbleeForMobile
  SimbleeForMobile.begin();
}


void loop() {  
  // Check to see if the button is pressed
  int currentState = digitalRead(switchPin);
  if(currentState == true) {
    // It's pressed: Count it!
    stepCount++;

    // If the screen is available, update the count
    if (SimbleeForMobile.updatable) {
        SimbleeForMobile.updateValue(stepsLabelId, stepCount);
    }
  }

  // Process any messages to/from SimbleForMobile 
  // (Must regularly process messages / run the "event loop")
  SimbleeForMobile.process();
}

// Create the user interface 
// (this example is strictly a display. It doesn't allow user interaction)
void ui() {
  SimbleeForMobile.beginScreen(WHITE);

  // Place a Logo on the screen
  SimbleeForMobile.drawText(110, 180, "Steps", BLACK, 40);

  // Place an updateable label on the screen
  stepsLabelId = SimbleeForMobile.drawText(150, 220, stepCount, BLACK, 40);
  
  SimbleeForMobile.endScreen();
}

