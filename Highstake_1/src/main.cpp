/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// ---- END VEXCODE CONFIGURED DEVICES ----
#include "vex.h"
#include "auton.h"
#include "macro.h"




using namespace vex;

// A global instance of competition
competition Competition;

// define your global instances of motors and other devices here

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/
int  autonCurrent = 0;
bool autoStarted  = false;

bool dunks_switch = false;

int lift_level= 0;
bool switch_lift = false;

int sorter_color = 0; //0 for red ,1 for blue
bool sorter_cam =false;


void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
  while (autoStarted== false)
  {
    Brain.Screen.clearLine(); 
    switch (autonCurrent)
    {
      case 0:
      //display in  the screen
       Brain.Screen.print("drivetrain_test"); 
       break;
       case 1:
      //display in  the screen
       Brain.Screen.print("d_test"); 
       break;
       case 2:
      //display in  the screen
       Brain.Screen.print("C_test"); 
       break;
      
    }

    if(Brain.Screen.pressing() )
    {
      autonCurrent++;
      if(autonCurrent == 8)
      {
        autonCurrent =0;

      }
    }

    task::sleep(300);
  }
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void autonomous(void) {

    autoStarted = true;
    switch(autonCurrent){
      case 0:
           drivetrain_test();
           break;
      case 1:
           red_side_left();
           break;
      case 2:
           red_side_left();
           break;
      case 3:
           red_side_left();
           break; 
      case 4:
           blue_side_left();
           break;
      case 5:
           blue_side_right();
           break;
      case 6:
           blue_side_middle();
           break;
      case 7:
           break;
    }

}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void usercontrol(void) {
  // User control code here, inside the loop
  while (1) {
     
     //dunk(dunks_switch);
     //lift_at_level(0,switch_lift);
     while(Controller1.ButtonA.pressing())
     {
      sorter_color = 1;
      sorter_cam = true;
     }  
     

    lift_at_level(lift_level,switch_lift);
    sorter_(sorter_cam,sorter_color);
    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }
  
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
