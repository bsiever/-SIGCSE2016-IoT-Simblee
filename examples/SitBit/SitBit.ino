/*
 * A SimbleeForMobile sketch for a primitive fitness tracker
 * 
 */

// TODO:
//    1. Review the code until you understand how it works.
//    2. Complete the two TODO items in the setup()
//    3. Upload this file and run it!
//    4. Use te SimbleeForMobile app to interact with your fitness counter.
//    5. Add a calorie counter that would translate a (correct) step count into calories
//
// CHALLENGE TODOs: 
//    a. When disconnecting and reconnecting the number of steps isn't shown correctly.
//       Update it so it works correctly.
//    b. Polling the button isn't an effective way to detect a single change. 
//       Develop new logic that is more robust.  (Use of millis() to count elapsed time
//       may be helpful).

#include <SimbleeForMobile.h>

// Use pin 6 for a switch (tile switch)
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



