/*
** EPITECH PROJECT, 2022
** scenes.cpp
** File description:
** scenes
*/

#include "bomber.hpp"

void introduction_scene(Game *game, Intro intro) {
    game->sceneZero();
    intro.draw_function();
}

int main_menu_scene(Game *game, Menu *menu) {
    if (game->sceneOne() == 1)
        return (1);
    menu->draw_function(game->button);
    return (0);
}

void choose_game_scene(Game *game, Bomberman *bomberman, Play *play) {
    if (game->sceneThree() == 1) {
        if (game->continu == 2) {
            bomberman->save_original_map();
            bomberman->resetGame();
        } else if (game->continu == 1) {
            bomberman->load_variables();
            if (game->is_in_game == false)
                bomberman->load_map();
        }
    }
    play->draw_function();
}

void choose_mode_scene(Game *game, Bomberman *bomberman, Choice *choice) {
    if (game->sceneFour() == 1) {
        if (bomberman->is_load == false) {
            bomberman->init_textures();
            bomberman->is_load = true;
        }
        if (game->button == 0) {
            bomberman->is_multi = false;
            bomberman->is_solo = true;
        }
        else if (game->button == 1) {
            bomberman->is_multi = true;
            bomberman->is_solo = false;
        }
        game->button = 0;
    }
    choice->draw_function();
}

void game_scene(Game *game, Bomberman *bomberman) {
    game->sceneFive();
    bomberman->check_input();
    if (bomberman->draw_function() == 1) {
        game->scene = 1;
        game->button = 1;
    }
}

void game_menu_scene(Game *game, Bomberman *bomberman,Pause *pause) {
    if (game->sceneSix() == 1) {
        game->scene = 1;
        game->button = 1;
        bomberman->saveFunctions();
    }
    pause->draw_function();
}