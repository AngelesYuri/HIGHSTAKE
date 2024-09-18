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
 /* Drivetrain.setDriveVelocity(100, percent);
  Drivetrain.driveFor(1800, mm);
  Drivetrain.setStopping(brake);
  wait(500,msec);
  Drivetrain.turnFor(-360, degrees);
  wait(500,msec);
  Drivetrain.setStopping(brake);
  Drivetrain.turnFor(360, degrees);
  */
  Drivetrain.setDriveVelocity(100, percent);
  Drivetrain.driveFor(100, inches);
  Drivetrain.setStopping(brake);
  wait(1000,msec);
  Drivetrain.driveFor(-50,inches);
  Drivetrain.setStopping(coast);
  wait(1000,msec);
  Drivetrain.turnFor(180,degrees);
  Drivetrain.setStopping(coast);
  wait(1000,msec);

  Drivetrain.driveFor(50,inches);
  Drivetrain.setStopping(coast);
  Drivetrain.turnFor(180,degrees);
  Drivetrain.setStopping(coast);  



  
} 