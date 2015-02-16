#include "DriveTrain.h"
#include "Constants.h"
#include <WPILib.h>
using namespace std;

DriveTrain::DriveTrain():
	leftFrontVic((uint32_t) PORT_DRIVE_VIC_LEFT_FRONT),
	leftBackVic((uint32_t) PORT_DRIVE_VIC_LEFT_BACK),
	rightBackVic((uint32_t) PORT_DRIVE_VIC_RIGHT_BACK),
	rightFrontVic((uint32_t) PORT_DRIVE_VIC_RIGHT_FRONT),
	
	leftEncoder((uint32_t) PORT_ENCODER_LEFT_A, (uint32_t) PORT_ENCODER_LEFT_B, true),
	rightEncoder((uint32_t) PORT_ENCODER_RIGHT_A, (uint32_t) PORT_ENCODER_RIGHT_B, false),
	
	leftFrontController(LEFT_PROPORTIONAL, LEFT_INTEGRAL, LEFT_DERIVATIVE, &leftEncoder, &leftFrontVic),
	leftBackController(LEFT_PROPORTIONAL, LEFT_INTEGRAL, LEFT_DERIVATIVE, &leftEncoder, &leftBackVic),
	rightFrontController(RIGHT_PROPORTIONAL, RIGHT_INTEGRAL, RIGHT_DERIVATIVE, &rightEncoder, &rightFrontVic),
	rightBackController(RIGHT_PROPORTIONAL, RIGHT_INTEGRAL, RIGHT_DERIVATIVE, &rightEncoder, &rightBackVic)
	{
		setAllVics(0.0);

		/** Sets the encoder distance per pulse **/
		leftEncoder.SetDistancePerPulse(LEFT_DPP);
		rightEncoder.SetDistancePerPulse(RIGHT_DPP);

		/** Starts encoders **/
		leftEncoder.Start();
		rightEncoder.Start();
	}

void DriveTrain::init()
{
	leftEncoder.Reset();
	rightEncoder.Reset();
	
	leftEncoder.Start();
	rightEncoder.Start();
	
	setAllVics(0);


	leftFrontController.SetInputRange(-9999, 9999);
	rightFrontController.SetInputRange(-9999, 9999);
	leftBackController.SetInputRange(-9999, 9999);
	rightBackController.SetInputRange(-9999, 9999);
}

void DriveTrain::update()
{
	double leftSpeed = min(max(moveSpeed - rotateSpeed, -1.0), 1.0);
	double rightSpeed = min(max(moveSpeed + rotateSpeed, -1.0), 1.0);
	
	if(leftFrontController.IsEnabled() || leftBackController.IsEnabled() || rightFrontController.IsEnabled() || rightBackController.IsEnabled())
	{
		cout << "Left Error: " << leftFrontController.GetError() << endl;
		cout << "Left  Error: " <<  leftBackController.GetError() << endl;
		cout << "Right Error: " << rightFrontController.GetError() << endl;
		cout << "Right Error: " << rightBackController.GetError() << endl;	
	}
	else
	{
		/** Sets victors to target speed **/
		leftBackVic.Set(-leftSpeed);
		leftFrontVic.Set(-leftSpeed);
		rightBackVic.Set(rightSpeed);
		rightFrontVic.Set(rightSpeed);
		std::cout << "this is the newest thingy" << std::endl;
	}
	
	/** Sets the PID controller setpoint to the current location plus a constant times the target speed **/
	leftFrontController.SetSetpoint(leftEncoder.GetDistance() - 50*leftSpeed);
	leftBackController.SetSetpoint(leftEncoder.GetDistance() - 50*leftSpeed);
	rightFrontController.SetSetpoint(rightEncoder.GetDistance() -50*rightSpeed);
	rightBackController.SetSetpoint(rightEncoder.GetDistance() - 50*rightSpeed);
	
//	if(leftEncoder.Get() != 0)
//	{
//		cout << "Left Encoder Value: " << leftEncoder.Get() << endl;
//	}
//	if(rightEncoder.Get() != 0)
//	{
//		cout << "Right Encoder Value: " << rightEncoder.Get() << endl;
//	}
}

void DriveTrain::disable()
{
	setAllVics(0);
	leftEncoder.Reset();
	rightEncoder.Reset();

	leftFrontController.Disable();
	rightFrontController.Disable();
	leftBackController.Disable();
	rightBackController.Disable();
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
	leftBackVic.Set(speed);
	leftFrontVic.Set(speed);
	rightBackVic.Set(-speed);
	rightFrontVic.Set(-speed);
}

void DriveTrain::driveDistance(double distance)
{
	leftEncoder.Reset();
	rightEncoder.Reset();
	
	leftEncoder.Start();
	rightEncoder.Start();
	
	leftFrontController.Enable();
	leftBackController.Enable();
	rightFrontController.Enable();
	rightBackController.Enable();
	
	leftFrontController.SetSetpoint(distance);
	leftBackController.SetSetpoint(distance);
	rightFrontController.SetSetpoint(distance);
	rightBackController.SetSetpoint(distance);
	
	
}
