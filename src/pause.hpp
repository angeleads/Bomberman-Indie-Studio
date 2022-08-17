/*
** EPITECH PROJECT, 2022
** Indie_Studio
** File description:
** pause
*/

#pragma once

    #include "game.hpp"

    #define PAUSE_CONTINU   "assets/pause/continue.png"
    #define PAUSE_SETTINGS  "assets/pause/settings.png"
    #define PAUSE_MENU      "assets/pause/menu.png"

    #define CONTINUE_TEXT   "CONTINUE"
    #define CONTINUE_X       550
    #define CONTINUE_Y       250
    #define CONTINUE_SIZE   150

    #define SETTING_TEXT    "SETTINGS"
    #define SETTINGX        550
    #define SETTINGY        450
    #define SETTING_SIZE    150

    #define MENU_TEXT       "MENU"
    #define MENUX           550
    #define MENUY           650
    #define MENU_SIZE       150

    class Pause : public Game {
        public:
            Texture2D continu_tx;
            Texture2D settings_tx;
            Texture2D menu_tx;
            int button = 0;
            bool is_load = false;

            Pause() {}; 
            void init_textures();
            void draw_function();
            void destroy_textures(); 
            ~Pause() {};
    };