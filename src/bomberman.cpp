/*
** EPITECH PROJECT, 2022
** Indie_Studio
** File description:
** bomberman
*/

#include "bomber.hpp"
#include <unistd.h>
#include <chrono> 
#include <thread>

void Bomberman::init_textures()
{
    Image background = LoadImage(BG_GAME);
    this->background_tx = LoadTextureFromImage(background);
    UnloadImage(background);
    Image brick = LoadImage(BRICK);
    this->brick_tx = LoadTextureFromImage(brick);
    UnloadImage(brick);
    Image wood = LoadImage(WOOD);
    this->wood_tx = LoadTextureFromImage(wood);
    UnloadImage(wood);
    Image grass = LoadImage(GRASS);
    this->grass_tx = LoadTextureFromImage(grass);
    UnloadImage(grass);

    Image win1 = LoadImage(WIN1);
    this->win1_tx = LoadTextureFromImage(win1);
    UnloadImage(win1);

    Image win2 = LoadImage(WIN2);
    this->win2_tx = LoadTextureFromImage(win2);
    UnloadImage(win2);

    this->bomb_sound = LoadSound(BOMB_SOUND);
    SetSoundVolume(this->bomb_sound, BOMB_VOLUME);

    this->player_blue = LoadModel(PLAYER_IQM);
    this->player_blue_tx = LoadTexture(PLAYER_BLUE);
    player_blue.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = this->player_blue_tx;
    this->player_red = LoadModel(PLAYER_IQM);
    this->player_red_tx = LoadTexture(PLAYER_RED);
    player_red.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = this->player_red_tx;
    this->animation = LoadModel(ANIMATION);
    fire_tx = LoadTexture(FIRE);
    animation.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = fire_tx;
}

void Bomberman::remove_wall()
{
    int i = 0;
    int j = 0;
    int tmpi = 0;
    int tmpj = 0;
    bool explosion = false;
    if (which_player == PLAYER_ONE) {
        i = player1.z;
        j = player1.x + MOVEMENT;
        tmpi = i;
        tmpj = j;
    } else if (which_player == PLAYER_TWO){
        i = player2.z;
        j = player2.x + MOVEMENT;
        tmpi = i;
        tmpj = j;
    }
    if (current_map[tmpi + 1][tmpj] == BREAKABLE_WALL) {
        explosion = true;
        current_map[tmpi + 1][tmpj] = EMPTY_WALL;
    } if (current_map[tmpi - 1][tmpj] == BREAKABLE_WALL) {
        explosion = true;
        current_map[tmpi - 1][tmpj] = EMPTY_WALL;
    } if (current_map[tmpi][tmpj + 1] == BREAKABLE_WALL) {
        explosion = true;
        current_map[tmpi][tmpj + 1] = EMPTY_WALL;
    } if (current_map[tmpi][tmpj - 1] == BREAKABLE_WALL) {
        explosion = true;
        current_map[tmpi][tmpj - 1] = EMPTY_WALL;
    }
    if (explosion == true)
        PlaySound(this->bomb_sound);
}

void Bomberman::check_victory()
{
    if (((player1.x - 1 == player2.x && player1.z == player2.z) || (player1.x + 1 == player2.x && player1.z == player2.z)|| (player1.z - 1 == player2.z && player1.x == player2.x)|| (player1.z + 1 == player2.z && player1.x == player2.x)) && player1bomb == true) {
        is_game_finish = true;
        win = PLAYER_ONE;
    } else if (((player2.x - 1 == player1.x && player2.z == player1.z)|| (player2.x + 1 == player1.x && player2.z == player1.z)|| (player2.z - 1 == player1.z && player2.x == player1.x)|| (player2.z + 1 == player1.z && player2.x == player1.x)) && player2bomb == true) {
        is_game_finish = true;
        win = PLAYER_TWO;
    }
}

void Bomberman::verify_direction(int player, float direction)
{
    if (player == 1)
        pivot1 = direction;
    else
        pivot2 = direction;
}

