
#ifndef HUMANCONTROLLER_H
#define HUMANCONTROLLER_H
#include <WPILib.h>
#include <stdlib.h>
#include <iostream>

class HumanController
{
	private:
  	
  		Joystick rotationController;//x value controller
  		Joystick movementController;//y value controller
 
  		
  		double rotationControllerVal;//left right value of x value
  		double movementControllerVal;//up down value of y value
  		
	public:
		
		HumanController HumanController;
		
		double getRotationVal();
		double getMovementVal();
	
		void update();
		
};
#endif
