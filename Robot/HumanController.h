
#ifndef HUMANCONTROLLER_H
#define HUMANCONTROLLER_H
#include <WPILib.h>
#include "Robot.h"
#include <stdlib.h>
#include <iostream>

class HumanController
{
	private:
  		Robot *robot;
  		
  		/** The controller determining rotation, measured by x **/
  		Joystick rotationController;
  		/** The controller determining movement, measured by y **/
  		Joystick movementController;
  		
  		
  		
	public:
		
		HumanController(Robot *robot);
	
		double getRotation();
		double getMovement();
		
		void update();
};
#endif
