#include "Robot.h"

Robot::Robot():
	driveTrain()
{
	
}

void Robot::update()
{
	driveTrain.update();
}

void Robot::disable()
{
	driveTrain.disable();
}

DriveTrain Robot::getDriveTrain()
{
	return driveTrain;
}
