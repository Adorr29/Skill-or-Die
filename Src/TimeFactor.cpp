/*
** EPITECH PROJECT, 2020
** Skill or Die
** File description:
** TimeFactor.cpp
*/

#include "TimeFactor.hpp"

TimeFactor TimeFactor::instance;

const float &TimeFactor::get()
{
    return instance.value;
}

void TimeFactor::set(const float &_value)
{
    instance.value = _value;
    instance.music.setPitch(instance.value);
}

TimeFactor::TimeFactor()
    : value(1.0)
{
    if (music.openFromFile("Resources/Music/Megalovania.ogg"))
        music.play();
}
