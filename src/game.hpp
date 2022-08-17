/*
** EPITECH PROJECT, 2022
** Indie_Studio
** File description:
** game=
*/
#pragma once

    #include <iostream>
    #include <fstream>
    #include <string>
    #include <stdio.h>
    #include <raylib.h>
    #include <chrono>

    using namespace std;

    #define WINDOW_WIDTH            1920
    #define WINDOW_HEIGHT           1000
    #define WINDOW_NAME             "[INDIE] Bomberman"
    #define FPS                     60

    #define NUM_FRAMES_PER_LINE     5
    #define NUM_LINES               5

    /*
        scene 0 = intro
        scene 1 = menu principal
        scene 2 = settings
        scene 3 = choice beetween save or new game
        scene 4 = choice beetween solo and multiplayers
        scene 5 = game
        scene 6 = pause menu
        scene 7 = end game page
    */

    #define INTRO                   0
    #define MAIN_MENU               1
    #define SETTINGS                2
    #define SAVED_NEWGAME           3
    #define SOLO_MULTIPLAYER        4
    #define GAME_SCENE              5
    #define GAME_MENU              6
    #define END_GAME                7

    #define MUSIC_TEXT              "MUSIC"
    #define SOUND_TEXT              "SOUND"
    #define BACK_TEXT               "BACK"

    #define MENU_MUSIC "assets/Music/music_menu.ogg"
    #define BUTTON_SOUND "assets/Music/sound_press_button.ogg"
    #define GAME_MUSIC "assets/Music/music_game.ogg"
    #define INTRO_MENU "assets/main/mainWelcome.png"
    #define MENU "assets/main/mainMenu.png"
    #define BOMB "assets/main/bomb.png"
    #define SOUND_ON "assets/main/on.png"
    #define SOUND_OFF "assets/main/mute.png"
    #define FONT "assets/font/walkthemoon.ttf"
    #define LEFT_G "assets/welcome/1bw.png"
    #define LEFT_C "assets/welcome/1on.png"
    #define MID_G "assets/welcome/2bw.png"
    #define MID_C "assets/welcome/2on.png"
    #define RIGHT_G "assets/welcome/3bw.png"
    #define RIGHT_C "assets/welcome/3on.png"
    #define SMENU "assets/main/smenu.png"
    #define BOMB_SOUND "assets/bomb/bomb.ogg"
    #define PMENU "assets/main/pmenu.png"
    #define SAVE_MAP "save/SaveMap.txt"
    #define SAVE_VARIABLES "save/SaveVariables.txt"

    class Game {
        public:
            int scene = 0;
            int button = 1;
            int f_call = 0;
            int is_pause = 0;
            const int screenWidth = 1920;
            const int screenHeight = 1000;
            bool is_solo = false;
            bool is_multi = false;
            Music MenuMusic;
            Music GameMusic;
            Sound ButtonSound;
            Font font;
            Texture2D intro_tx;
            Texture2D main_menu_tx;
            Texture2D menu_tx;
            Texture2D bomb_tx;
            Texture2D sOn_tx;
            Texture2D sOf_tx;
            Texture2D leftG_tx;
            Texture2D leftC_tx;
            Texture2D midG_tx;
            Texture2D midC_tx;
            Texture2D rightG_tx;
            Texture2D rightC_tx;
            Texture2D smenu_tx;
            Texture2D pmenu_tx;
            Vector3 player1 = { -4.0f, 0.0f, 1.0f };
            Vector3 player2 = { 4.0f, 0.0f, 9.0f };
            char **current_map;
            int continu = 0;
            bool is_in_game = false;
            bool is_load_file = false;
            time_t start;
            int win = 0;
            bool is_game_finish = false;
            float music_volume = 0.4f;
            float sound_volume = 0.3f;

            Game() {start=time(0);};
            void destroy_textures();
            void init_textures();
            void draw_function();
            void init_music();
            void handle_buttons();
            void musicAndSound();
            void muteAndPlay();
            void sceneZero();
            int sceneOne();
            void draw_menu_one();
            void settings_scene();
            int sceneThree();
            int sceneFour();
            void sceneFive();
            int sceneSix();
            void sceneSeven();
            void check_is_loadfiles();
            ~Game() {};
    };