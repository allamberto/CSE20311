//Ana Lamberto
//bounce.cpp
//Purpose - circle that bounces around screen

#include <unistd.h>
#include "gfx.h"
#include <cstdlib>
#include <time.h>

int main(){
        int wd = 600, ht = 500;         // window width and height
        int xc = 50, yc = 50, r = 20;           //starting position
        int vX = 1, vY = 1;             //starting velocity
        int deltat = 10000;
        char c = 0; //key pressed
        srand(time(NULL)); //random time

        gfx_open(wd, ht, "My window");   // Open a new window for drawing
        gfx_color(255,255,0);

        while(c != 'q') {                // keep going until a 'q' is pressed
                gfx_clear();
                if(xc <= r){ //check left and right wall collision
                        vX = -1 * vX;
                        xc = r + 1;
                }
                else if(xc >= wd - r){
                        vX = -1 * vX;
                        xc = wd - r - 1;
                }
                else if(yc <= r){ //check top and bottom wall collision
                        vY = -1 * vY;
                        yc = r + 1;
                }
                else if(yc >= ht - r)  {
                        vY = -1 * vY;
                        yc = ht - r - 1;
                }
                gfx_circle(xc, yc, r);
                gfx_flush();
                usleep(deltat);
                xc = xc + vX * deltat * .0001;             // increment x animation
                yc = yc + vY * deltat * .0001;             // increment y animation
                if(gfx_event_waiting()){
                        c = gfx_wait();
                        if(c == 1){
                                xc = gfx_xpos();
                                yc = gfx_ypos();
                                vX = rand() % 4 + 1; //velocity between 1 and 2
                                vY = rand() % 4 + 1; //keep v constant
                        }
                 }
        }
}
