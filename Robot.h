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
		void update();
		void disable();
		
		DriveTrain getDriveTrain();
};

#endif
