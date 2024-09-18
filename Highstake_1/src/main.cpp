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
int  autonomousCurrent = 0;
bool autonomousStarted  = false;

bool dunksSwitch = false;

int liftlevel= 0;
bool switchlift = false;

int sorterColor = 0; //0 for red ,1 for blue
bool sorterCam =false;


void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
  while (autonomousStarted== false)
  {
    Brain.Screen.clearLine(); //shows the current autonomous in the screen
    switch (autonomousCurrent)
    {
      case 0:
      //display in  the screen
       Brain.Screen.print("drivetrain_test"); 
       break;
       case 1:
      //display in  the screen
       Brain.Screen.print("red_side_right"); 
       break;
       case 2:
      //display in  the screen
       Brain.Screen.print("red_side_middle"); 
       break;
        case 3:
      //display in  the screen
       Brain.Screen.print("blue_side_right"); 
       break;
        case 4:
      //display in  the screen
       Brain.Screen.print("blue_side_middle"); 
       break;
        
      
      
      
      
    }

    if(Brain.Screen.pressing() ) //change the current autonomous 
    {
      autonomousCurrent++;
      if(autonomousCurrent ==4) //4 is he limit of the autonmous side /and is reset 
      {
        autonomousCurrent =0;

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

    autonomousStarted = true;
    switch(autonomousCurrent){
      case 0:
           drivetrain_test();
           break;
      case 1:
           red_side_right();
           break;
      case 2:
           red_side_middle();
           break;
      case 3:
           blue_side_right();
           break; 
      case 4:
           blue_side_middle();
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
      sorterColor = 1;
      sorterCam = true;
     }  
     

   
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
