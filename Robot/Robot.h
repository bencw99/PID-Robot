#ifndef ROBOT_H
#define ROBOT_H
#include <WPILib.h>
#include "Constants.h"
#include "DriveTrain.h"

class Robot
{
	private:
		DriveTrain driveTrain;
		
	public:
		Robot();
		void init();
		void update();
		void disable();
		
		void driveDistance(double distance);
		void setMoveSpeed(double moveSpeed);
		void setRotateSpeed(double rotateSpeed);
};

#endif
