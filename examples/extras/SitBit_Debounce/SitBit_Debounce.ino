/*
 * A SimbleeForMobile sketch for a primitive fitness tracker
 * 
 * This version includes a state machine to debounce the tilt switch.
 */


#include <SimbleeForMobile.h>

// Define the pin that represents the tilt switch
const int tiltSwitch = 6;
int stepCount = 0;
int stepsLabelId = 0;

// Define constants for debounce
const int min_on_time = 5;
const int min_contact_interval = 200;


void setup() {
  Serial.begin(9600);
  Serial.println("Started");  
  // step sensor
  pinMode(tiltSwitch, INPUT_PULLUP);

  // this is the data we want to appear in the advertisement
  // (if the deviceName and advertisementData are too long to fix into the 31 byte
  // ble advertisement packet, then the advertisementData is truncated first down to
  // a single byte, then it will truncate the deviceName)
  SimbleeForMobile.advertisementData = "SitBit";
  
  // use a shared cache
  SimbleeForMobile.domain = "siever.info";
  
  SimbleeForMobile.begin();
}


void buttonPressed() {
  Serial.println("Press");
  stepCount++;
  if (SimbleeForMobile.updatable) {
      SimbleeForMobile.updateValue(stepsLabelId, stepCount);
  }
}

void updateSwitchState() {
  static int state = 0;
  static int onStart = 0;
  static int offStart = 0;

  int currentState = digitalRead(tiltSwitch);
  
  switch(state) {
    case 0: // Waiting for ON
      if(currentState) {
        state = 1;
        onStart = millis();
      }
      Simblee_pinWake(tiltSwitch, HIGH);
    break;

    case 1: // Waiting for on time
      if(millis() - onStart > min_on_time) 
        state = 2;
    break;

    case 2: // Check it
      if(currentState) { 
          // if still on 
         buttonPressed();
         state = 3; // Wait for release
         Simblee_pinWake(tiltSwitch, LOW);
      } else { // Reset
        state = 0; // Wait for on
        Simblee_pinWake(tiltSwitch, HIGH);
      }
      break;
      
    
    case 3: // Waiting for off time
      if(!currentState) {
         offStart = millis();
         state = 4;
      }
    break;

    case 4: // Waiting for off
    default:
      if((millis()-offStart) >  min_contact_interval ) {
        if(!currentState) {
          state=0;
        }
      }
    break;
  }
}




void loop() {  
  updateSwitchState();
  
  SimbleeForMobile.process();

  Simblee_ULPDelay(INFINITE);
}


void ui()
{
  SimbleeForMobile.beginScreen(WHITE);

  // Place a Logo on the screen
  SimbleeForMobile.drawText(110, 180, "Steps", BLACK, 40);

  // Place an updateable label on the screen
  stepsLabelId = SimbleeForMobile.drawText(150, 220, stepCount, BLACK, 40);
  
  SimbleeForMobile.endScreen();

  SimbleeForMobile.endScreen();
}

void ui_event(event_t &event)
{
  Serial.println("UI Event");  
}
