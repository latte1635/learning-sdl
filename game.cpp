#include "game.h"

Game::Game(std::string window_title, int screen_width, int screen_height) {

    if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
    }
    else {
        window = SDL_CreateWindow(window_title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screen_width, screen_height, SDL_WINDOW_SHOWN);
        
        if(window == NULL) {
            printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        }
        else {
            screen = SDL_GetWindowSurface(window);
        }
    }
    _screen_width = screen_width;
    _screen_height = screen_height;
}

Game::~Game() {

    for(GameObject* object : objects)
        delete(object);

    // Destroy textures
    for(SDL_Surface* texture : textures)
        SDL_FreeSurface(texture);

    // Destroy window and window surface
    SDL_DestroyWindow(window);
    window = NULL;
    
    // Quit SDL subsystems
    SDL_Quit();
    printf("Exited game Successfully\n");
}

SDL_Surface* Game::load_bmp(std::string path) {

    SDL_Surface* texture = SDL_LoadBMP(path.c_str());
    if(texture == NULL) {
        printf("Unable to load image %s! SDL Error: %s\n", path, SDL_GetError());
    }
    printf("Successfully loaded bmp image: %s\n", path.c_str());

    textures.push_back(texture);
    return texture;
}

void Game::draw() {
    for(GameObject* object : objects) {

        SDL_Rect* position = object->get_rect();
        //if(position->x <= 0 || position->x >= _screen_width || position->y <= 0 || position->y >= _screen_height) {
        //    continue;
        //}
        printf("Player position: %d, %d\n", position->x, position->y);
        SDL_BlitSurface(object->get_texture(), object->get_current_frame(), screen, position);
    }
    SDL_UpdateWindowSurface(window);
}

void Game::handle_events() {
    while(SDL_PollEvent(&event) != 0) {
        if(event.type == SDL_QUIT) {
            quit = true;
        }
    }
}

void Game::start() {

    SDL_Surface* player_texture = load_bmp("assets/dudeanim.bmp");

    GameObject* player = new GameObject();
    player->set_texture(player_texture);
    player->set_anim_frame(0);
    objects.push_back(player);

}

void Game::loop() {

    int frame = 0;

    while(!quit) {
        handle_events();

        objects.at(0)->set_anim_frame(frame % 3);
        
        draw();
        frame++;
    }
}