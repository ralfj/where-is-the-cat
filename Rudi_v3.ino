#include <MicroView.h>    // include MicroView library

int buttonPin = A0;       // the the input pin
int buttonState = 0;    // variable to store the pushbutton status
int counter = 0;     // set variable counter equal to 0
int state = true;   // set variable state equal to TRUE

void setup() {
   uView.begin();      // start MicroView custom Ardiuno library
   uView.clear(PAGE);    // clear page

   pinMode(buttonPin, INPUT);    // initialize the pushbutton pin as an input
   digitalWrite(buttonPin,HIGH);   // set Internal pull-up
}


void loop() {
   buttonState = digitalRead(buttonPin); // read the state of the pushbutton value

   uView.setCursor(0, 0);   // set cursor at 0,0 on the display
   uView.print("Rudi is.. ");     // print Rudi is...
   uView.display();

   uView.setCursor(0, 10);   // set the cursor to 0,10 on the display
   if (state)  { uView.print("IN "); } else { uView.print("OUT "); }  // either print In or Out depending on the value of the state varible
   uView.display();

   uView.setCursor(0, 20);   // set the cursor to 0,20 on the display
   uView.print(counter); // display the current value of the variable counter
   uView.display();

   // check if the pushbutton is pressed.
   // if it is not pressed, the buttonState is HIGH:
   if (buttonState == LOW) {
      delay(1000); // delay to de-bounce the switch input, in the final hardware implementation we need to find a better solution than a time delay
      counter = counter + 1; // increment the variable counter by 1 each time the button state changes
      state = !state; // invert the value of the variable state
   }
}
