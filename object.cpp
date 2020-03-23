#include "object.h"

Object::Object() {
    _rect_transform.w = 32;
    _rect_transform.h = 32;
    _rect_transform.x = 1;
    _rect_transform.y = 1;

    _current_anim.w = 32;
    _current_anim.h = 32;
}

Object::~Object() {
    printf("Destroyed object\n");
}

void Object::set_position(int x, int y) {
    _rect_transform.x = x;
    _rect_transform.y = y;
}

SDL_Rect* Object::get_rect() {
    return &_rect_transform;
}

SDL_Surface* Object::get_texture() {
    return _texture;
}

void Object::set_texture(SDL_Surface* texture) {
    _texture = texture;
}

void Object::set_anim_frame(int sheet_pos) {
    
    int offset_x = int(sheet_pos % 8) * 32;
    int offset_y = int(sheet_pos / 8) * 32;

    printf("%d, %d\n", offset_x, offset_y);

    _current_anim.x = offset_x;
    _current_anim.y = offset_y;
}

SDL_Rect* Object::get_current_frame() {
    return &_current_anim;
}