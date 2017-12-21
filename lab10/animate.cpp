//Ana Lamberto
//animate.cpp
//Purpose: Looney Tunes
#include <unistd.h>
#include "gfx.h"
#include <iostream>
#include <cmath>
using namespace std;

void duck();
void pig();
void circTrace(int);

int main(){

        char choice;
        cout << "Would you like Daffy Duck (d) or Porky Pig (p): ";
        cin >> choice;

        int wd = 600, ht = 600;         // window width and height
        int rad = 40;                   // circle's starting center, and its radius
        int pausetime = 10000;          // pause time
        char c = 0;                     // key that is pressed

        gfx_open(wd, ht, "My window");  // Open a new window for drawing.
        gfx_color(0,0,255);
        switch(choice){
                case 'p':
                        while(c != 'q') {
                                pig();
                                gfx_text(230, 400, "Th-Th-Th-That's all folks!");                
                                circTrace(rad);
                                gfx_flush();
                                if(gfx_event_waiting()) {
                                        c = gfx_wait();
                                        if(c == 1){
                                                gfx_color(255, 255, 255);
                                                gfx_text(gfx_xpos(), gfx_ypos(), "Looney Tunes");
                                        }
                                }
                        }
                        break;
                case 'd':
                        while(c != 'q') {
                                duck();
                                gfx_text(250, 400, "That's all folks!");
                                circTrace(rad);
                                gfx_flush();
                                if(gfx_event_waiting()){
                                        c = gfx_wait();
                                        if(c == 1){
                                                gfx_color(255, 255, 255);
                                                gfx_text(gfx_xpos(), gfx_ypos(), "Looney Tunes");
                                        }
                                }
                        }
                        break;
                default:
                        cout << "Please choose one of the two options." << endl;
                        cout << "Would you like Daffy Duck (d) or Porky Pig (p): ";
                        cin >> choice;

        }
        return 0;
}

void duck(){
        gfx_color(96, 96, 95); //gray
        gfx_circle(300, 300, 20); //head
        gfx_line(300, 280, 300, 270); //hair
        gfx_line(300, 280, 303, 275);
        gfx_line(300, 280, 297, 275);
        gfx_color(255, 148, 10); //orange
        gfx_line(285, 300, 260, 310); //beak
        gfx_line(260, 310, 290, 312);
        gfx_color(255,255,255); //white
        gfx_circle(295, 295, 5); //eyes
        gfx_circle(305, 295, 5);
        gfx_line(298, 320, 298, 330);
        gfx_line(302, 320, 302, 330);
}

void pig(){
        gfx_color(255, 147, 251); //pink        
        gfx_circle(300, 300, 20); //head
        gfx_line(300, 285, 287, 265); //ears
        gfx_line(287, 265, 280, 291);
        gfx_line(300, 285, 313, 265);
        gfx_line(313, 265, 320, 291);
        gfx_circle(300, 310, 7); //nose
        gfx_line(298, 306, 298, 312);
        gfx_line(302, 306, 302, 312);
        gfx_color(255, 255, 255); //white
        gfx_circle(295, 295, 4); //eyes
        gfx_circle(305, 295, 4);
}

void circTrace(int r){
        gfx_color(255, 0, 0);
        float xPrev = 299, yPrev = 200; //inital point
        for(float i = 0; i <= 360; i = i + .1){ //loop through circle
                gfx_line(xPrev, yPrev, xPrev + 299*cos(i), yPrev + 299*sin(i));
                gfx_flush();
                xPrev = xPrev + 12*cos(i); //get jagged line effect
                yPrev = yPrev + 12*sin(i); //get jagged line effect
                usleep(2000); //pause between drawing lines
        }
}
