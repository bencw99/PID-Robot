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
  		
  		Talon leftFrontVic;
  		Talon leftBackVic;
  		Talon rightFrontVic;
  		Talon rightBackVic;
  		
  		PIDController leftFrontController;
		PIDController leftBackController;
		PIDController rightFrontController;
		PIDController rightBackController;
  		
  		Encoder leftEncoder;
  		Encoder rightEncoder;
  		
  	public:
		DriveTrain();
		
		void init();
		void update();
		void disable();
		
		double getMoveSpeed();
		double getRotateSpeed();
		
		void setMoveSpeed(double moveSpeed);
		void setRotateSpeed(double rotateSpeed);
		
		void setAllVics(double speed);
		
		void driveDistance(double distance);
};
#endif
