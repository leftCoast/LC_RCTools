#include "trapMove.h"

linegrator(float y1,float y2,float dx,float c) { return (((y1+y2)/2) * dx) + c; }



trapMove::trapMove(float distance,float MaxVelocity,float accelAngle) {

	Dm 	= distance;							// Distance to travel.
	Vm 	= MaxVelocity;						// Max velocity possible.
	if (accelAngle>=90) {
		moveType = instMove;
	} else if (accelAngle<=0) {
		moveType = noMove;
	} else {
		TANa	= tan(accelAngle);			// Tangent of the acceleration angle. ( TAN(µ) = Opposite/adjacent )
		Tc		= Vm/TANa;						// Time to hit max velocity.
		Tm		= (Dm/Vm)+(Vm/TANa);			// Total time for move. (CHECK FOR BOTH CASES)
		if (Tc<(Tm/2) {						// If Time to hit max Velocity < 1/2 total time for move.
			moveType = trapMove;				// Its a trapezoidal move.
			A1			= Tc*Vm/2;				// Aria of accel triangle.
			A2			= (Vm*(Tm-Tc))-A1;	// Aria of accel triangle + cruise rectangle;
		} else {									// else, Tc >= 1/2 total time.
			moveType = triMove;				// Its a triangle move. (Never hits max velocity)
			Vtm		= sqrt(Dm * TANa);	//	The Height of the triangle.
			Tm2		= Tm/2;					// Half the time.
			TANa2		= TANa/2;				// Tan(a)/2  
		}
	}
}


trapMove::~trapMove(void) {  }

	
float trapMove::dist(float t) {
	
	switch(moveType) {
		case instMove	: return return (t * Vm);
		case noMove		: return 0;
		case trapMove	: return trapizoid(t);
		case triMove	: return triangle(t);
	}
}


float trapMove::trapizoid(float t) {
	
	
}


float trapMove::triangle(float t) {

	If (t<=Tm2) {
		return (t^2) * TANa2;
	} else {
		return Dm - ((Tm - t)^2 * TANa2);	// Total area (Dm) - Triangle area not covered.
	}
}