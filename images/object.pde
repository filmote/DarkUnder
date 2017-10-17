class Object {
  int objectX;
  int objectY;
  int objectRow;
  int objectCol;
  boolean active=false;
  char objectType;
  PImage icnXMap;

  Object ( int rowY, int colX, char type) {
    objectRow=rowY;
    objectCol=colX;
    objectType=type;
    objectX=colX*TILE_SIZE;
    objectY=rowY*TILE_SIZE;
    icnXMap = loadImage("icnXMap.gif");
  }
  void display() {
    for (int i=0; i<myObjects.size (); i++) {
      Object o=myObjects.get(i);
      if (o.checkCollision(o.objectCol, o.objectRow, o.objectType)) {
        //if (o.objectType=='P') myObjects.remove(i);
        myUI.UIStatus="collecting";
        myUI.objectType="HP POTION";
        myUI.objectID=i;
      }
    }

    switch (objectType) {
    case 'P':
      image (icnXMap, (objectX+myHero.originX)-((pcolX*TILE_SIZE)), (objectY+myHero.originY)-((prowY*TILE_SIZE)));
      break;
    default:
      break;
    }
  }
  boolean checkCollision( int objectCol, int objectRow, char objectType) {
    //println("--- checking collisions ---");
    //println("objectX= "+objectCol+" objectY= "+objectRow);
    //println("playerX= "+pcolX+" playerY= "+prowY);
    if (objectCol == pcolX && objectRow == prowY) {
      //println("player catch");
      collect(objectType);
      return true;
    } else {
      return false;
    }
  }
  void collect(char objectType) {
    //println(objectRow, objectCol);
    switch (objectType) {
    case 'P':
      //fill (220, 156, 1);
      //myHero.hasKey=true;
      //myLevel.worldGrid[myDoor.myDoorRow][myDoor.myDoorCol]=00;   
      break;
    default:
      break;
    }
    //println (objectType+" collected");
  }
}
