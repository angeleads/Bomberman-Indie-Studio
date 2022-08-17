/*
** EPITECH PROJECT, 2022
** bomber.hpp
** File description:
** bomber
*/

#pragma once

    #include "game.hpp"
    #include "menu.hpp"
    #include "intro.hpp"
    #include "play.hpp"
    #include "choice.hpp"
    #include "bomberman.hpp"
    #include "pause.hpp"
    #include <string.h>

    void introduction_scene(Game *game, Intro intro);
    int main_menu_scene(Game *game, Menu *menu);
    void scene_two(Game *game, Bomberman *bomberman);
    void choose_game_scene(Game *game, Bomberman *bomberman, Play *play);
    void choose_mode_scene(Game *game, Bomberman *Bomberman, Choice *choice);
    void game_scene(Game *game, Bomberman *bomberman);
    void game_menu_scene(Game *game, Bomberman *bomberman, Pause *pause);
