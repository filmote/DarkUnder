class Stalker extends Enemy {
  PImage stalker;
  PImage icnXMap;
  int range=5;
  Stalker ( int rowY, int colX) {
    super (rowY, colX);
    icnXMap = loadImage("icnXMap.gif");
  }
  void display() {
    checkCollision(enemyCurCol, enemyCurRow);
    image (icnXMap, (enemyX+myHero.originX)-((pcolX*TILE_SIZE)), (enemyY+myHero.originY)-((prowY*TILE_SIZE)));
  }
  void moveEnemy () {
    if (dist(enemyCol,enemyRow,pcolX,prowY)<range){
         getTarget(); 
    }
    if (moveUp && moveLegal(enemyRow, enemyCol)) {
      enemyY=enemyY-TILE_SIZE;
    } else if (moveDown && moveLegal(enemyRow, enemyCol)) {
      enemyY=enemyY+TILE_SIZE;
    } else if (moveRight && moveLegal(enemyRow, enemyCol)) {
      enemyX=enemyX+TILE_SIZE;
    } else if (moveLeft && moveLegal(enemyRow, enemyCol)) {
      enemyX=enemyX-TILE_SIZE;
    } else if (!moveLegal(enemyRow, enemyCol)) {
      doNothing();
    }
  }
  //-- doNothing
  void doNothing() {
    enemyRow=enemyCurRow;
    enemyCol=enemyCurCol;
    moveDown=false;
    moveLeft=false;
    moveRight=false;
    moveUp=false;
    //makeDecision();
    //println("doing Nothing!");
  }
  //-- acquire player's position based on quadrants pathfinding
  void getTarget() {
    if (myHero.rowY-enemyCurRow>0 && myHero.colX-enemyCurCol>0) {
      //println("PLAYER BOTTOM RIGHT");
      if (moveLegal(enemyRow+1, enemyCol)) {
        enemyRow++;
        moveDown=true;
        moveLeft=false;
        moveRight=false;
        moveUp=false;
      } else if (moveLegal(enemyRow, enemyCol+1)) {
        enemyCol++;
        moveDown=false;
        moveLeft=false;
        moveRight=true;
        moveUp=false;
      } else {
        enemyRow=enemyCurRow;
        enemyCol=enemyCurCol;
        makeDecision();
        //doNothing();
      }
    } else if (myHero.rowY-enemyCurRow>0 && myHero.colX-enemyCurCol<0) {
      //println("PLAYER BOTTOM LEFT");
      if (moveLegal(enemyRow+1, enemyCol)) {
        enemyRow++;
        moveDown=true;
        moveLeft=false;
        moveRight=false;
        moveUp=false;
      } else if (moveLegal(enemyRow, enemyCol-1)) {
        enemyCol--;
        moveDown=false;
        moveLeft=true;
        moveRight=false;
        moveUp=false;
      } else {
        enemyRow=enemyCurRow;
        enemyCol=enemyCurCol;
        makeDecision();
        //doNothing();
      }
    } else if (myHero.rowY-enemyCurRow<0 && myHero.colX-enemyCurCol>0) {
      //println("PLAYER TOP RIGHT");
      if (moveLegal(enemyRow-1, enemyCol)) {
        enemyRow--;
        moveUp=true;
        moveDown=false;
        moveLeft=false;
        moveRight=false;
      } else if (moveLegal(enemyRow, enemyCol+1)) {
        enemyCol++;
        moveUp=false;
        moveDown=false;
        moveLeft=false;
        moveRight=true;
      } else {
        enemyRow=enemyCurRow;
        enemyCol=enemyCurCol;
        makeDecision();
        //doNothing();
      }
    } else if (myHero.rowY-enemyCurRow<0 && myHero.colX-enemyCurCol<0) {
      //println("PLAYER TOP LEFT");
      if (moveLegal(enemyRow-1, enemyCol)) {
        enemyRow--;
        moveUp=true;
        moveDown=false;
        moveLeft=false;
        moveRight=false;
      } else if (moveLegal(enemyRow, enemyCol-1)) {
        enemyCol--;
        moveUp=false;
        moveDown=false;
        moveLeft=true;
        moveRight=false;
      } else {
        enemyRow=enemyCurRow;
        enemyCol=enemyCurCol;
        makeDecision();
        //doNothing();
      }
    } else if (myHero.rowY-enemyCurRow>0 && myHero.colX-enemyCurCol==0 ) {
      //println("PLAYER BOT");
      enemyRow++;
      moveDown=true;
      moveLeft=false;
      moveRight=false;
      moveUp=false;
    } else if (myHero.rowY-enemyCurRow<0 && myHero.colX-enemyCurCol==0) {
      //println("PLAYER TOP");
      enemyRow--;
      moveUp=true;
      moveDown=false;
      moveLeft=false;
      moveRight=false;
    } else if (myHero.colX-enemyCurCol>0 && myHero.rowY-enemyCurRow==0) {
      //println("PLAYER RIGHT");
      enemyCol++;
      moveRight=true;
      moveDown=false;
      moveLeft=false;
      moveUp=false;
    } else if (myHero.colX-enemyCurCol<0 && myHero.rowY-enemyCurRow==0) {
      //println("PLAYER LEFT");
      enemyCol--;
      moveLeft=true;
      moveDown=false;
      moveRight=false;
      moveUp=false;
    } else {
      makeDecision();
      //doNothing();
    }
  }
}

