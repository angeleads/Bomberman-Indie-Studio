/*
** EPITECH PROJECT, 2022
** Indie_Studio
** File description:
** play
*/

#include "bomber.hpp"

void Play::init_textures() {}

void Play::draw_function() {
    ClearBackground(RAYWHITE);
    DrawText(CONTINUE, CONTINUEX, CONTINUEY, CONTINUE_SIZE, PURPLE);
    DrawText(NEW_GAME, NEW_GAMEX, NEW_GAMEY, NEW_GAME_SIZE, PURPLE);
    DrawText(PAUSE_BACK, PAUSE_BACKX, PAUSE_BACKY, PAUSE_BACK_SIZE, PURPLE);
}

void Play::destroy_textures() {}