#include <WPILib.h>

class PIDRobot : public IterativeRobot
{
	private:
		Robot robot;
		HumanController humanController;
		
	public:
		EBBot();
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
	
}

void PIDRobot::AutonomousInit()
{
	
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
