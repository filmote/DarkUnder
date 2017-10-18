class Vision {
PImage visionBack;
PImage closeWallLeft;
PImage closeWallRight;
PImage midWallLeft;
PImage midWallRight;
PImage farWallLeft;
PImage farWallRight;
PImage closeWallFront;
PImage midWallFront;
PImage farWallFront;
int originX= 3;
int originY= 4;
  
  Vision(){
    visionBack = loadImage("visionBack.gif");
    closeWallLeft = loadImage("closeWallLeft.gif");
    closeWallRight = loadImage("closeWallRight.gif");
    midWallLeft = loadImage("midWallLeft.gif");
    midWallRight = loadImage("midWallRight.gif");
    farWallLeft = loadImage("farWallLeft.gif");
    farWallRight = loadImage("farWallRight.gif");
    closeWallFront = loadImage("closeWallFront.gif");
    midWallFront = loadImage("midWallFront.gif");
    farWallFront = loadImage("farWallFront.gif");
  }
  
  void playerVision (){//draw the walls by checking row and cols ahead of player
    image(visionBack,myVision.originX,myVision.originY);
    //far front wall
    if (row-3>=0){//make sure we don't check row out of bound in the array
      if (myLevel.worldGrid[row-3][col]>0) {
        image(farWallFront,originX,originY);
      }
    }
    //far left wall
    if (row-2>=0){
      if (myLevel.worldGrid[row-2][col-1]>0) {
        image(farWallLeft,originX,originY);
      }
    }
    //far right wall
    if (row-2>=0){
      if (myLevel.worldGrid[row-2][col+1]>0) {
        image(farWallRight,originX,originY);
      }
    }
    //mid front wall
    if (row-2>=0){
      if (myLevel.worldGrid[row-2][col]>0) {
        image(midWallFront,originX,originY);
      }
    }
    //mid left wall
    if (myLevel.worldGrid[row-1][col-1]>0) {
      image(midWallLeft,originX,originY);
    }
    //mid right wall
    if (myLevel.worldGrid[row-1][col+1]>0) {
      image(midWallRight,originX,originY);
    }
    //close front wall
    if (myLevel.worldGrid[row-1][col]>0) {
      image(closeWallFront,originX,originY);
    }
    //close left wall
    if (myLevel.worldGrid[row][col-1]>0) {
      image(closeWallLeft,originX,originY);
    }
    //close right wall
    if (myLevel.worldGrid[row][col+1]>0) {
      image(closeWallRight,originX,originY);
    }
  }
}
