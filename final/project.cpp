//Ana Lamberto and Angie Franco
//final project - project.cpp
//BrickBreaker

#include "gfxnew.h"
#include <iostream>
#include <unistd.h>
#include <vector>
#include <cstdlib>
using namespace std;

void buildBlock(int, int, int, int, int);
void setup(int, int, vector<int>&, vector<int>&);
void checkCollision(int, int, int, int, int, float&, float&, int, vector<int>&, vector<int>&);
void checkCollisionPaddle(int, int, int, int&, float&, float&, int);
void drawBlocks(vector<int>, vector<int>);
void move_paddle(int&, int&);
void lives(int);
void reset(int&, int, int&, int&, float&, float&);
void changeXVel(float&);



int main(){
  srand(time(NULL)); //for random colors
  vector<int> posX; //x posiitons
  vector<int> posY; //y posiitons
  int width = 600, height = 600; //sccreen size
  int xc = 300, yc = 535, r = 15; //starting positions
  float vX = 1, vY = 1; //starting velocities
  int deltat = 15000;
  gfx_open(width, height, "Breakout");
  char c; //for event changes
  bool stop = false, loop = true; //control loops
  int event, numLives = 4; //control loops
  int prevX = 270;
  int newX;


  setup(5, 10, posX, posY); //setup initial game
  while(!stop){ //waits for mouse click to start game
    c = gfx_wait();
    if(c == 1){
      gfx_color(0, 0, 0);
      gfx_fill_circle(300, 535, r); //turn initial circle black
      buildBlock(270, 550, 60, 15, 0); //turn initial paddle black
      xc = xc + vX; // increment x animation
      yc = yc - vY; // increment y animation
      changeXVel(vX);
      stop = true; //end start loop
    }
  }

  while(loop){
    gfx_color(255, 255, 255);
    if((posX.size() == 0) && (posY.size() == 0)){ //check to see if there are any blocks left
      gfx_clear();
      gfx_text(300, 300, "You Win!");
      usleep(1000000);
      break;
    }

    if(xc <= r){ //check left wall collision
      vX = -1 * vX;
      xc = r + 1;
    }
    else if(xc >= width - r){ //right wall collision
      vX = -1 * vX;
      xc = width - r - 1;
    }
    else if(yc <= r){ //check top wall collision
      vY = -1 * vY;
      yc = r + 1;
    }
    else if(yc >= height - r){ //bottom wall collision
      reset(prevX, 550, xc, yc, vX, vY); //reset board
      lives(--numLives); //if hits bottom take away a life
    }
    gfx_fill_circle(xc, yc, r); //make ball
    for(int i = 0; i < posX.size(); i++){
      checkCollision(posX[i], posY[i], xc, yc, r, vX, vY, i, posX, posY); //check for collision with every block
    }
    checkCollisionPaddle(newX, 550, xc, yc, vY, vX, r);
    gfx_color(0, 0, 0);
    gfx_fill_circle(xc, yc, r); //color over ball with black
    xc = xc + vX * deltat * .0001; // increment x animation
    yc = yc - vY * deltat * .0001; // increment y animation


    if((gfx_event_waiting()) != 0){ //check to quit game
      event = gfx_event_waiting();
      c = gfx_wait(); //controls loop
        if(c == 'Q'){ //move left
          newX = prevX - 10;
          move_paddle(prevX, newX);
        }
        if(c == 'S'){ //move right
          newX= prevX + 10;
          move_paddle(prevX, newX);
        }
        if(c == 'r') //refresh blocks
          drawBlocks(posX, posY);
    }
    if((c == 'q') || (numLives <= 0)){ //check to end loop
      gfx_clear();
      gfx_color(255,255,255);
      gfx_text(300, 300, "Game Over"); //game over
      gfx_flush();
      usleep(1000000);
      loop = false;
    }
  }

  return 0;
}

void buildBlock(int x1, int y1, int x2, int y2, int color){ //make filled block with certain color
  if(color == 1) //red block
    gfx_color(250, 0, 0);
  else if(color == 2) //green block
    gfx_color(0, 250, 0);
  else if(color == 3)//blue block
    gfx_color(0, 0, 250);
  else //whatever is passed to function
    gfx_color(color, color, color);

  gfx_fill_rectangle(x1, y1, x2, y2);
  gfx_flush();
}

