/*
** EPITECH PROJECT, 2022
** Indie_Studio
** File description:
** intro
*/

#pragma once
    #include "game.hpp"

    #define INTRO_MENU          "assets/main/mainWelcome.png"

    #define WELCOME_TEXT        "WELCOME"
    #define WELCOMEX            220
    #define WELCOMEY            600
    #define WELCOME_SIZE        125

    #define PRESS_ENTER         "PRESS ENTER"
    #define PRESSX              220
    #define PRESSY              600
    #define PRESS_SIZE          125

    class Intro : public Game {
        public:
            Texture2D welcome_tx;
            bool is_intro = true;

            Intro() {}; 
            void init_textures();
            void update_function(double timer);
            void draw_function();
            void destroy_textures(); 
            void change_screen_intro(double *timer);
            ~Intro() {};
    };