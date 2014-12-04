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
  		
  		Encoder leftEncoder;
  		Encoder rightEncoder;
  		
  	public:
		DriveTrain();
		
		double getMoveSpeed();
		double getRotateSpeed();
		
		void setMoveSpeed(double moveSpeed);
		void setRotateSpeed(double rotateSpeed);
		
		void setAllVics(double speed);
		
		void init();
		void update();
		void disable();
		
};
#endif