void setup(int x, int y, vector<int>& posX, vector<int>& posY){ //setup screen
  int color;
  for(int r = 60; r < 540; r = r + 80){ //draw all the blocks in row/col form
    for(int c = 100; c < 300; c = c + 40){
      color = rand() % 3 + 1; //choose random color between 1 and 3 for blocks
      buildBlock(r, c, 60, 15, color);
      posX.push_back(r); //save positions of blocks
      posY.push_back(c);
    }
  }
  buildBlock(270, 550, 60, 15, 1); //build block at the bottom of screen
  gfx_color(255, 255, 255);
  gfx_fill_circle(300, 535, 15); //draw circle to move
  lives(4); //set up lives in top left screen
}


void checkCollision(int x1, int y1, int x2, int y2, int r, float &velX, float &velY, int index, vector<int>& posX, vector<int>& posY){
if(((y1 + 18) >= (y2)) && (y1 - 3 <= y2) && ((x1 + 63 >= x2) && (x1 - 3 <= x2))){ // bottom block of collision
    velY = -1 * velY;
    buildBlock(posX[index], posY[index], 60, 15, 0); //turn block black
    posX.erase(posX.begin() + index); //take out block from vector so doesn't cause collision
    posY.erase(posY.begin() + index);
  }
}

void checkCollisionPaddle(int px1, int py1, int cx2, int& cy2, float &velY, float &velX, int r){ //check if hits paddle
  if((cx2 + r >= px1) && (cx2 - r <= (px1 + 60)) && (py1 <= (cy2 + r)) && (py1 + 15 >= (cy2 + r))){ //if ball hits paddle
    velY = -1 * velY * 1.15; //increase velocity and change direction every time it hits paddle
    changeXVel(velX);
  }
}

void lives(int numLives){
  gfx_color(0, 0, 0);
  for(int j = 0; j < 3; j++) // cover all old circles with black
    gfx_fill_circle(10 + 15*j, 10, 5);

  gfx_color(255, 255, 255);
  for(int i = 0; i < (numLives - 1); i++){ //draw remaining lives at top of the screen
    gfx_fill_circle(10 + 15*i, 10, 5);
  }
}

void move_paddle(int &x1,int &x2){
  buildBlock(x1, 550, 60, 15, 0); //black block that covers old position
  buildBlock(x2, 550, 60, 15, 1); //red block in new position
  x1 = x2; //make new position the old position for next block
}

void drawBlocks(vector<int> posX, vector<int> posY){
  int color;
  for(int i = 0; i < posX.size(); i++){ //build remaining blocks
    color = rand() % 3 + 1; //pick random color 1, 2, 3 (red, green, blue)
    buildBlock(posX[i], posY[i], 60, 15, color);
  }
}

void reset(int &x1, int y1, int &x2, int &y2, float &vX, float &vY){
  gfx_color(0, 0, 0);
  gfx_fill_circle(x2, y2, 15); //fill circle wherever it is with black
  buildBlock(x1, y1, 60, 15, 0); //fill paddle wherever it is with black
  //reset positions of ball and paddle to center
  x1 = 270; //paddle orig position
y1 = 550;
  x2 = 300; //ball center orig position
  y2 = 530;
  gfx_color(255, 0, 0);
  buildBlock(270, 550, 60, 15, 1); //build block at the bottom of screen
  gfx_color(255, 255, 255);
  gfx_fill_circle(300, 530, 15); //draw circle to move
  vY = 1;
  vX = 1; //reset slow X velocity
  changeXVel(vX); //randomize X velocity
}

void changeXVel(float &vX){
  float change1 = rand() % 2; //random change of x direction
  float change2 = rand() % 2 + 1; //decides if ball moves left or right
  if(change2 == 1) //force ball to change angle toward the left
    vX = -1 * (vX + change1);
  else if(change2 == 2) //force ball to change angle toward the right
    vX = vX + change1;
}
