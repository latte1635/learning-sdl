#include <SDL2/SDL.h>
#include <string>
#include <vector>

#include "gameobject.h"

class Game {
private:

    enum KeyPresses {
        KEY_PRESS_SURFACE_DEFAULT,
        KEY_PRESS_SURFACE_UP,
        KEY_PRESS_SURFACE_DOWN,
        KEY_PRESS_SURFACE_LEFT,
        KEY_PRESS_SURFACE_RIGHT,
        KEY_PRESS_SURFACE_TOTAL,
    };

    int _screen_width = 0;
    int _screen_height = 0;

    SDL_Window* window = NULL;
    SDL_Surface* screen = NULL;

    std::vector<GameObject*> objects;
    std::vector<SDL_Surface*> textures;

    bool quit = false;
    SDL_Event event;

public:
    Game(std::string window_title, int screen_width, int screen_height);
    ~Game();

    SDL_Surface* load_bmp(std::string path);
    
    void draw();
    void start();
    void loop();
    void handle_events(); 
};