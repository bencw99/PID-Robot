#ifndef DRIVETRAIN_H
#define DRIVETRAIN_H
#include <WPILib.h>
#include <stdlib.h>
#include <iostream>

class DriveTrain
{
	private:
  		double moveSpeed;
  		double rotateSpeed;
  		
  		Victor leftFrontVic;
  		Victor leftBackVic;
  		Victor rightFrontVic;
  		Victor rightBackVic;
  		
  	public:
		DriveTrain();
		
		double getMoveSpeed();
		double getRotateSpeed();
		
		void setMoveSpeed(double moveSpeed);
		void setRotateSpeed(double rotateSpeed);
		
		void update();
		
		void setAllVics(double speed);
		
		void disable();
		
};
#endif
