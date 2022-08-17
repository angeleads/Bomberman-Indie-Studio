/*
** EPITECH PROJECT, 2022
** B-YEP-400-BAR-4-1-indiestudio-blanca.sibecas-hernandez
** File description:
** bot
*/

#include "bomber.hpp"

bool Bomberman::bot_check_wall_front(int line, int column)
{
    if (current_map[line - 1][column] == 'x' && current_map[line - 1][column] == 'a')
        return (true);
    return (false);
}

bool Bomberman::bot_check_wall_back(int line, int column)
{
    if (current_map[line + 1][column] == 'x' && current_map[line + 1][column] == 'a')
        return (true);
    return (false);
}

bool Bomberman::bot_check_wall_right(int line, int column)
{
    if (current_map[line][column + 1] == 'x' && current_map[line][column + 1] == 'a')
        return (true);
    return (false);
}

bool Bomberman::bot_check_wall_left(int line, int column)
{
    if (current_map[line][column - 1] == 'x' && current_map[line][column - 1] == 'a')
        return (true);
    return (false);
}