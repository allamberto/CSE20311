//Ana Luisa Lamberto
//symbol.cpp
//Purpose: Print symbols to screen based on user keyboard input

#include <unistd.h>
#include "gfx.h"
#include <cmath>

void square();
void triangle();
void circle();
void polygon(int side);

int main(){
        int wd = 500;  // window width
        int ht = 400;  // window height 
        int xm, ym;
        char c;
        bool play = true; //flag

  // Open a new window for drawing.
        gfx_open(wd, ht, "My window");

        c = gfx_wait();
        while(play) {
                switch(c){
                        case 1:
                                square();
                                break;
                        case 't':
                                triangle();
                                break;
                        case 'c':
                                circle();
                                break;
                        case 51: case 52: case 53: case 54: case 55: case 56: case 57:
                                polygon(c);
                                break;
                        case 27:
                                gfx_clear();
                                break;
                        case 'q':
                                play = false;
                                break;
                }
                gfx_flush();
                c = gfx_wait();
        }

        return 0;
}

void square(){
        gfx_color(0, 0, 225);
        gfx_line(gfx_xpos() - 13, gfx_ypos() - 13, gfx_xpos() + 13, gfx_ypos() - 13); //top line
        gfx_line(gfx_xpos() - 13, gfx_ypos() - 13, gfx_xpos() - 13, gfx_ypos() + 13); //left line
        gfx_line(gfx_xpos() + 13, gfx_ypos() - 13, gfx_xpos() + 13, gfx_ypos() + 13); //right line
        gfx_line(gfx_xpos() - 13, gfx_ypos() + 13, gfx_xpos() + 13, gfx_ypos() + 13); //bottom line
}

void circle(){
        gfx_color(255, 255, 225); //blue
        gfx_circle(gfx_xpos(), gfx_ypos(), 13);
}

void triangle(){
        gfx_color(0, 255, 0); //green
        gfx_line(gfx_xpos(), gfx_ypos() - 11, gfx_xpos() - 12.5, gfx_ypos() + 11); //left
        gfx_line(gfx_xpos(), gfx_ypos() - 11, gfx_xpos() + 12.5, gfx_ypos() + 11); //right
        gfx_line(gfx_xpos() - 12.5, gfx_ypos() + 11, gfx_xpos() + 12.5, gfx_ypos() + 11); //bottom
}

void polygon(int r){
        gfx_color(181, 60, 209);
        float theta = (360/(r - 48))*(3.14/180); //angle in radians
        float xPrev = gfx_xpos() + 12; //first position
        float yPrev = gfx_ypos();
        for(float i = theta; i <= (2 * 3.141); i = i + theta){ //loop through a circle
                gfx_line(xPrev, yPrev, gfx_xpos() + 12*cos(i), gfx_ypos() + 12*sin(i)); //go from previous position to new position
                xPrev = gfx_xpos() + 12*cos(i); //save position just find for next iteration of loop
                yPrev = gfx_ypos() + 12*sin(i);
        }
}

