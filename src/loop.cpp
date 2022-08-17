/*
** EPITECH PROJECT, 2022
** Indie_Studio
** File description:
** loop
*/

#include "bomber.hpp"

void update_music(Game game)
{
    if (game.scene <= SOLO_MULTIPLAYER && game.is_pause == 0) { 
        StopMusicStream(game.GameMusic);
        UpdateMusicStream(game.MenuMusic);
    } else {
        PlayMusicStream(game.GameMusic);
        UpdateMusicStream(game.GameMusic); 
    }
}

void destroy_and_save(Game game, Bomberman bomberman) {
    game.destroy_textures();
    bomberman.destroy_textures();
    bomberman.saveFunctions();
}

int draw_scene(Menu *menu, Game *game, Intro intro, Play *play, Choice *choice,
Bomberman *bomberman, Pause *pause)
{
    game->draw_function();
    switch (game->scene) {
        case INTRO:
            introduction_scene(game, intro);
            break;
        case MAIN_MENU:
            if (main_menu_scene(game, menu) == 1)
                return (1);
            break;
        case SETTINGS:
            game->settings_scene();
            break;
        case SAVED_NEWGAME:
            choose_game_scene(game, bomberman, play);
            break;
        case SOLO_MULTIPLAYER:
            choose_mode_scene(game, bomberman, choice);
            break;
        case GAME_SCENE:
            game_scene(game, bomberman);
            break;
        case GAME_MENU:
            game_menu_scene(game, bomberman, pause);
            break;
    }
    return (0);
}

void loop_function() {
    Menu menu;
    Game game;
    Intro intro;
    Play play;
    Choice choice;
    Bomberman bomberman;
    Pause pause;
    double timer = 0;

    game.init_textures();
    game.init_music();
    SetExitKey(KEY_F4);
    SetCameraMode(bomberman.camera, CAMERA_FREE);
    SetTargetFPS(60);
    bomberman.read_from_file();
    while (!WindowShouldClose()) {
        intro.update_function(timer);
        UpdateCamera(&bomberman.camera);
        update_music(game);
        BeginDrawing();
        if (draw_scene(&menu, &game, intro, &play, &choice, &bomberman, &pause) == 1) {
            EndDrawing();
            break;
        }
        EndDrawing();
    }
    destroy_and_save(game, bomberman);
}