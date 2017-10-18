int TILE_SIZE =4;
int UNIT =TILE_SIZE/4;
int row;
int col;
int pcolX;
int prowY;
ArrayList<Object>myObjects = new ArrayList<Object>();
ArrayList<Enemy>myEnemies = new ArrayList<Enemy>();
char gameStatus = 'S'; //S splah, R Running, L logo
UI myUI;
Level myLevel;
Player myHero;
Vision myVision;
boolean aiTurn =true;
void setup(){
  
  //size(128,64);
  size(512,256);
  noSmooth();
  //noStroke();
  myLevel = new Level();
  myVision = new Vision();
  myUI = new UI();
}
void draw(){
  background(255);
  scale(4);
  noStroke(); 
  switch (gameStatus){
    case 'R': //running
          myLevel.worldDrawGrid();
          myHero.display();
          //-- display/remove objects
          for (int i=0; i<myObjects.size (); i++) {
            Object o=myObjects.get(i);
            o.display();
          }
          //-- display/remove enemies
          for (int i=0; i<myEnemies.size (); i++) {
          Enemy e=myEnemies.get(i);
          e.display();
          if (aiTurn) {
            e.moveEnemy();
            aiTurn=false;//enemy moved, wait for player's turn
            }
          }
          myVision.playerVision();
          myUI.displayGame();
          break;
    case 'S': //splash
          myUI.displaySplash();
          myUI.selectOptions();
          break;
    case 'L': //logo
          myUI.displayLogo();
          break;
  }
  //println("Hero X= "+pcolX+" Hero Y= "+prowY);
}
//-- keyboard
void keyPressed() {
  if (keyCode == 'D' || keyCode == RIGHT) {
    myHero.movePlayer('R');
    myUI.lastDirection='R';
  } else if (keyCode == 'A' || keyCode == LEFT) {
    myHero.movePlayer('L');
    myUI.lastDirection='L';
  } else if (keyCode == 'W' || keyCode == UP) {
    myHero.movePlayer('U');
  } else if (keyCode == 'S' || keyCode == DOWN) {
    myHero.movePlayer('D');
  }
  if (keyCode == 'X' || keyCode == 'x') {
  myUI.activated = true;
  } else if (keyCode == 'Z' || keyCode =='z'){
    myUI.back = true;
  }
}
void keyReleased(){
  if (keyCode == 'X' || keyCode == 'x') {
  myUI.activated = false;
  } else if (keyCode == 'Z' || keyCode =='z'){
    myUI.back = false;
  }
}
