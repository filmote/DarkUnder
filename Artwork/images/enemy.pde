abstract class Enemy {
  //int enemySize = 64;
  int enemyX;
  int enemyY;
  int enemyRow;
  int enemyCol;
  int enemyCurRow;
  int enemyCurCol;
  boolean moveUp;
  boolean moveDown;
  boolean moveRight;
  boolean moveLeft;
  Enemy ( int rowY, int colX) {
    enemyRow=rowY;
    enemyCol=colX;
    enemyCurRow=rowY;
    enemyCurCol=colX;
    enemyX=colX*TILE_SIZE;
    enemyY=rowY*TILE_SIZE;
  }
  void display() {
  }
  //-- moves the player image
  void moveEnemy () {
    if (moveUp && moveLegal(enemyRow, enemyCol)) {
      enemyY=enemyY-TILE_SIZE;
      enemyRow--;
    } else if (moveDown && moveLegal(enemyRow, enemyCol)) {
      enemyY=enemyY+TILE_SIZE;
      enemyRow++;
    } else if (moveRight && moveLegal(enemyRow, enemyCol)) {
      enemyX=enemyX+TILE_SIZE;
      enemyCol++;
    } else if (moveLeft && moveLegal(enemyRow, enemyCol)) {
      enemyX=enemyX-TILE_SIZE;
      enemyCol--;
    } else if (!moveLegal(enemyRow, enemyCol)) {
      enemyRow=enemyCurRow;
      enemyCol=enemyCurCol;
      makeDecision();
    } else {
      if (moveUp) {
        enemyRow++;
      }
      if (moveDown) {
        enemyRow--;
      }
      if (moveRight) {
        enemyCol--;
      }
      if (moveLeft) {
        enemyCol++;
      }
      moveUp=false;
      moveDown=false;
      moveLeft=false;
      moveRight=false;
      makeDecision();
    }
  }
  //-- check if the requested move is possible
  boolean moveLegal (int enemyRow, int enemyCol) {
    if (myLevel.worldGrid[enemyRow][enemyCol]<1) {
      //println("WALK");
      enemyCurCol=enemyCol;
      enemyCurRow=enemyRow;
      return true;
    } else {
      //println("WALL");
      return false;
    }
  }
  //-- check collisions with player
  void checkCollision( int enemyCurCol, int enemyCurRow) {
    //println("--- checking collisions ---");
    //println("enemyX= "+enemyCurCol+" enemyY= "+enemyCurRow);
    //println("playerX= "+myHero.colX+" playerY= "+myHero.rowY);
    if (enemyCurCol == myHero.colX && enemyCurRow == myHero.rowY 
      || enemyCurCol == myHero.colX+1 && enemyCurRow == myHero.rowY
      || enemyCurCol == myHero.colX && enemyCurRow == myHero.rowY+1
      || enemyCurCol == myHero.colX-1 && enemyCurRow == myHero.rowY
      || enemyCurCol == myHero.colX && enemyCurRow == myHero.rowY-1) {
      //println("player dead");
      //gameState=4;
    } //else {println("----");}
  }
  //-- randomize a movement direction
  void makeDecision() {
    int choice = int(random(1, 5));
    //int choice = 4;
    switch(choice) {
    case 1:
      enemyRow--;
      moveUp=true;
      moveDown=false;
      moveLeft=false;
      moveRight=false;
      break;

    case 2:
      enemyCol++;
      moveRight=true;
      moveDown=false;
      moveLeft=false;
      moveUp=false;
      break;

    case 3:
      enemyRow++;
      moveDown=true;
      moveLeft=false;
      moveRight=false;
      moveUp=false;
      break;

    case 4:
      enemyCol--;
      moveLeft=true;
      moveDown=false;
      moveRight=false;
      moveUp=false;
      break;

    default:
      break;
    }
  }
}
