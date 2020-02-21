/*
** EPITECH PROJECT, 2020
** Skill or Die
** File description:
** TimeFactor.hpp
*/

#pragma once

//#include <list>
#include <SFML/Audio.hpp> // tmp

using namespace std;
using namespace sf; // tmp

class TimeFactor
{
public:
    static const float &get();
    static void set(const float &_value);

private:
    TimeFactor();
    ~TimeFactor() = default;
    TimeFactor(const TimeFactor &timeFactor) = delete;

private:
    static TimeFactor instance;
    float value;

private:
    Music music; // tmp
};
