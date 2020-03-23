#include "gameobject.h"

GameObject::GameObject() {
    _rect_transform.w = 32;
    _rect_transform.h = 32;
    _rect_transform.x = 1;
    _rect_transform.y = 1;

    _current_anim.w = 32;
    _current_anim.h = 32;
}

GameObject::~GameObject() {
    printf("Destroyed object\n");
}

void GameObject::set_position(int x, int y) {
    _rect_transform.x = x;
    _rect_transform.y = y;
}

SDL_Rect* GameObject::get_rect() {
    return &_rect_transform;
}

SDL_Surface* GameObject::get_texture() {
    return _texture;
}

void GameObject::set_texture(SDL_Surface* texture) {
    _texture = texture;
}

void GameObject::set_anim_frame(int sheet_pos) {
    
    int offset_x = int(sheet_pos % 8) * 32;
    int offset_y = int(sheet_pos / 8) * 32;

    printf("%d, %d\n", offset_x, offset_y);

    _current_anim.x = offset_x;
    _current_anim.y = offset_y;
}

SDL_Rect* GameObject::get_current_frame() {
    return &_current_anim;
}

void animate() {
    
}