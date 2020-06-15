#ifndef trapMove_h
#define trapMove_h

extern linegrator(float y1,float y2,float dx,float c);


class trapMove {

	public:
	
	enum		moveTypes	{ triMove, trapMove, instMove, noMove };
	
				trapMove(float distance,float MaxVelocity,float accelAngle);
	virtual	~trapMove(void);
	
				float	dist(float t);
				
				moveTypes	moveType;
				float			Dm;
				float			Vm;
				float			TANa;
				float			Tc;
				float			Tm;
};

#endif