void Bomberman::move_player(int player, string direction)
{
    int line = 0;
    int column = 0;

    if (player == PLAYER_ONE) {
        line = player1.z;
        column = player1.x + MOVEMENT;
        if (direction == DIRECTION_FONT) {
            if (current_map[line - 1][column] != UNBREAKABLE_WALL && current_map[line - 1][column] != BREAKABLE_WALL)
                player1.z -= DIRECTION_MOVEMENT;
            verify_direction(player, 270.0f);
        } else if (direction == DIRECTION_BACK) {
            if (current_map[line + 1][column] != UNBREAKABLE_WALL && current_map[line + 1][column] != BREAKABLE_WALL)
                player1.z += DIRECTION_MOVEMENT;
            verify_direction(player, 90.0f);
        } else if(direction == DIRECTION_RIGHT) {
            if (current_map[line][column + 1] != UNBREAKABLE_WALL && current_map[line][column + 1] != BREAKABLE_WALL)
                player1.x += DIRECTION_MOVEMENT;
            verify_direction(player, 180.0f);
        } else if (direction == DIRECTION_LEFT) {
            if (current_map[line][column - 1] != UNBREAKABLE_WALL && current_map[line][column - 1] != BREAKABLE_WALL)
                player1.x -= DIRECTION_MOVEMENT;
            verify_direction(player, 0.0f);
        } else if (direction == DIRECTION_BOMB) {
            is_animation = true;
            which_player = PLAYER_ONE;
        }
    } else {
        line = player2.z;
        column = player2.x + 5;
        if (direction == DIRECTION_FONT) {
            if (current_map[line - 1][column] != UNBREAKABLE_WALL && current_map[line - 1][column] != BREAKABLE_WALL)
                player2.z -= DIRECTION_MOVEMENT;
            verify_direction(player, 270.0f);
        } else if (direction == DIRECTION_BACK) {
            if (current_map[line + 1][column] != UNBREAKABLE_WALL && current_map[line + 1][column] != BREAKABLE_WALL)
                player2.z += DIRECTION_MOVEMENT;
            verify_direction(player, 90.0f);
        } else if(direction == DIRECTION_RIGHT) {
            if (current_map[line][column + 1] != UNBREAKABLE_WALL && current_map[line][column + 1] != BREAKABLE_WALL)
                player2.x += DIRECTION_MOVEMENT;
            verify_direction(player, 180.0f);
        } else if (direction == DIRECTION_LEFT) {
            if (current_map[line][column - 1] != UNBREAKABLE_WALL && current_map[line][column - 1] != BREAKABLE_WALL)
                player2.x -= DIRECTION_MOVEMENT;
            verify_direction(player, 0.0f);
        } else if (direction == DIRECTION_BOMB) {
            is_animation = true;
            which_player = PLAYER_TWO;
        }
    }
}
void Bomberman::check_input()
{
    if (this->is_solo == true && can_move == true) {
        if (IsKeyPressed(KEY_W) == true)
            move_player(1, DIRECTION_FONT);
        else if (IsKeyPressed(KEY_S) == true)
            move_player(1, DIRECTION_BACK);
        else if (IsKeyPressed(KEY_A) == true)
            move_player(1, DIRECTION_LEFT);
        else if (IsKeyPressed(KEY_D) == true)
            move_player(1, DIRECTION_RIGHT);
        else if (IsKeyPressed(KEY_E) == true) {
            move_player(1, DIRECTION_BOMB);
            this->player1bomb = true;
        }
    } else if (this->is_multi == true && can_move == true) {
        if (IsKeyPressed(KEY_W) == true)
            move_player(PLAYER_ONE, DIRECTION_FONT);
        else if (IsKeyPressed(KEY_A) == true)
            move_player(PLAYER_ONE, DIRECTION_LEFT);
        else if (IsKeyPressed(KEY_S) == true)
            move_player(PLAYER_ONE, DIRECTION_BACK);
        else if (IsKeyPressed(KEY_D) == true)
            move_player(PLAYER_ONE, DIRECTION_RIGHT);
        else if (IsKeyPressed(KEY_E) == true) {
            move_player(PLAYER_ONE, DIRECTION_BOMB);
            this->player1bomb = true;
        } else if (IsKeyPressed(KEY_UP) == true)
            move_player(PLAYER_TWO, DIRECTION_FONT);
        else if (IsKeyPressed(KEY_LEFT) == true)
            move_player(PLAYER_TWO, DIRECTION_LEFT);
        else if (IsKeyPressed(KEY_DOWN) == true)
            move_player(PLAYER_TWO, DIRECTION_BACK);
        else if (IsKeyPressed(KEY_RIGHT) == true)
            move_player(PLAYER_TWO, DIRECTION_RIGHT);
        else if (IsKeyPressed(KEY_RIGHT_SHIFT) == true) {
            move_player(PLAYER_TWO, DIRECTION_BOMB);
            this->player2bomb = true;
        }
    }
}

