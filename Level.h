#ifndef LEVEL_H
#define LEVEL_H

#include <Arduboy2.h>
#include "Enums.h"
#include "Player.h"

struct Level {

    int originX=108;
    int originY=18;
    String levelDescription="Hallway of \nthe dead";
    int  worldGrid[10][10] = {   
    {1,1,1,1,1,1,1,1,1,1},
    {1,0,0,0,0,0,0,0,0,1},
    {1,0,1,1,1,0,0,0,0,1},
    {1,0,1,0,1,0,0,0,0,1},
    {1,0,0,0,1,0,0,0,0,1},
    {1,1,1,0,1,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,1},
    {1,0,1,1,0,1,0,1,0,1},
    {1,0,0,1,0,1,0,1,0,1},
    {1,1,1,1,1,1,1,1,1,1}
     };

     int xDim = 10;
     int yDim = 10;

  // Level(){
  //    row=8;
  //    col=4;
  //    myHero = new Player(row, col); 
  //   // myObjects.add(new Object(3, 3, 'P'));
  //    //myObjects.add(new Object(4, 6, 'P'));
  //   // myEnemies.add(new Stalker(2, 6));
  // };
  


};

#endif
