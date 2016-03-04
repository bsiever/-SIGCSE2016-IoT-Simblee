/*
 * A SimbleeForMobile App for monitoring the user's pulse.
 */

// TODO:
//    1. Review the code
//    2. Complete the two TODO items in the setup()
//    3. Upload this file and run it!
//    4. Use the SimbleeForMobile app to verify that the (simulated) pulse
//       is being shown.
//    5. Change setup() so the app will show the actual pulse from the center.
//    6. Upload the file and try it!
//    6. Create a simple bar graph.  Create a single rectangle at the bottom
//       of the screen and update its height in proportion to the user's pulse.
//       Use https://www.simblee.com/Getting%20Started%20with%20SimbleeForMobile%20v1.02.pdf
//       to find details on the drawRect() functions.
//    7. Create a full bar graph. 

#include <SimbleeForMobile.h>
#include <PulseSensorAmped.h>

const int pulseSignalPin = 6;
uint8_t   pulseLabel;

void setup() {
  // TODO: Add your 3-4 letter Advertising String and end the quotes:
  //       (This will help you identify and work with your device)
  SimbleeForMobile.advertisementData = "Pls-
  SimbleeForMobile.deviceName = "Pls-

  // Connect the Pulse Sensor to the Pin
  PulseSensorAmped.attach(pulseSignalPin);
 
  // NOTE: This uses artificial data by default.  
  //       Disable this line to use sensor data 
  //       (Using it allows easy testing of callbacks)
  PulseSensorAmped.spoofedData(true);

  SimbleeForMobile.begin();
}


void loop() {
  SimbleeForMobile.process();  
  // Process pulse data
  PulseSensorAmped.process();
}

void ui() {
  color_t darkgray = rgb(85,85,85);
  int width = SimbleeForMobile.screenWidth;
  int height = SimbleeForMobile.screenHeight;
    
  SimbleeForMobile.beginScreen(darkgray);
  SimbleeForMobile.drawText(width/2-45, height/2-250, "Pulse", WHITE, 45);
  pulseLabel = SimbleeForMobile.drawText(width/2-30, height/2-25, "---", WHITE,45);
  SimbleeForMobile.endScreen();
}

void SimbleeForMobile_onConnect(void) {
  PulseSensorAmped.start();
}

void SimbleeForMobile_onDisconnect(void) {
  PulseSensorAmped.stop();  
}

// An optional function to recieve the Beats Per Minute (BPM) and Interbeat Interval (IBI) in mS
void PulseSensorAmped_data(int BPM, int IBI) {
  if(SimbleeForMobile.updatable) {
    SimbleeForMobile.updateValue(pulseLabel,BPM);
  }
}

// An optional function to indicate that the pulse signal has been lost
// (Due to the nature of pulse detection via reflected light, spurios signals are possible. 
//  i.e. received data may not be valid) 
void PulseSensorAmped_lost(void) {
  if(SimbleeForMobile.updatable)
    SimbleeForMobile.updateText(pulseLabel,"---");
}

