#include <SDL2/SDL.h>
#include <string>
#include <vector>

#include "object.h"

class Game {
private:

    int _screen_width = 0;
    int _screen_height = 0;

    SDL_Window* window = NULL;
    SDL_Surface* screen = NULL;

    std::vector<Object*> objects;
    std::vector<SDL_Surface*> textures;

    bool quit = false;
    SDL_Event event;

public:
    Game(std::string window_title, int screen_width, int screen_height);
    ~Game();

    SDL_Surface* load_bmp(std::string path);
    
    void preload_object_surfaces();
    void draw();
    void start();
    void loop();
    void handle_events(); 
};