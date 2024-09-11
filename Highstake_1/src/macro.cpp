#include "vex.h"
#include "Vision.h"

int centerFOV = 158;//is use for centering of vision sesnor
int offsetX = 15; //

// set all of this as a task later
// all of  the classses here are running on the background at consntant unless ,it said not 
void dunk(bool dunks_switch)
{
  // run motor until the vision fits the width and the length needed for the donut to stay at the end
   while(dunks_switch == true)
   {
     cam1.takeSnapshot(BLUE_);
     if(cam1.largestObject.exists){
          if(cam1.largestObject.centerX >centerFOV + offsetX)
          {
            clamp.spin(forward);
          }
          else if(cam1.largestObject.centerX < centerFOV - offsetX)
          {
            clamp.spin(reverse);
          }
          else {clamp.stop();}
     }
   }
     
     //motor run until objject is 0,0 
     // if object is above 0,0 run backward
     
    wait(5,msec);
 }



void lift_at_level(int level,bool lift_switch)
{
   // level change this later if needed 
   // 1 ==  180
   // 2 ==  360
   int degree = 0;
   switch(level)
   {
     case 0:
         degree = 0;
         break;
     case 1:
         degree = 180;
         break;
     case 2:
         degree = 360;
         break;    

   }
  
   while (lift_switch == true)
   {
     // set motor level to angle of "LEVEL"  of the lift mecanissm
     lift.setPosition(degree,degrees);
     wait(5,msec);

   }
  
}

  

void sorter_(bool sorter_switch,int sorter_color )
{ 
    // sorter switch for it to make the class work
    // while sorter color is 1 == blue, 2 == red
   
    while(sorter_switch == true)
    {
      while(sorter_color == 1)
      {
       cam1.takeSnapshot(RED_);
       if(cam1.objectCount > 0 )  { sorter.set(true);  }
       else{sorter.set(false); 

      }
      while(sorter_color == 0)
      {
        cam1.takeSnapshot(BLUE_);
       if(cam1.objectCount > 0 )  { sorter.set(true);  }
       else{sorter.set(false); }
      }
      }
    }
}

    
    
    
