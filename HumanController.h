
#ifndef HUMANCONTROLLER_H
#define HUMANCONTROLLER_H
#include <WPILib.h>
#include <stdlib.h>
#include <iostream>

class HumanController
{
	private:
  	
  		/** The controller determining rotation, measured by x **/
  		Joystick rotationController;
  		/** The controller determining movement, measured by y **/
  		Joystick movementController;
  		
  		double rotationControllerVal;//left right value of x value
  		double movementControllerVal;//up down value of y value
  		
	public:
		
		HumanController HumanController;
		
		double getRotationVal();
		double getMovementVal();
	
		void update();
		
};
#endif
