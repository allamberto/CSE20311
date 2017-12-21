//Ana Luisa Lamberto
//Lab 11 - Fractals.cpp

#include "gfx.h"
#include <iostream>
#include <cmath>
using namespace std;


void sierpinski(int, int, int, int, int, int);
void drawTriangle(int, int, int, int, int, int);
void shrinkSquare(int, int, int, int, int, int, int, int);
void drawRectangle(int, int, int, int, int, int, int, int); //draw square from corner points
void drawSpiralSquare(int, int, float, float);
void drawSquare_Center(int, int, int); //draw square from center
void drawCircLace(int, int, int);
void drawSnowflake(int, int, int);
void drawTree(int, int, float, float);
void drawFern(int, int, float, float);
void drawSpirals(float, float, float);

int main(){

        int wd = 600, ht = 600, mrg, rad = 200;
        gfx_open(wd, ht, "Fractals");
        gfx_color(255, 255, 255);

        char c;
        while(c != 'q'){
                c = gfx_wait();

                switch(c){
                        case '1':
                                gfx_clear();
                                mrg = 20;
                                sierpinski(mrg, mrg, wd - mrg, mrg, wd/2, ht - mrg);
                                break;
                        case '2':
                                gfx_clear();
                                mrg = 150;
                                shrinkSquare(mrg, mrg, wd - mrg, mrg, wd - mrg, ht - mrg, mrg, ht - mrg);
        break;
                        case '3':
        gfx_clear();
                                drawSpiralSquare(wd/2, wd/2, 1, 0);
        break;
                        case '4':
        gfx_clear();
                                drawCircLace(wd*.5, ht*.5, rad);
        break;
                        case '5':
        gfx_clear();
                                drawSnowflake(wd/2, ht/2, wd/3);
                                break;                  
                        case '6':
        gfx_clear();    
                                drawTree(wd/2, ht - 10, ht/4, (3.14/2)); //start at -y axis
        break;                  
                        case '7':
        gfx_clear();    
                                drawFern(wd/2, ht, ht/2, (-3.14/2)); //initial stem values
        break;                  
                        case '8':
        gfx_clear();    
                                drawSpirals(wd/2, ht/2, 12*3.14);
        break;                  
                        default:
                                gfx_clear();
                }               
        }       
        
        return 0;
}       

void sierpinski(int x1, int y1, int x2, int y2, int x3, int y3){
        if(abs(x2-x1) < 5) return; //base case
        drawTriangle(x1, y1, x2, y2, x3, y3); //draw triangle
        sierpinski(x1, y1, (x1+x2)/2, (y1+y2)/2, (x1+x3)/2, (y1+y3)/2); //recursive calls
  sierpinski((x1+x2)/2, (y1+y2)/2, x2, y2, (x2+x3)/2, (y2+y3)/2);
  sierpinski((x1+x3)/2, (y1+y3)/2, (x2+x3)/2, (y2+y3)/2, x3, y3);
}

void drawTriangle(int x1, int y1, int x2, int y2, int x3, int y3){
        gfx_line(x1, y1, x2, y2);
        gfx_line(x1, y1, x3, y3);
        gfx_line(x2, y2, x3, y3);
}

void shrinkSquare(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4){
        if(abs(x2-x1) < 2) return; //base case
        drawRectangle(x1, y1, x2, y2, x3, y3, x4, y4); //draw rectangle

 double len = (x2-x1)/4.5;  // make each length half the length of the squares in next step
 //recursive calls for each corner
 shrinkSquare(x1-len, y1-len, x1+len, y1-len, x1+len, y1+len, x1-len, y1+len);  // top left corner
 shrinkSquare(x2-len, y2-len, x2+len, y2-len, x2+len, y2+len, x2-len, y2+len);  // top right corner
 shrinkSquare(x3-len, y3-len, x3+len, y3-len, x3+len, y3+len, x3-len, y3+len);  // bottom left corner
 shrinkSquare(x4-len, y4-len, x4+len, y4-len, x4+len, y4+len, x4-len, y4+len);  // bottom right corner
}

void drawRectangle(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4){
        gfx_line(x1, y1, x2, y2);
        gfx_line(x2, y2, x3, y3);
        gfx_line(x3, y3, x4, y4);
        gfx_line(x4, y4, x1, y1);
        gfx_flush();
}

