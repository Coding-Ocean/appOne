#include"libOne.h"
void gmain(){
    window(1000, 1000);
    while (notQuit){
        float vx = mathMouseX;
        float mag = vx < 0 ? -vx : vx;
        float nvx = vx / mag;
        clear(200);
        mathAxis(9.1f);
        strokeWeight(10);
        stroke(0);
        mathArrow(0, 0, vx, 0);
        stroke(255, 0, 0);
        mathArrow(0, 0, nvx, 0);


        textSize(50);
        text(vx, 0, 50);
        text(mag, 0, 100);
    }
}
