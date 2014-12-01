#include <WPILib.h>
#include "HumanController.h"
#include "DriveTrain.h"

HumanController::HumanController(Robot *robot):
	movementController((uint32_t) PORT_SPEED_CONTROLLER),
	rotationController((uint32_t) PORT_TURN_CONTROLLER)
{
	this->robot = robot;
}

double HumanController::getRotation()
{
	return rotationController.GetX();
}

double HumanController::getMovement()
{
	return movementController.GetY();
}

void HumanController::update()
{
	robot->getDriveTrain().setMovement(this->getMovement());
	robot->getDriveTrain().setRotation(this->getRotation());
}
