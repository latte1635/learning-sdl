#include <SDL2/SDL.h>
#include <string>

class Game {
private:
    SDL_Window* window = NULL;    
    SDL_Surface* screen = NULL;
    SDL_Surface* image = NULL;

    bool quit = false;
    SDL_Event event;

public:
    Game(std::string window_title, int screen_width, int screen_height);
    ~Game();

    bool load_bmp(std::string path);
    void draw_image();
    void update();
    void loop();
    void handle_events(); 
};