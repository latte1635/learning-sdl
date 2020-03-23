#include <SDL2/SDL.h>

class Object {
private:

    SDL_Rect _rect_transform;
    SDL_Surface* _texture = NULL;

    SDL_Rect _current_anim;


public:
    Object();
    ~Object();

    void draw(SDL_Surface* target_surface);

    void set_position(int x, int y);
    SDL_Rect* get_rect();

    void set_texture(SDL_Surface* texture);
    SDL_Surface* get_texture();
   
    void set_anim_frame(int sheet_pos);
    SDL_Rect* get_current_frame();
};