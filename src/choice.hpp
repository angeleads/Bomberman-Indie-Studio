/*
** EPITECH PROJECT, 2022
** Indie_Studio
** File description:
** game_choice
*/

#pragma once

    #include "game.hpp"

    #define MENU "assets/main/mainMenu.png"
    #define BOMB "assets/main/bomb.png"

    #define SOLO            "SOLO"
    #define SOLOX           140
    #define SOLOY           250
    #define SOLO_SIZE       115

    #define MULTI           "MULTIPLAYER"
    #define MULTIX          140
    #define MULTIY          500
    #define MULTI_SIZE      115

    #define MENU_BACK       "BACK"
    #define BACKX           140
    #define BACKY           750
    #define BACK_SIZE       115

    class Choice : public Game {
        public:
            Texture2D menu_tx;
            Texture2D bomb_tx;
            int button = 0;
            bool is_load = false;

            Choice() {}; 
            void init_textures();
            void draw_function();
            void destroy_textures(); 
            ~Choice() {};
    };