void drawSpiralSquare(int x1, int y1, float rad, float theta){
        if(rad > 200) return; //base case
        drawSquare_Center(x1, y1, rad); //draw square from center
        drawSpiralSquare(x1 + 2*rad*cos(theta), y1 - 2*rad*sin(theta), rad*1.2, theta + (3.14/3));
}

void drawSquare_Center(int x, int y, int len){
        gfx_line(x - (len/2), y - (len/2), x + (len/2), y - (len/2));
  gfx_line(x + (len/2), y - (len/2), x + (len/2), y + (len/2));
  gfx_line(x + (len/2), y + (len/2), x - (len/2), y + (len/2));
  gfx_line(x - (len/2), y + (len/2), x - (len/2), y - (len/2));
}

void drawTree(int x1, int y1, float len, float theta){
  if(len < 3) return; //base case

        gfx_line(x1, y1, x1 + len*cos(theta), y1 - len*sin(theta)); //initial branch

        //resursive calls

        drawTree(x1 + len*cos(theta), y1 - len*sin(theta), len * .7, theta + 3.14/6);
        drawTree(x1 + len*cos(theta), y1 - len*sin(theta), len * .7, theta - 3.14/6);
}

void drawCircLace(int x1, int y1, int rad){
        if(rad < 2) return; //base case
        float theta = 0; //for circular motion
        int x2, y2, rad2; //for recursive function
        gfx_circle(x1, y1, rad);
        gfx_flush();

        for(int i = 0; i < 6; i++){ //create circle with 6 smaller circles
                x2 = x1 + rad * cos(theta);
                y2 = y1 + rad *sin(theta);
                rad2 = rad * (1./3); //third of previous radius each time called
                drawCircLace(x2, y2, rad2); //recursive call
                theta = theta + (3.14/3); //update theta
        }
}

void drawSnowflake(int x, int y, int len){
        if(len < 3) return; //base case

        gfx_line(x, y, x + (len*cos(0*2*3.14/5)), y + (len*sin(0*2*3.14/5)));
        gfx_line(x, y, x + (len*cos(1*2*3.14/5)), y + (len*sin(1*2*3.14/5)));
        gfx_line(x, y, x + (len*cos(2*2*3.14/5)), y + (len*sin(2*2*3.14/5)));
        gfx_line(x, y, x + (len*cos(3*2*3.14/5)), y + (len*sin(3*2*3.14/5)));
        gfx_line(x, y, x + (len*cos(4*2*3.14/5)), y + (len*sin(4*2*3.14/5)));

        drawSnowflake(x + (len*cos(0*2*3.14/5)), y + (len*sin(0*2*3.14/5)), len*.4);
        drawSnowflake(x + (len*cos(1*2*3.14/5)), y + (len*sin(1*2*3.14/5)), len*.4);
        drawSnowflake(x + (len*cos(2*2*3.14/5)), y + (len*sin(2*2*3.14/5)), len*.4);
        drawSnowflake(x + (len*cos(3*2*3.14/5)), y + (len*sin(3*2*3.14/5)), len*.4);
        drawSnowflake(x + (len*cos(4*2*3.14/5)), y + (len*sin(4*2*3.14/5)), len*.4);

}

void drawFern(int x1, int y1, float len, float theta){
        cout << x1 << " " << y1 << " " << len << " " << theta << endl;
        if(len < 10) return; //base case

        gfx_line(x1, y1, x1 + len*cos(theta), y1 + len*sin(theta)); //first straight line
        for(float i = .4; i <= 1; i = i + .2){ //recursive calls for four branches on each side - used small i to control length of hypotenuse
                drawFern(x1 + len * i * cos(theta), y1 + len * i * sin(theta), len * .4, theta - (3.14/6));
                drawFern(x1 + len * i * cos(theta), y1 + len * i * sin(theta), len * .4, theta + (3.14/6));
        }
}

void drawSpirals(float x, float y, float theta){
        gfx_point(x, y); //middle point
        double radius;
        if(exp(theta/(2*3.14)) < 1) return; //base case

        for(double miniTheta = 0; miniTheta <= theta; miniTheta = miniTheta + (3.14/5)){ // loop for spiral and call recursion on spiral
                radius = exp(miniTheta/(2*3.14)); //update radius
                drawSpirals(x + radius*cos(miniTheta), y - radius*sin(miniTheta), miniTheta - 2*3.14 - 3.14/5); //draw larger spiral around small spiral
        }
}
                                     
        
