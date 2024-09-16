#include "vex.h"
#include "macro.h"


// this are the class that can be called n the autonomous program in  the 
void red_side_right()
{
  Drivetrain.driveFor(-1341.64,mm);
  //on intake
  Drivetrain.turnFor(45,degrees);
  Drivetrain.driveFor(1200,mm);

}

void red_side_middle()
{
  Drivetrain.driveFor(-1341.64,mm);
  Drivetrain.turnFor(45,degrees);
  Drivetrain.driveFor(848.53,mm);
  Drivetrain.turnFor(45,degrees);
  Drivetrain.driveFor(600,mm);
  Drivetrain.turnFor(45,degrees);



}


void blue_side_right()
{
   Drivetrain.driveFor(-1341.64,mm);
   Drivetrain.turnFor(-45,degrees);
   Drivetrain.driveFor(1200,mm);



}

void blue_side_middle()
{
   Drivetrain.driveFor(-1341.64,mm);
   Drivetrain.turnFor(-45,degrees);
   Drivetrain.driveFor(848.53,mm);
   Drivetrain.turnFor(-45,degrees);
   Drivetrain.driveFor(600,mm);
   Drivetrain.turnFor(90,degrees);
   Drivetrain.driveFor(600,mm);




}



void drivetrain_test()
{
  Drivetrain.setDriveVelocity(100, percent);
  Drivetrain.driveFor(1800, mm);
  Drivetrain.setStopping(brake);
  wait(500,msec);
  Drivetrain.turnFor(-360, degrees);
  wait(500,msec);
  Drivetrain.setStopping(brake);
  Drivetrain.turnFor(360, degrees);
  
  Drivetrain.driveFor(-1800, mm);

 
  sorter_(true,1);
  lift_at_level(2,true);

  
} 