int get_random(int lower, int upper)
{
    return ((rand() % (upper - lower + 1)) + lower);
}

void Bomberman::move_bot()
{
    int line = 0;
    int column = 0;
    DrawModelEx(this->player_red, { player2.x, player2.y, player2.z }, (Vector3){ 0.0f, 1.0f, 0.0f }, pivot2, (Vector3){ 0.5f, 0.5f, 0.5f }, WHITE);
    line = player2.z;
    column = player2.x + MOVEMENT;
    bool checks[DIRECTIONS];
    checks[FRONT] = bot_check_wall_front(line, column);
    checks[BACKK] = bot_check_wall_back(line, column);
    checks[RIGHT] = bot_check_wall_right(line, column);
    checks[LEFT] = bot_check_wall_left(line, column);

    if ((time(0)-start)%2 == 0 && counter%15== 0 && can_move == true) {
        if (checks[FRONT] == false && get_random(0, 1) == 0) { //front
            counter++;
            if (current_map[line - 1][column] == EMPTY_WALL) {
                player2.z -= DIRECTION_MOVEMENT;
                pivot2 = 270.0f;
            } else {
                player2bomb = true;
                move_player(PLAYER_TWO, DIRECTION_BOMB);
                if (current_map[line - 1][column] == EMPTY_WALL)
                    player2.z -= DIRECTION_MOVEMENT;
            }
        }
        else if (checks[BACKK] == false && get_random(0, 1) == 0) { //back
            counter++;
            if (current_map[line + 1][column] == EMPTY_WALL) {
                player2.z += DIRECTION_MOVEMENT;
                pivot2 = 90.0f;
            } else {    
                player2bomb = true;
                move_player(PLAYER_TWO, DIRECTION_BOMB);
                if (current_map[line + 1][column] == EMPTY_WALL)
                    player2.z += DIRECTION_MOVEMENT;
            }
        }
        else if (checks[RIGHT] == false && get_random(0, 1) == 0) { //right
            counter++;
            if (current_map[line][column + 1] == EMPTY_WALL) {
                player2.x += DIRECTION_MOVEMENT;
                pivot2 = 180.0f;
            } else {
                player2bomb = true;
                move_player(PLAYER_TWO, DIRECTION_BOMB);
                if (current_map[line][column + 1] == EMPTY_WALL)
                    player2.x += DIRECTION_MOVEMENT;
            }
        }
        else if (checks[LEFT] == false && get_random(0, 1) == 0) { //left
            counter++;
            if (current_map[line][column - 1] == EMPTY_WALL) {
                player2.x -= DIRECTION_MOVEMENT;
                pivot2 = 0.0f;
            } else {
                player2bomb = true;
                move_player(PLAYER_TWO, DIRECTION_BOMB);
                if (current_map[line][column - 1] == EMPTY_WALL)
                    player2.x -= DIRECTION_MOVEMENT;
            }
        }
        else if (checks[FRONT] == false && get_random(0, 1) == 0) { //front
            counter++;
            if (current_map[line - 1][column] == EMPTY_WALL) {
                player2.z -= DIRECTION_MOVEMENT;
                pivot2 = 270.0f;
            } else {
                player2bomb = true;
                move_player(PLAYER_TWO, DIRECTION_BOMB);
                if (current_map[line - 1][column] == EMPTY_WALL)
                    player2.z -= DIRECTION_MOVEMENT;
            }
        }  
        else if (checks[BACKK] == false) { //back
            counter++;
            if (current_map[line + 1][column] == EMPTY_WALL) {
                player2.z += DIRECTION_MOVEMENT;
                pivot2 = 90.0f;
            } else {
                player2bomb = true;
                move_player(PLAYER_TWO, DIRECTION_BOMB);
                if (current_map[line + 1][column] == EMPTY_WALL)
                    player2.z += DIRECTION_MOVEMENT;
            }
        }
        else if (checks[RIGHT] == false) { //right
            counter++;
            if (current_map[line][column + 1] == EMPTY_WALL) {
                player2.x += DIRECTION_MOVEMENT;
                pivot2 = 180.0f;
            } else {
                player2bomb = true;
                move_player(PLAYER_TWO, DIRECTION_BOMB);
                if (current_map[line][column + 1] == EMPTY_WALL)
                    player2.x += DIRECTION_MOVEMENT;
            }
        }
        else if (checks[LEFT] == false) { //left
            counter++;
            if (current_map[line][column - 1] == EMPTY_WALL) {
                player2.x -= DIRECTION_MOVEMENT;
                pivot2 = 0.0f;
            } else {
                player2bomb = true;
                move_player(PLAYER_TWO, DIRECTION_BOMB);
                if (current_map[line][column - 1] == EMPTY_WALL)
                    player2.x -= DIRECTION_MOVEMENT;
            }
        }
    }
    counter++;
}
void Bomberman::animation_bomb()
{
    int i = 0;
    int j = 0;
    int tmpi = 0;
    int tmpj = 0;
    float mili = 0;

    if (which_player == PLAYER_ONE) {
        i = player1.x + MOVEMENT;
        j = player1.z;
        tmpi = i;
        tmpj = j;
    } if (which_player == PLAYER_TWO) {
        i = player2.x + MOVEMENT;
        j = player2.z;
        tmpi = i;
        tmpj = j;
    }
    if (is_animating == false)
        start_clock();
    current_time = elapsedSeconds();
    if (current_time < 1) {
        if (which_player == 1) {
            if (current_map[tmpi - 1][tmpj] != UNBREAKABLE_WALL) {
                DrawModel(animation, {player1.x - 1, player1.y - 0.4f, player1.z}, 1.0f, WHITE);
            }
            if (current_map[tmpi + 1][tmpj] != UNBREAKABLE_WALL)
                DrawModel(animation, {player1.x + 1, player1.y - 0.4f, player1.z}, 1.0f, WHITE);
            if (current_map[tmpi][tmpj + 1] != UNBREAKABLE_WALL)
                DrawModel(animation, {player1.x, player1.y - 0.4f, player1.z + 1}, 1.0f, WHITE);
            if (current_map[tmpi][tmpj - 1] != UNBREAKABLE_WALL)
                DrawModel(animation, {player1.x, player1.y - 0.4f, player1.z - 1}, 1.0f, WHITE);
            this->remove_wall();
        } else if (which_player == 2) {
            if (current_map[tmpi - 1][tmpj] != UNBREAKABLE_WALL)
                DrawModel(animation, {player2.x - 1, player2.y - 0.4f, player2.z}, 1.0f, WHITE);
            if (current_map[tmpi + 1][tmpj] != UNBREAKABLE_WALL)
                DrawModel(animation, {player2.x + 1, player2.y - 0.4f, player2.z}, 1.0f, WHITE);
            if (current_map[tmpi][tmpj + 1] != UNBREAKABLE_WALL)
                DrawModel(animation, {player2.x, player2.y - 0.4f, player2.z + 1}, 1.0f, WHITE);
            if (current_map[tmpi][tmpj - 1] != UNBREAKABLE_WALL)
                DrawModel(animation, {player2.x, player2.y - 0.4f, player2.z - 1}, 1.0f, WHITE);
            this->remove_wall();
        }
        is_animating = true;
        can_move = false;
    } else if (current_time >= 1) {
        current_time = 0;
        is_animation = false;
        is_animating = false;
        can_move = true;
        stop();
    }
}

