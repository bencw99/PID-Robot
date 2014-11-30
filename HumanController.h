
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
  		Joystick Shooter;//shooter value controller
  		
  		double rotationControllerVal;//left right value of x value
  		double movementControllerVal;//up down value of y value
  		double ShooterVal;//general value of shooter controller(i think)
  		
	public:
		
		HumanController HumanController;
		
		double getRotationVal();
		double getMovementVal();
		double getShooterVal();
		
		void update();
		
};
#endif
