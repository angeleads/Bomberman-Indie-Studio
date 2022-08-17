/*
** EPITECH PROJECT, 2022
** Indie_Studio
** File description:
** play
*/

#pragma once

    #include "game.hpp"

    #define MENU "assets/main/mainMenu.png"
    #define BOMB "assets/main/bomb.png"

    #define CONTINUE                "CONTINUE"
    #define CONTINUEX               350
    #define CONTINUEY               250
    #define CONTINUE_SIZE           150

    #define NEW_GAME                "NEW GAME"
    #define NEW_GAMEX               350
    #define NEW_GAMEY               450
    #define NEW_GAME_SIZE           150

    #define PAUSE_BACK              "BACK"
    #define PAUSE_BACKX             575
    #define PAUSE_BACKY             650
    #define PAUSE_BACK_SIZE         150

    class Play : public Game {
        public:
            Texture2D menu_tx;
            Texture2D bomb_tx;
        
            int button = 0;
            int is_load = false;

            Play() {}; 
            void init_textures();
            void draw_function();
            void destroy_textures(); 
            ~Play() {};
    };