#include "vex.h"
#include "macro.h"


// this are the class that can be called n the autonomous program in  the 
void red_side_right()
{}

void red_side_middle()
{}

void red_side_left()
{}

void blue_side_right()
{}

void blue_side_middle()
{}

void blue_side_left()
{}

void drivetrain_test()
{
  Drivetrain.driveFor(600, mm);
  wait(500,msec);
  Drivetrain.turnFor(-90, degrees);
  wait(500,msec);
  
  Drivetrain.turnFor(90, degrees);
  Drivetrain.driveFor(-600, mm);

  Drivetrain.setDriveVelocity(90, percent);
  sorter_(true,1);
  lift_at_level(2,true);

  
}