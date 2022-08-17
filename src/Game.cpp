/*
** EPITECH PROJECT, 2022
** Game.cpp
** File description:
** Game
*/

#include "game.hpp"

void Game::draw_function() {
    ClearBackground(RAYWHITE);
    if (this->scene == INTRO)
        DrawTexture(this->intro_tx, this->screenWidth/2 - this->intro_tx.width/2,
            this->screenHeight/2 - this->intro_tx.height/2, WHITE);
    else if (this->scene == MAIN_MENU)
        draw_menu_one();
    else if ((this->scene == SETTINGS) || this->scene == GAME_MENU)
        DrawTexture(this->menu_tx, this->screenWidth/2 - this->menu_tx.width/2,
            this->screenHeight/2 - this->menu_tx.height/2, WHITE);
    else if (this->scene == SAVED_NEWGAME)
        DrawTexture(this->smenu_tx, this->screenWidth/2 - this->smenu_tx.width/2,
            this->screenHeight/2 - this->smenu_tx.height/2, WHITE);
    else if (this->scene == SOLO_MULTIPLAYER)
        DrawTexture(this->pmenu_tx, this->screenWidth/2 - this->pmenu_tx.width/2,
            this->screenHeight/2 - this->pmenu_tx.height/2, WHITE);
    if (this->scene == SETTINGS) {
        if (this->button == 0)
            DrawTexture(this->bomb_tx, 275, 250, WHITE);
        else if (this->button == 1)
            DrawTexture(this->bomb_tx, 275, 450, WHITE);
        else if (this->button == 2)
            DrawTexture(this->bomb_tx, 655, 650, WHITE); 
        DrawText(MUSIC_TEXT, 400, 250, 125, BLACK);
        DrawText(TextFormat("< %.0f%% >", music_volume * 100 - 10), 1000, 250, 125, BLACK);
        DrawText(SOUND_TEXT, 400, 450, 125, BLACK);
        DrawText(TextFormat("< %.0f%% >", sound_volume * 100 - 10), 1000 , 450, 125, BLACK);
        DrawText(BACK_TEXT, 780, 650, 125, BLACK);
    }
    if (scene == SAVED_NEWGAME) {
        if (this->button == 0)
            DrawTexture(this->bomb_tx, 260, 270, WHITE);
        else if (this->button == 1)
            DrawTexture(this->bomb_tx, 260, 460, WHITE);
        else if (this->button == 2)
            DrawTexture(this->bomb_tx, 470, 670, WHITE); 
    }
    if (scene == SOLO_MULTIPLAYER) {
        if (this->button == 0)
            DrawTexture(this->bomb_tx, 40, 250, WHITE);
        else if (this->button == 1)
            DrawTexture(this->bomb_tx, 40, 500, WHITE);
        else if (this->button == 2)
            DrawTexture(this->bomb_tx, 40, 750, WHITE);
    }
    if (scene == GAME_MENU) {
        if (this->button == 0)
            DrawTexture(this->bomb_tx, 460, 270, WHITE);
        else if (this->button == 1)
            DrawTexture(this->bomb_tx, 460, 460, WHITE);
        else if (this->button == 2)
            DrawTexture(this->bomb_tx, 460, 670, WHITE); 
    }
}

void Game::init_textures() {
    Image welcome = LoadImage(INTRO_MENU);
    this->intro_tx = LoadTextureFromImage(welcome);
    UnloadImage(welcome);

    Image menu = LoadImage(MENU);
    this->menu_tx = LoadTextureFromImage(menu);
    UnloadImage(menu);

    Image bomb = LoadImage(BOMB);
    this->bomb_tx = LoadTextureFromImage(bomb);
    UnloadImage(bomb);

    Image sON = LoadImage(SOUND_ON);
    this->sOn_tx = LoadTextureFromImage(sON);
    UnloadImage(sON);

    Image sOf = LoadImage(SOUND_OFF);
    this->sOf_tx = LoadTextureFromImage(sOf);
    UnloadImage(sOf);

    Image left_g = LoadImage(LEFT_G);
    this->leftG_tx = LoadTextureFromImage(left_g);
    UnloadImage(left_g);

    Image left_c = LoadImage(LEFT_C);
    this->leftC_tx = LoadTextureFromImage(left_c);
    UnloadImage(left_c);

    Image mid_c = LoadImage(MID_C);
    this->midC_tx = LoadTextureFromImage(mid_c);
    UnloadImage(mid_c);

    Image mid_g = LoadImage(MID_G);
    this->midG_tx = LoadTextureFromImage(mid_g);
    UnloadImage(mid_g);

    Image right_g = LoadImage(RIGHT_G);
    this->rightG_tx = LoadTextureFromImage(right_g);
    UnloadImage(right_g);

    Image right_c = LoadImage(RIGHT_C);
    this->rightC_tx = LoadTextureFromImage(right_c);
    UnloadImage(right_c);

    Image Smenu = LoadImage(SMENU);
    this->smenu_tx = LoadTextureFromImage(Smenu);
    UnloadImage(Smenu);

    Image Pmenu = LoadImage(PMENU);
    this->pmenu_tx = LoadTextureFromImage(Pmenu);
    UnloadImage(Pmenu);
}

