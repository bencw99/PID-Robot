#include <WPILib.h>
#include "Robot.h"
#include "HumanController.h"

class PIDRobot : public IterativeRobot
{
	private:
		Robot robot;
		HumanController humanController;

	public:
		PIDRobot();
		void RobotInit();
		void AutonomousInit();
		void AutonomousPeriodic();
		void AutonomousDisabled();
		void DisabledInit();
		void DisabledPeriodic();
		void TeleopInit();
		void TeleopPeriodic();
		void TeleopDisabled();
		void TestInit();
		void TestPeriodic();
};

PIDRobot::PIDRobot():
	robot(),
	humanController(&robot)
{

}

void PIDRobot::RobotInit()
{
	robot.init();
}

void PIDRobot::AutonomousInit()
{
	robot.init();
}

void PIDRobot::AutonomousPeriodic()
{
	robot.update();
}

void PIDRobot::AutonomousDisabled()
{

}

void PIDRobot::DisabledInit()
{
	robot.disable();
}

void PIDRobot::DisabledPeriodic()
{
	robot.disable();
	robot.update();
}

void PIDRobot::TeleopInit()
{
	robot.init();
//	robot.driveDistance(150);
}

void PIDRobot::TeleopPeriodic()
{
	humanController.update();
	robot.update();
}

void PIDRobot::TeleopDisabled()
{
	robot.disable();
	robot.update();
}

void PIDRobot::TestInit()
{

}
void PIDRobot::TestPeriodic()
{

}
START_ROBOT_CLASS(PIDRobot);