int Bomberman::draw_function()
{
    unsigned int animsCount = 0;
    ModelAnimation *anims = LoadModelAnimations(PLAYER_IQM, &animsCount);
    int animFrameCounter = 0;
    Vector3 position = { 0.3f, 0.3f, 0.5f };
    int res = 0;

    if (is_game_finish == false) {
        ClearBackground(RAYWHITE);
        DrawTexture(this->background_tx, this->screenWidth/2 - this->background_tx.width/2,
        this->screenHeight/2 - this->background_tx.height/2, WHITE);
        BeginMode3D(camera);
        cubePosition.x = -5.0f;
        for (int y = 0; current_map[y] != NULL; y++) {
            for (int x = 0; x != MAP_SIZE; x++) {
                if (current_map[y][x] == UNBREAKABLE_WALL) {
                    DrawCubeTexture(brick_tx, cubePosition, 1.0, 1.0, 1.0, WHITE);
                    DrawCubeWires(cubePosition, 1.0, 1.0, 1.0, BLACK);
                } else if (current_map[y][x] == BREAKABLE_WALL) {
                    DrawCubeTexture(wood_tx, cubePosition,  1.0, 1.0, 1.0, WHITE);
                    DrawCubeWires(cubePosition, 1.0, 1.0, 1.0, BLACK);
                }
                cubePosition.x += 1;
            }
            cubePosition.x = -5.0f;
            cubePosition.z += 1;
        }
        cubePosition.z = 5.0f;
        cubePosition.x = 0.0f;
        DrawCubeTexture(grass_tx, cubePosition, 10.0f, 0.0f, 10.0f, WHITE);
        DrawCubeWires(cubePosition, 10.0f, 0.0f, 10.0f, BLACK);
        cubePosition.x = -5.0f;
        cubePosition.z = 0;
        if (is_solo) {
            DrawModelEx(this->player_blue, { player1.x, player1.y, player1.z }, (Vector3){ 0.0f, 1.0f, 0.0f }, pivot1, (Vector3){ 0.5f, 0.5f, 0.5f }, WHITE);
            Bomberman::move_bot();
        } else {
            DrawModelEx(this->player_blue, { player1.x, player1.y, player1.z }, (Vector3){ 0.0f, 1.0f, 0.0f }, pivot1, (Vector3){ 0.5f, 0.5f, 0.5f }, WHITE);
            DrawModelEx(this->player_red, { player2.x, player2.y, player2.z }, (Vector3){ 0.0f, 1.0f, 0.0f }, pivot2, (Vector3){ 0.5f, 0.5f, 0.5f }, WHITE);
        }
        if (is_animation == true) {
            this->animation_bomb();
            this->check_victory();
            player1bomb = false;
            player2bomb = false;
        }
        EndMode3D();
    } else if (is_game_finish == true) {
        ClearBackground(RAYWHITE);
        if (win == PLAYER_ONE) {
            DrawTexture(this->win1_tx, this->screenWidth/2 - this->win1_tx.width/2,
            this->screenHeight/2 - this->win1_tx.height/2, WHITE);
            DrawText(MENU_OPTION, 1600, 900, 100, BLACK);
        } else if (win == PLAYER_TWO) {
            DrawTexture(this->win2_tx, this->screenWidth/2 - this->win2_tx.width/2,
            this->screenHeight/2 - this->win2_tx.height/2, WHITE);
            DrawText(MENU_OPTION, 1600, 900, 100, BLACK);
        }
        if (IsKeyPressed(KEY_ENTER) == true)
            return 1;
    }
    return 0;
}

void Bomberman::destroy_textures()
{
    UnloadTexture(this->background_tx);
    UnloadTexture(this->wood_tx);
    UnloadTexture(this->brick_tx);
    UnloadTexture(this->grass_tx);
    if (this->is_load == true) {
        UnloadModel(player_blue);
        UnloadModel(player_red);
    }
    UnloadTexture(this->win1_tx);
    UnloadTexture(this->win2_tx);
}