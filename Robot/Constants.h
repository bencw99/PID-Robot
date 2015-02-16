#define PORT_DRIVE_VIC_LEFT_FRONT 0
#define PORT_DRIVE_VIC_LEFT_BACK 1
#define PORT_DRIVE_VIC_RIGHT_FRONT 2
#define PORT_DRIVE_VIC_RIGHT_BACK 3

#define PORT_SPEED_CONTROLLER 1
#define PORT_TURN_CONTROLLER 2

#define PORT_ENCODER_RIGHT_A 3
#define PORT_ENCODER_RIGHT_B 2
#define PORT_ENCODER_LEFT_A 1
#define PORT_ENCODER_LEFT_B 0

/** PID values currently arbitrarily assigned. Better values determined through testing **/

///** The left proportional constant used in PID control **/
//#define LEFT_PROPORTIONAL 0.1
///** The left integral constant used in PID control **/
//#define LEFT_INTEGRAL 0.0
///** The left derivative constant used in PID control **/
//#define LEFT_DERIVATIVE 0.1

///** The right proportional constant used in PID control **/
//#define RIGHT_PROPORTIONAL -0.1
///** The right integral constant used in PID control **/
//#define RIGHT_INTEGRAL -0.0
///** The right derivative constant used in PID control **/
//#define RIGHT_DERIVATIVE -0.1

#define LEFT_PROPORTIONAL .12
#define LEFT_INTEGRAL 0
#define LEFT_DERIVATIVE .1

#define RIGHT_PROPORTIONAL -.12
#define RIGHT_INTEGRAL -0
#define RIGHT_DERIVATIVE -.1

#define RIGHT_DPP 0.018258776354
#define LEFT_DPP 0.012808296080
