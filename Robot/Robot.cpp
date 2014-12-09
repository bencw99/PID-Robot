#include "Robot.h"

Robot::Robot():
	driveTrain()
{
	
}

void Robot::init()
{
	driveTrain.init();
}

void Robot::update()
{
	driveTrain.update();
}

void Robot::disable()
{
	driveTrain.disable();
	
}

void Robot::setMoveSpeed(double moveSpeed)
{
	driveTrain.setMoveSpeed(moveSpeed);
}

void Robot::setRotateSpeed(double rotateSpeed)
{
	driveTrain.setRotateSpeed(rotateSpeed);
}
