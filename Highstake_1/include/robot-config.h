using namespace vex;

extern brain Brain;



// VEXcode devices
extern controller Controller1;
extern drivetrain Drivetrain;
extern motor lift;
extern motor clamp;
extern digital_out  sorter;
extern vision cam1;
using signature = vision::signature;




/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );