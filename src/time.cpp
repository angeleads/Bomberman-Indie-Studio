/*
** EPITECH PROJECT, 2022
** B-YEP-400-BAR-4-1-indiestudio-blanca.sibecas-hernandez
** File description:
** time
*/

#include "bomberman.hpp"

void Bomberman::start_clock()
{
    m_StartTime = chrono::system_clock::now();
    m_bRunning = true;
}

void Bomberman::stop()
{
    m_EndTime = chrono::system_clock::now();
    m_bRunning = false;
}

void Bomberman::restart()
{
    m_StartTime = chrono::system_clock::now();
}

double Bomberman::elapsedMilliseconds()
{
    std::chrono::time_point<std::chrono::system_clock> endTime;
    if (m_bRunning) {
        endTime = std::chrono::system_clock::now();
    }
    else {
        endTime = m_EndTime;
    }
    return chrono::duration_cast<std::chrono::milliseconds>(endTime - m_StartTime).count();
}

double Bomberman::elapsedSeconds()
{
    return elapsedMilliseconds() / 1000.0;
}