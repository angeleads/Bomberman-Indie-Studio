/*
** EPITECH PROJECT, 2022
** Indie_Studio
** File description:
** game_choice
*/

#include "bomber.hpp"

void Choice::init_textures() {}

void Choice::draw_function() {
    DrawText(SOLO, SOLOX, SOLOY, SOLO_SIZE, BLACK);
    DrawText(MULTI, MULTIX, MULTIY, MULTI_SIZE, BLACK);
    DrawText(MENU_BACK, BACKX, BACKY, BACK_SIZE, BLACK);
}

void Choice::destroy_textures() {}