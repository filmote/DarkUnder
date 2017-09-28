//class UI {

  int HP=10;
  int DF=0;
  int AP=1;
  int MG=0;
  char orientation='N';
  // PImage frames;
  // PImage frameOrientation;
  // PImage splash;
  // PImage hMarker;
  // PImage garCo;
  // PImage foundWindow;
  // PImage icnHPPotion;
  // PImage icnTrash;
  // PImage icnHand;
  // PImage icnSelect;
  // PFont font;
  char lastDirection = 'L';
  boolean activated = false;
  boolean back = false;
  String UIStatus;
  String objectType;
  int objectID;


  // UI() {
  // frames = loadImage("frames.gif");
  // frameOrientation = loadImage("frameOrientation.gif");
  // font = loadFont("Hooge0557-8.vlw");
  // splash = loadImage("splash.gif");
  // hMarker = loadImage("hMarker.gif");
  // garCo = loadImage("garCo.gif");
  // foundWindow = loadImage("foundWindow.gif");
  // icnHPPotion = loadImage("icnHPPotion.gif");
  // icnTrash = loadImage("icnTrash.gif");
  // icnHand = loadImage("icnHand.gif");
  // icnSelect = loadImage("icnSelect.gif");
  // textFont(font, 16);
  // }
void displayGame() {

  // image(frames, 0, 0);
  // fill(255);
  // //-- stats
  // textAlign(LEFT);
  // text("HP...", 70, 14); 
  // text("DF...", 70, 22); 
  // text("AP...", 70, 30);
  // text("MG..", 70, 38);
  // textAlign(RIGHT);
  // text(HP, 92, 14); 
  // text(DF, 92, 22); 
  // text(AP, 92, 30);
  // text(MG, 92, 38);

  if (UIStatus == "collecting") {
    // image(foundWindow,16,10);
    // fill(0);
    // textAlign(CENTER);
    // imageMode(CENTER);
    // text("YOU FOUND",35,17);
    // text(objectType,35,51);
    // image(icnHPPotion,35,31);
    // imageMode(CORNER);
    // image(icnHand,66,43);
    // image(icnTrash,78,43);
    switch (lastDirection){

      case 'L':
        Sprites::drawOverwrite(67, 56, icnSelect, 0);
        if (activated){
//        myObjects.remove(objectID);
        UIStatus="";
        }
        break;

      case 'R':
        Sprites::drawOverwrite(79, 56, icnSelect, 0);
        if (activated){
//        myObjects.remove(objectID);
        UIStatus="";
        }
        break;
      // default:
      //   println("exception");
      //   break;
    } 

  }
  else {
    // //-- description
    // textAlign(LEFT);
    // text(myLevel.levelDescription.toUpperCase(), 80, 50);
    // //-- orientation
    // image(frameOrientation,66,43);
    // textSize(16);
    // textAlign(LEFT);
    // text(orientation, 69, 55);
    // textSize(8);
  }
  
}



SplashButtons splashStatus = SplashButtons::Play;

void displaySplash() {
  
  Sprites::drawOverwrite(0, 0, splash, 0);
 
  if (splashStatus == SplashButtons::Play) {
    Sprites::drawSelfMasked(25, 54, hMarker, 0);
  }
  else {
    Sprites::drawSelfMasked(63, 54, hMarker, 0);
  }

  if (arduboy.justPressed(LEFT_BUTTON)) {
    splashStatus = SplashButtons::Play;
  }

  if (arduboy.justPressed(RIGHT_BUTTON)) {
    splashStatus = SplashButtons::About;
  }

  if (arduboy.justPressed(A_BUTTON) && splashStatus == SplashButtons::Play) {
    gameStatus = GameStates::Play;
  }

  if (arduboy.justPressed(A_BUTTON) && splashStatus == SplashButtons::About) {
    gameStatus = GameStates::About;
  }

}

void displayLogo(){

  Sprites::drawOverwrite(0, 0, garCo, 0);  

  if (arduboy.justPressed(A_BUTTON)) {
    gameStatus = GameStates::Splash;
  }

}
  
