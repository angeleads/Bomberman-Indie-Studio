/*
** EPITECH PROJECT, 2022
** Menu.cpp
** File description:
** Menu
*/

#include "menu.hpp"

void Menu::init_textures() {
}

void Menu::draw_function(int but) {
    if (but == 0) {
        DrawText("SETTINGS", 20, 450, 120, GREEN);
        DrawText("PLAY", 775, 550, 100, BLACK);
        DrawText("EXIT", 1400, 550, 100, BLACK);
    } else if (but == 1) {
        DrawText("SETTINGS", 50, 550, 100, BLACK);
        DrawText("PLAY", 750, 450, 190, GREEN);
        DrawText("EXIT", 1400, 550, 100, BLACK);
    } else if (but == 2) {
        DrawText("SETTINGS", 50, 550, 100, BLACK);
        DrawText("PLAY", 775, 550, 100, BLACK);
        DrawText("EXIT", 1375, 450, 190, GREEN);
    }
}

void Menu::destroy_textures() {}