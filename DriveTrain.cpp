#include "DriveTrain.h"
#include "Constants.h"
#include <WPILib.h>

DriveTrain::DriveTrain()
	leftFrontVic((uint32_t) PORT_DRIVE_VIC_LEFT_FRONT),
	leftBackVic((uint32_t) PORT_DRIVE_VIC_LEFT_BACK),
	rightBackVic((uint32_t) PORT_DRIVE_VIC_RIGHT_BACK),
	rightFrontVic((uint32_t) PORT_DRIVE_VIC_RIGHT_FRONT)
{
	setAllVics(0.0);
}

double DriveTrain::getMoveSpeed()
{
	return moveSpeed;
}

double DriveTrain::getRotateSpeed()
{
	return rotateSpeed;
}

void DriveTrain::setMoveSpeed(double moveSpeed)
{
	this->moveSpeed = moveSpeed;
}

void DriveTrain::setRotateSpeed(double rotateSpeed)
{
	this->rotateSpeed = rotateSpeed;
}

void DriveTrain::update()
{
	double leftSpeed = min(max(moveSpeed - rotateSpeed, -1), 1);
	double rightSpeed = min(max(moveSpeed + rotateSpeed, -1), 1);
	
	backLeftVic.Set(-leftSpeed);
	frontLeftVic.Set(-leftSpeed);
	backRightVic.Set(rightSpeed);
	frontRightVic.Set(rightSpeed);
}

void setAllVics(double speed)
{
	leftBackVic.Set(speed);
	leftFrontVic.Set(speed);
	rightBackVic.Set(-speed);
	rightFrontVic.Set(-speed);
}

void DriveTrain::disable()
{
	setAllVics(0);
}

