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

#define TimeFactorInstance TimeFactor::getInstance()

class TimeFactor
{
public:
    TimeFactor();
    static TimeFactor &getInstance();
    const float &get() const;
    void set(const float &_value);

private:
    static TimeFactor instance;
    float value;

private:
    Music music; // tmp
};
