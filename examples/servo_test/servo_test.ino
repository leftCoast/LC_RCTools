
#include "RCServoObj.h"

// NOTE : In this example we use while(something) idle(); as a way to emulate delay().
// Your code should be designed to not need this kind of "crutch", but at times its just
// the way it is. If you use delay(), everything stops, and you will be unhappy. So if
// you really need to stop the user, this while()idle(); Hack can do the trick for you.


RCServoObj aServo(2);   // Create a servo object with its pin number.
timeObj timer(1500);    // Timer for holding for "blind" moves to complete.

void setup() {
   
   aServo.move(0);               // First we need to move the servo to a known position.
                                 // This is a blind move.no control.
                                 
   timer.start();                // Its going to take some time to get there. Start the timer.
   while(!timer.ding()) idle();  // The servo code runs in the background. 
                                 // This stops the foreground code only. 
                                 // Its what delay() should have been.
}


void loop() {

   idle();                                      // Let the background stuff have some time.
   aServo.controlledMove(0,100,.01);            // Start the move to 0% 100% velocity, .01 Acceleration.
   while(aServo.moving()) idle();               // While moving, stop foreground letting servo run.
   aServo.controlledMove(100,100,.01);          // Start move to 100% 100% velocity, .01 Acceleration.
   while(aServo.moving()) idle();               // While moving, stop foreground letting servo run.


   // If you have the servo specs. speed and degrees swing. The code can be set up to do specific moves in degrees.
   
   aServo.controlledDegreeMove(45,100,.150);    // Start the move to 45 Deg. 100% velocity, .15 Acceleration.
   while(aServo.moving()) idle();               // While moving, stop foreground letting servo run.
   aServo.controlledDegreeMove(90,100,.150);    // Start the move to 90 Deg. 100% velocity, .15 Acceleration.
   while(aServo.moving()) idle();               // While moving, stop foreground letting servo run.
  delay(1000);                                  // Everything is over, take a breather for a second.
}