void Game::draw_menu_one() {
    if (this->button == 0) {
        DrawTexture(this->leftC_tx, 0, 0, WHITE);
        DrawTexture(this->midG_tx, 640, 0, WHITE);
        DrawTexture(this->rightG_tx, 1280, 0, WHITE);
    } else if (this->button == 1) {
        DrawTexture(this->leftG_tx, 0, 0, WHITE);
        DrawTexture(this->midC_tx, 640, 0, WHITE);
        DrawTexture(this->rightG_tx, 1280, 0, WHITE);
    } else if (this->button == 2) {
        DrawTexture(this->leftG_tx, 0, 0, WHITE);
        DrawTexture(this->midG_tx, 640, 0, WHITE);
        DrawTexture(this->rightC_tx, 1280, 0, WHITE);
    }
}

void Game::init_music() {
    InitAudioDevice();
    this->MenuMusic = LoadMusicStream(MENU_MUSIC);
    SetMusicVolume(this->MenuMusic, 0.4);
    this->ButtonSound = LoadSound(BUTTON_SOUND);
    SetSoundVolume(this->ButtonSound, 0.2);
    this->GameMusic = LoadMusicStream(GAME_MUSIC);
    SetMusicVolume(this->GameMusic, 0.4);
    PlayMusicStream(this->MenuMusic);
}

void Game::handle_buttons() {
    if (this->scene != 1) {
        if (IsKeyPressed(KEY_DOWN) == true && (this->button == 0 || this->button == 1)) {
            this->button++;
            PlaySoundMulti(this->ButtonSound);
        }
        if (IsKeyPressed(KEY_UP) == true && (this->button == 1 || this->button == 2)) {
            this->button--;
            PlaySoundMulti(this->ButtonSound);
        }
    } else {
        if (IsKeyPressed(KEY_RIGHT) == true && (this->button == 0 || this->button == 1)) {
            this->button++;
            PlaySoundMulti(this->ButtonSound);
        }
        if (IsKeyPressed(KEY_LEFT) == true && (this->button == 1 || this->button == 2)) {
            this->button--;
            PlaySoundMulti(this->ButtonSound);
        }
    }
}

void Game::check_is_loadfiles()
{
    ifstream file;
    string line;
    bool is_mapfile = false;
    bool is_variables_file = false;
    int i = 0;

    file.open(SAVE_MAP);
    while (getline(file, line))
        i++;
    if (i == 12)
        is_mapfile = true;
    i = 0;
    file.close();
    file.open(SAVE_VARIABLES);
    while (getline(file, line))
        i++;
    if (i == 7)
        is_variables_file = true;

    if (is_mapfile == true && is_variables_file == true)
        is_load_file = true;
}

void Game::musicAndSound() {
    if (this->button == 0) {
        if (IsKeyPressed(KEY_RIGHT) == true && music_volume < 1.1f) {
            music_volume += 0.1f;
            SetMusicVolume(MenuMusic, music_volume + 0.1);
            SetMusicVolume(GameMusic, music_volume + 0.1);
        }
        else if (IsKeyPressed(KEY_LEFT) == true && music_volume > 0.2f) {
            music_volume -= 0.1f;
            SetMusicVolume(MenuMusic, music_volume - 0.1);
            SetMusicVolume(GameMusic, music_volume - 0.1);
        }
    } else if (button == 1) {
        if (IsKeyPressed(KEY_RIGHT) == true && sound_volume < 1.1f) {
            sound_volume += 0.1f;
            SetSoundVolume(ButtonSound, sound_volume + 0.1);
        }
        else if (IsKeyPressed(KEY_LEFT) == true && sound_volume > 0.2f) {
            sound_volume -= 0.1f;
            SetSoundVolume(ButtonSound, sound_volume - 0.1);
        }
    }
}

