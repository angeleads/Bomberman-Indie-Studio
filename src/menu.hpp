/*
** EPITECH PROJECT, 2022
** PlayMenu.hpp
** File description:
** PlayMenu
*/

#pragma once
    #include "game.hpp"

    #define BOMB "assets/main/bomb.png"

    class Menu : public Game {
        public:
            Texture2D main_menu_tx;
            Texture2D bomb_tx;
            bool is_load = false;

            Menu() {}; 
            void init_textures();
            void draw_function(int but);
            void destroy_textures();
            ~Menu() {}; 
    };