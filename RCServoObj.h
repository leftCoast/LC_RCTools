#ifndef RCServoObj_h
#define RCServoObj_h


#include "lists.h"
#include "timeObj.h"
#include "squareWave.h"
#include "baseTrapMove.h"



#define   DEF_SEC_PER_60_DEG .16    //.16 seconds / 60deg. Avarage speed spec. used for RC servos. (Smaller value is faster)
#define   DEF_SWING_DEG       90   // Typical servo rotates 90 degrees lock to lock.

// Formula for maximum servo velocity : Percent swing / milisecond = 60 / (SecPer60 * SwingDeg * 10)
// You don't really need to know this to use the code. Its just here for those that have to
// go under the hood to fix things.


// There is a default to this servoType bit. If you don't want to deal with it you don't
// need to. The default will probably work just fine.
class servoType {

   public:
            servoType(double secondsPer60Degee=DEF_SEC_PER_60_DEG,double totalSwingDegrees=DEF_SWING_DEG);
            ~servoType(void);

            double   mapVel(double inVel);
            double   mapDeg(double inDeg);
            
            mapper   mVelMapper;
            mapper   mDegMapper;
};


// Here is the servo object. Create one using the pin number its hooked to. Then you can do
// move(0..100%) or controlledMove(0..100%, 0..100%, 0..100%) Position, velocity, acceleration.
// While doing a controlled move, you can call moving() to see if the move is still in
// progress.
class RCServoObj :   public linkListObj,
                     public timeObj {

   public:
            RCServoObj(int pinNumber,servoType* inServoType=NULL);
   virtual  ~RCServoObj(void);

            void  move(double newPos);
            void  controlledMove(double newPos,double inVmax=100,double inAccel=50);
            void  controlledDegreeMove(double newPosDeg,double inVmax=100,double inAccel=50);
            bool  moving(void);
            
            void  startPulse(void);
            void  endPulse(void);
            void  calcNextPos(void);
            
   protected:
  
   virtual  bool  isGreaterThan(linkListObj* compObj);
    virtual bool  isLessThan(linkListObj* compObj);

            int            mPin;
            servoType*     mServoType;
            bool           mControlledMove;
            double         mNextPos;
            double         mEndPos;
            double         mStartPos;
            double         mLastPos;
            baseTrapMove   mTrapMove;
            unsigned long  mTotalTime;
            bool           mForward;
            
};


// Don't worry about this bit. Its the controller behind the scenes that manages all your
// servos.
class servoController : public linkList,
                        public squareWave {

   public:
            servoController(void);
   virtual  ~servoController(void);

            void  addServo(RCServoObj* newServo);

   protected:
   virtual  void  pulseOn(void);
   virtual  void  pulseOff(void);
            void  startServos(void);
            void  watchServos(void);
            void  addNewServos(void);
            void  calcMoves(void);

            RCServoObj* mIdleServoList;

};

extern servoController servoControl;	// Servo manager. Runs automatically in the background.

#endif
