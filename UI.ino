

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
    gameState = GameState::InitGame;
  }

  if (arduboy.justPressed(A_BUTTON) && splashStatus == SplashButtons::About) {
    gameState = GameState::About;
  }

}

void displayLogo(){

  Sprites::drawOverwrite(0, 0, garCo, 0);  

  if (arduboy.justPressed(A_BUTTON)) {
    gameState = GameState::Splash;
  }

}
  