void Game::sceneZero() {
    if (IsKeyPressed(KEY_ENTER) == true) {
        this->scene = 1;
        PlaySoundMulti(this->ButtonSound);
    } 
}

int Game::sceneOne() {
    if (IsKeyPressed(KEY_ENTER) == true && this->button == 0) {
        this->scene = 2;
        this->button = 0;
        PlaySoundMulti(this->ButtonSound);
    } else if (IsKeyPressed(KEY_ENTER) == true && this->button == 1) {
        this->scene = 3;
        this->button = 0;
        PlaySoundMulti(this->ButtonSound);
    } else if (IsKeyPressed(KEY_ENTER) == true && this->button == 2) {
        PlaySoundMulti(this->ButtonSound);
        return (1);
    }
    this->handle_buttons();
    return (0);
}

void Game::settings_scene() {
    this->handle_buttons();
    this->musicAndSound();
    this->f_call = 1;
    if (IsKeyPressed(KEY_ENTER) == true && (this->button == 2)) {
        if (this->is_pause == 0) {
            this->button = 1;
            this->scene = 1;
        } else if (this->is_pause == 1) {
            this->scene = 6;
            this->is_pause = 0;
            button = 0;
        }
        this->f_call = 0;
        PlaySoundMulti(this->ButtonSound);
    }
}

int Game::sceneThree() {
    this->check_is_loadfiles();
    if (IsKeyPressed(KEY_ENTER) == true && this->button == 0 && this->is_load_file == true) {
        this->button = 0;
        this->scene = 5;
        PlaySoundMulti(this->ButtonSound);
        this->continu = 1;
        return (1);
    }
    if (IsKeyPressed(KEY_ENTER) == true && this->button == 1) {
        this->button = 0;
        this->scene = 4;
        PlaySoundMulti(this->ButtonSound);
        this->continu = 2;
        return (1);
    } else if (IsKeyPressed(KEY_ENTER) == true && this->button == 2) {
        this->button = 1;
        this->scene = 1;
        PlaySoundMulti(this->ButtonSound);
    }
    this->handle_buttons();
    return (0);
}

int Game::sceneFour() {
    if (IsKeyPressed(KEY_ENTER) == true && (this->button == 0 || this->button == 1)) {
        this->scene = 5;
        PlaySoundMulti(this->ButtonSound);
        return (1);
    }
    if (IsKeyPressed(KEY_ENTER) == true && this->button == 2) {
        this->button = 0;
        this->scene = 3;
        PlaySoundMulti(this->ButtonSound);
    }
    this->handle_buttons();
    return (0);
}

void Game::sceneFive() {
    if (IsKeyPressed(KEY_ESCAPE) == true) {
        this->scene = 6;
        PlaySoundMulti(this->ButtonSound);
    }
    this->is_in_game = true;
}

int Game::sceneSix() {
    if (IsKeyPressed(KEY_ESCAPE) == true || (IsKeyPressed(KEY_ENTER) == true && this->button == 0)) {
        this->scene = 5;
        PlaySoundMulti(this->ButtonSound);
    } else if (IsKeyPressed(KEY_ENTER) == true && this->button == 2) {
        PlaySoundMulti(this->ButtonSound);
        return (1);
    } else if(IsKeyPressed(KEY_ENTER) == true && this->button == 1) {
        this->scene = 2;
        this->is_pause = 1;
        button = 0;
        PlaySoundMulti(this->ButtonSound);
    } 
    this->handle_buttons();
    return (0);
}

void Game::destroy_textures() {
    UnloadTexture(this->intro_tx);
    UnloadTexture(this->main_menu_tx);
    UnloadTexture(this->menu_tx);
    UnloadTexture(this->bomb_tx);
    UnloadTexture(this->leftC_tx);
    UnloadTexture(this->leftG_tx);
    UnloadTexture(this->midC_tx);
    UnloadTexture(this->midG_tx);
    UnloadTexture(this->rightC_tx);
    UnloadTexture(this->rightG_tx);
    UnloadTexture(this->smenu_tx);
    UnloadTexture(this->pmenu_tx);
    UnloadTexture(this->sOn_tx);
    UnloadTexture(this->sOf_tx);
}