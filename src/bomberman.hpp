/*
** EPITECH PROJECT, 2022
** Indie_Studio
** File description:
** bomberman
*/
#pragma once

    #define BG_GAME "assets/bomberman/background.png"
    #define MAP "assets/bomberman/map.txt"
    #define BRICK "assets/block/brick_block.png"
    #define WOOD  "assets/block/wood_block.png"
    #define GRASS  "assets/block/grass_block.png"
    #define FIRE "assets/bomb/fire.png"
    #define ANIMATION "assets/bomb/explosion.obj"
    #define PLAYER_IQM "assets/bomberman/player.iqm"
    #define PLAYER_BLUE "assets/bomberman/textures/blue.png"
    #define PLAYER_RED "assets/bomberman/textures/red.png"
    #define WIN1 "assets/win/win1.png"
    #define WIN2 "assets/win/win2.png"
    #include "game.hpp"

    #define BOMB_VOLUME         0.2

    #define MENU_OPTION         "MENU"

    #define MAP_SIZE            12

    #define FRONT               0
    #define BACKK               1
    #define RIGHT               2
    #define LEFT                3
    #define DIRECTIONS          4
    #define DIRECTION_BOMB      "bomb"
    #define DIRECTION_FONT      "font"
    #define DIRECTION_BACK      "back"
    #define DIRECTION_RIGHT     "right"
    #define DIRECTION_LEFT      "left"
    #define DIRECTION_MOVEMENT  1.0

    #define MOVEMENT            5
    #define PLAYER_ONE          1
    #define PLAYER_TWO          2

    #define BREAKABLE_WALL      'w'
    #define UNBREAKABLE_WALL    'x'
    #define EMPTY_WALL          'o'

    class Bomberman : public Game {
        public:
            int no_sound;
            Texture2D background_tx;
            Texture2D brick_tx;
            Texture2D wood_tx;
            Texture2D grass_tx;
            Texture2D bomb_normal_tx;
            Texture2D player_blue_tx;
            Texture2D player_red_tx;
            Texture2D win1_tx;
            Texture2D win2_tx;
            Texture2D fire_tx;
            Model animation;
            Model player_blue;
            Sound bomb_sound;
            Model player_red;
            Camera3D camera = { 0 };
            char **original_map;
            Vector3 cubePosition = { 0.0f, 0.0f, 0.0f };
            Vector3 floorPosition = { 0.0f, 0.0f, 0.0f };
            bool is_load = false;
            bool is_animation = false;
            bool is_explosed = false;
            int which_player = 0;
            float pivot1 = 90.0f;
            float pivot2 = 270.0f;
            int counter = 0;
            chrono::time_point<std::chrono::system_clock> m_StartTime;
            chrono::time_point<std::chrono::system_clock> m_EndTime;
            bool m_bRunning = false;
            bool player1bomb = false;
            bool player2bomb = false;
            float current_time = 0;
            bool is_animating = false;
            bool can_move = true;
            bool is_played_sound = false;

            Bomberman() {   
                camera.position = (Vector3){ 0.0f, 15.0f, 15.0f };
                camera.target = (Vector3){ 0.0f, -5.0f, 0.0f };
                camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
                camera.fovy = 45.0f;
                camera.projection = CAMERA_PERSPECTIVE;
            };
            void init_textures();
            int draw_function();
            void destroy_textures(); 
            void read_from_file();
            void save_original_map();
            void remove_random_walls();
            void move_player(int player, string direction);
            void check_input();
            void move_bot();
            void remove_wall();
            void animation_bomb();
            void plant_bomb(int player);
            void look_for_empty_space();
            void resetGame();
            void save_variables(int nb);
            void saveFunctions();
            void save_map();
            void load_variables();
            void load_map();
            bool bot_check_wall_front(int line, int column);
            bool bot_check_wall_back(int line, int column);
            bool bot_check_wall_left(int line, int column);
            bool bot_check_wall_right(int line, int column);
            void verify_direction(int player, float direction);
            void start_clock();
            void stop();
            void restart();
            double elapsedMilliseconds();
            double elapsedSeconds();
            void check_victory();
            ~Bomberman() {};
    };