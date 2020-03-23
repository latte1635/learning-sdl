#include <stdio.h>
#include <iostream>

#include "game.h"


int main(int argc, char* argv[]) {
    
    Game game = Game("Test", 640, 480);

    game.load_bmp("assets/dude.bmp");
    game.draw_image();
    game.update();

    game.loop();
    

}