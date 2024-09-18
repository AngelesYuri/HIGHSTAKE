/*vex-vision-config:begin*/
#include "vex.h"
vex::vision::signature RED_ = vex::vision::signature (1, -1, 5057, 2528, -405, 1445, 520, 0.9, 0);
vex::vision::signature BLUE_ = vex::vision::signature (2, -4369, -1237, -2803, 3641, 12137, 7889, 0.8, 0);
vex::vision::signature SIG_3 = vex::vision::signature (3, 0, 0, 0, 0, 0, 0, 2.5, 0);
vex::vision::signature SIG_4 = vex::vision::signature (4, 0, 0, 0, 0, 0, 0, 2.5, 0);
vex::vision::signature SIG_5 = vex::vision::signature (5, 0, 0, 0, 0, 0, 0, 2.5, 0);
vex::vision::signature SIG_6 = vex::vision::signature (6, 0, 0, 0, 0, 0, 0, 2.5, 0);
vex::vision::signature SIG_7 = vex::vision::signature (7, 0, 0, 0, 0, 0, 0, 2.5, 0);
vex::vision cam1 = vex::vision (vex::PORT21, 50, RED_, BLUE_, SIG_3, SIG_4, SIG_5, SIG_6, SIG_7);
/*vex-vision-config:end*/