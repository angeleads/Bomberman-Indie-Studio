/*
** EPITECH PROJECT, 2022
** Indie_Studio
** File description:
** pause
*/

#include "bomber.hpp"

void Pause::init_textures() {}

void Pause::draw_function()
{
    ClearBackground(RAYWHITE);
    DrawText(CONTINUE_TEXT, CONTINUE_X, CONTINUE_Y, CONTINUE_SIZE, BLACK);
    DrawText(SETTING_TEXT, SETTINGX, SETTINGY, SETTING_SIZE, BLACK);
    DrawText(MENU_TEXT, MENUX, MENUY, MENU_SIZE, BLACK);
}

void Pause::destroy_textures() {}