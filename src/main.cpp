/*
** EPITECH PROJECT, 2022
** Indie_Studio
** File description:
** main
*/

#include "game.hpp"

void loop_function();

int main(void)
{
    srand(time(0)); //each timer rand is executed diferent value
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_NAME);
    SetTargetFPS(FPS);
    loop_function();
    CloseWindow();     
    StopSoundMulti();
    CloseAudioDevice();    
    return (0);
}