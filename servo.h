#ifndef servo_h
#define servo_h

// This is the original servo code. It does the normal jump from one position to the next.
// If that's all you need, this'll be fine. Most only need them to do that anyway. Probably,
// as the new stuff is ironed out, this class will be scrapped. I don't want multiple
// classes to do the same thing.


#include "squareWave.h"

class servo : public squareWave {

	public:
				servo (int inPin);
	virtual	~servo(void);
     
				void	setServo(float val); 
	virtual	void	pulseOn(void);
	virtual	void	pulseOff(void);
	
				bool	init;
				int	mPin;
};

#endif