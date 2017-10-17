class Level {
  int originX=108;
  int originY=18;
  String levelDescription="Hallway of \nthe dead";
  int [][] worldGrid={   
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
Level(){
   row=8;
   col=4;
   myHero = new Player(row, col); 
   myObjects.add(new Object(3, 3, 'P'));
   //myObjects.add(new Object(4, 6, 'P'));
   myEnemies.add(new Stalker(2, 6));
};

void worldDrawGrid() {
  rectMode(CORNER);
    for (int row=0; row<worldGrid.length; row++) {
      for ( int col=0; col<worldGrid[row].length; col++) {
        switch(worldGrid[row][col]) {
        case 0: //floor
          fill(0);
          break;

        case 1: //wall
          fill(255);
          break;

        default:
          println("exception in worldDrawGrid!");
          break;
        }
        rect((col*TILE_SIZE+myHero.originX)-((pcolX*TILE_SIZE)), (row*TILE_SIZE+myHero.originY)-((prowY*TILE_SIZE)), TILE_SIZE, TILE_SIZE);
      }
    }
  }

}
