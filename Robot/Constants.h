#define PORT_DRIVE_VIC_LEFT_FRONT 5
#define PORT_DRIVE_VIC_LEFT_BACK 6
#define PORT_DRIVE_VIC_RIGHT_FRONT 1
#define PORT_DRIVE_VIC_RIGHT_BACK 2

#define PORT_SPEED_CONTROLLER 1
#define PORT_TURN_CONTROLLER 2

#define PORT_ENCODER_RIGHT_A 1
#define PORT_ENCODER_RIGHT_B 2
#define PORT_ENCODER_LEFT_A 5
#define PORT_ENCODER_LEFT_B 6

/** PID values currently arbitrarily assigned. Better values determined through testing **/

/** The proportional constant used in PID control **/
#define PROPORTIONAL 0.1
/** The integral constant used in PID control **/
#define INTEGRAL 0.1
/** The derivative constant used in PID control **/
#define DERIVATIVE 0.1

#define LEFT_DPP 0.08220549667
#define RIGHT_DPP 0.07995890167

#define TIME_CONSTANT = 0.1;

#define DISTANCE_PER_ROT 2*atan(1)*4
