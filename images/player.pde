class Player {
  color playerColor = color(#FFFFFF);
  int playerSize = TILE_SIZE;
  int playerX;
  int playerY;
  int rowY;
  int colX;
  int originX=109;
  int originY=21;

  Player ( int rowY, int colX) {
    playerX=colX*TILE_SIZE;
    playerY=rowY*TILE_SIZE;
    this.rowY=rowY;
    this.colX=colX;
    pcolX=col;
    prowY=row;
  }  
  void display(){
    fill(#000000);
    noStroke();
    rect(originX,originY, TILE_SIZE, TILE_SIZE);
    fill(#FFFFFF);
    rect(originX+1,originY+1, TILE_SIZE/2, TILE_SIZE/2);
    stroke(0);
  }
  boolean moveLegal (int row, int col) {
    //println("Hero X= "+row+" Hero Y= "+col);
    if (myLevel.worldGrid[row][col]<1) {
      return true;
    } else {
      return false;
    }
  }  
  void movePlayer(char direction){
    switch (direction) {
     case 'U':
     row--;
    if (myHero.moveLegal(row, col)) {
      myHero.playerY = myHero.playerY-myHero.playerSize;
      myHero.rowY=row-1;
    } else {
      row++;
    };
    break;
    case 'D':
    row++;
    if (myHero.moveLegal(row, col)) {
      myHero.playerY = myHero.playerY+myHero.playerSize;
      myHero.rowY=row;
    } else {
      row--;
    };
    break;
    case 'L':
    col--;
    if (myHero.moveLegal(row, col)) {
      myHero.playerX = myHero.playerX-myHero.playerSize;
      myHero.colX=col;
    } else {
      col++;
    };
    break;
    case 'R':
    col++;
    if (myHero.moveLegal(row, col)) {
      myHero.playerX = myHero.playerX+myHero.playerSize;
      myHero.colX=col;
    } else {
      col--;
    };
    break;
    }
    pcolX=col;
    prowY=row;
    aiTurn=true;//player moved, turn to enemy
  }
}


