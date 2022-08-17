/*
** EPITECH PROJECT, 2022
** Intro.cpp
** File description:
** Intro
*/

#include "intro.hpp"

void Intro::draw_function() {
    if (this->is_intro == true) {
        DrawText("WELCOME", 220, 600, 125, BLACK);
    } else {
        DrawText("PRESS ENTER", 220, 600, 125, BLACK);
    }
}

void Intro::change_screen_intro(double *timer) {    
    if (int (*timer) % 2 == 0)
        this->is_intro = true;
    else {
        this->is_intro = false;
    }
}

void Intro::update_function(double timer) {
    if (this->scene == INTRO) {
        timer = GetTime();
        this->change_screen_intro(&timer);
    }
}

void Intro::destroy_textures() {}