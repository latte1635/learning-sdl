#include <SDL2/SDL.h>

class GameObject {
private:

    SDL_Rect _rect_transform;
    SDL_Surface* _texture = NULL;

    SDL_Rect _current_anim;
    int anim[];

public:
    GameObject();
    ~GameObject();

    void draw(SDL_Surface* target_surface);

    void set_position(int x, int y);
    SDL_Rect* get_rect();

    void set_texture(SDL_Surface* texture);
    SDL_Surface* get_texture();
   
    void set_anim_frame(int sheet_pos);
    SDL_Rect* get_current_frame();

    void animate();
};