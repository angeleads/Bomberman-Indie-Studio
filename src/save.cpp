/*
** EPITECH PROJECT, 2022
** B-YEP-400-BAR-4-1-indiestudio-blanca.sibecas-hernandez
** File description:
** save
*/

#include "bomber.hpp"

void Bomberman::load_map()
{
    ifstream map;
    string line;
    int i = 0;
    for (int i = 0; current_map[i] != NULL; i++)
        free(current_map[i]);
    free(current_map);
    this->current_map = (char **)malloc(sizeof(char *) * 12);
    for (int i = 0; i != 12; i++)
        this->current_map[i] = (char *)malloc(sizeof(char) * 12);
    map.open("save/SaveMap.txt");
    while (getline(map, line)) {
        strcpy(current_map[i], line.c_str());
        i++;
    }
    current_map[i] = NULL;
    if (this->is_load == false) {
        this->init_textures();
        this->is_load = true;
    }
    map.close();
}

void Bomberman::load_variables()
{ 
    ifstream variables;
    string line;
    int indice = 0;
    variables.open("save/SaveVariables.txt");
    while (getline(variables, line)) {
        switch (indice) {
            case 0:
                if (line == "1")
                    this->is_solo = true;
                else
                    this->is_multi = true;
            case 1:
                player1.x = stof(line);
            case 2:
                player1.y = stof(line);
            case 3:
                player1.z = stof(line);
            case 4:
                player2.x = stof(line);
            case 5:
                player2.y = stof(line);
            case 6:
                player2.z = stof(line);
        }
        indice++;
    }
    variables.close();
}

void Bomberman::resetGame()
{
    this->player1 = { -4.0f, 0.0f, 1.0f };
    this->player2 = { 4.0f, 0.0f, 9.0f };
    this->is_solo = false;
    this->is_multi = false;
    bool player1_win = false;
    bool player2_win = false;
    player1bomb = false;
    player2bomb = false;
    is_game_finish = false;
}

void Bomberman::save_map()
{
    ofstream SaveFile;
    SaveFile.open("save/SaveMap.txt");
    for (int i = 0; current_map[i] != NULL; i++) {
        for (int j = 0; current_map[i][j] != '\0'; j++)
            SaveFile << current_map[i][j];
        if (current_map[i + 1] != NULL)
            SaveFile << endl;
    }
    SaveFile << endl;
}

void Bomberman::save_variables(int nb)
{
    ofstream SaveFile;
    SaveFile.open("save/SaveVariables.txt");
    SaveFile << nb << "\n";
    SaveFile << player1.x << "\n";
    SaveFile << player1.y << "\n";
    SaveFile << player1.z << "\n";
    SaveFile << player2.x << "\n";
    SaveFile << player2.y << "\n";
    SaveFile << player2.z << "\n";
    SaveFile.close();
}

void Bomberman::saveFunctions()
{    
    int nb_player = 1;
    if (this->is_multi == true)
        nb_player = 2;
    this->save_variables(nb_player);
    this->save_map();
}