# LC_RCTools
Tools for interacting with Radio Control servos.

**RCServoObj**  
RCServoObj has the controlled (trapezoid) move in it. It compiles and works. So far. But not very tested yet. I added an example .ino file on how to make it go.  

**NOTE :** Typically you can't read a servo's position. Meaning? When your program starts up, the servo code doesn't know where the servo is. If it dosen't know where it is, it can't do any calcualtions for a controlled move. Therefore, your first move, controlled or not, will be an uncotrolled jump like the good old days. This sets the servo to a known position and it can do calculated moves from there on. So, don't get all worked up when your first move is a jump. **Its best if you can start your program with the sevo in a known position, tell the servo to move() to where it already is, setting its position without the initial jump. From then on, you can do controlled moves smoothly.**

**servoType class**  
This allows the user to set specific parameters for their different type servos. Allowing moves by degree, more accurate speed control and things like that. Typically? There is a default servoType object automatically set up for you. So, if you don't what to deal with all that, don't worry. The default will be fine for most everything you'll need. Meaning, you can ignore this class for now.

**RCReciver**  
RCReciver is non functioning at the moment. ( An IDE upgrade broke it and I've not had a look yet to see what went wrong. )

Good luck.


