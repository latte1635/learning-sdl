#include "game.h"

Game::Game(std::string window_title, int screen_width, int screen_height) {

    if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
    }
    else
    {
        window = SDL_CreateWindow(window_title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screen_width, screen_height, SDL_WINDOW_SHOWN);
        
        if(window == NULL)
        {
            printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
            
        }
        else
        {
            screen = SDL_GetWindowSurface(window);
        }
    }
}

Game::~Game() {
    //Deallocate surface
    SDL_FreeSurface(image);
    image = NULL;

    //Destroy window and window surface
    SDL_DestroyWindow(window);
    window = NULL;

    //Quit SDL subsystems
    SDL_Quit();
    printf("Exited game Successfully\n");
}

bool Game::load_bmp(std::string path) {
    
    image = SDL_LoadBMP(path.c_str());
    if(image == NULL)
    {
        printf("Unable to load image %s! SDL Error: %s\n", path, SDL_GetError());
        return false;
    }
    printf("Successfully loaded bmp image: %s\n", path.c_str());
    return true;
}

void Game::draw_image() {
    SDL_BlitSurface(image, NULL, screen, NULL);
}

void Game::update() {
    SDL_UpdateWindowSurface(window);
}

void Game::handle_events() {
    while(SDL_PollEvent(&event) != 0) {
        
    }
}

void Game::loop() {
    while(!quit) {
        update();   
    }
}