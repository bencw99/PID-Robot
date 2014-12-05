#include "DriveTrain.h"
#include "Constants.h"
#include <WPILib.h>

DriveTrain::DriveTrain():
	leftFrontVic((uint32_t) PORT_DRIVE_VIC_LEFT_FRONT),
	leftBackVic((uint32_t) PORT_DRIVE_VIC_LEFT_BACK),
	rightBackVic((uint32_t) PORT_DRIVE_VIC_RIGHT_BACK),
	rightFrontVic((uint32_t) PORT_DRIVE_VIC_RIGHT_FRONT),
	
	leftEncoder((uint32_t) PORT_ENCODER_LEFT_A, (uint32_t) PORT_ENCODER_LEFT_B, true),
	rightEncoder((uint32_t) PORT_ENCODER_RIGHT_A, (uint32_t) PORT_ENCODER_RIGHT_B, false)
{
	setAllVics(0.0);
	
	leftEncoder.SetDistancePerPulse(0.01);
	rightEncoder.SetDistancePerPulse(0.01);
	
	leftEncoder.Start();
	rightEncoder.Start();

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

void DriveTrain::setAllVics(double speed)
{
	leftBackVic.Set(-speed);
	leftFrontVic.Set(-speed);
	rightBackVic.Set(speed);
	rightFrontVic.Set(speed);
}

void DriveTrain::init()
{
	leftEncoder.Reset();
	rightEncoder.Reset();
	
	leftEncoder.Start();
	rightEncoder.Start();
	
	setAllVics(0);
}

void DriveTrain::update()
{
	double leftSpeed = min(max(moveSpeed - rotateSpeed, -1), 1);
	double rightSpeed = min(max(moveSpeed + rotateSpeed, -1), 1);
	
	leftBackVic.Set(-leftSpeed);
	leftFrontVic.Set(-leftSpeed);
	rightBackVic.Set(rightSpeed);
	rightFrontVic.Set(rightSpeed);
	
	cout<< "Left Encoder Value: " + leftEncoder.Get() << endl;
	cout<< "Right Encoder Value: " + rightEncoder.Get() << endl;
	
		
	cout << leftEncoder.GetDistance() << endl;
	cout << rightEncoder.GetDistance() << endl;
}

void DriveTrain::disable()
{
	setAllVics(0);
}

