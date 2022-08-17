/*
** EPITECH PROJECT, 2022
** Indie_Studio
** File description:
** read_map_file
*/

#include "bomberman.hpp"
#include <fstream>
#include <stdlib.h>
#include <string.h>

void Bomberman::remove_random_walls()
{
    int counter = 0;
    int i = 3;
    int j = 0;
    //this->current_map[i][j];

    srand (time(NULL));
    while (counter != 3) {
        j = rand() % 9 + 1;
        if (this->current_map[i][j] == 'w') {
            this->current_map[i][j] = 'o';
            counter++;
            i += 2;
        }
    }
    j = 3;
    while (counter != 6) {
        i = rand() % 9 + 1;
        if (this->current_map[i][j] == 'w') {
            this->current_map[i][j] = 'o';
            counter++;
            j += 2;
        }
    }
}

void Bomberman::save_original_map()
{
    int i = 0;

    this->current_map = (char **)malloc(sizeof(char *) * 12);
    for (; i != 12; i++) {
        this->current_map[i] = (char *)malloc(sizeof(char) * 12);
        strcpy(this->current_map[i], this->original_map[i]);
    }
    this->current_map[i] = NULL;
    this->remove_random_walls();
}

void Bomberman::read_from_file()
{
    ifstream fin;
    fin.open(MAP, ios::in);
    int i = 0;
    int j = 0;
    int h = 0;
    char test[420];
    char ch ;

    this->original_map = (char **)malloc(sizeof(char *) * 12);
    for (int i = 0; i != 12; i++)
        this->original_map[i] = (char *)malloc(sizeof(char) * 12);
    i = 0;
	while (!fin.eof()) {
        fin.get(ch);
        test[i] = ch;
        i++;
	}
    test[i - 1] = '\0';

    for (i = 0; test[i] != '\0'; i++) {
        if (test[i] == '\n') {
            this->original_map[h][j] = '\0';
            j = -1;
            h++;
        }
        this->original_map[h][j] = test[i];
        j++;
    }
    this->original_map[h][j] = '\0';
    this->original_map[h + 1] = NULL;
    this->save_original_map();
}