#include <stdio.h>
#include <iostream>

#include "game.h"


int main(int argc, char* argv[]) {
    
    Game game = Game("Test", 640, 480);
    
    game.start();
    game.loop();
}