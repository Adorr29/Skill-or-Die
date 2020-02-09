/*
** EPITECH PROJECT, 2020
** Skill or Die
** File description:
** TimeFactor.hpp
*/

#include "TimeFactor.hpp"

TimeFactor TimeFactor::instance;

TimeFactor::TimeFactor()
    : value(1.0)
{
    if (music.openFromFile("Resources/Music/Megalovania.ogg"))
        music.play();
}

TimeFactor &TimeFactor::getInstance()
{
    return instance;
}

const float &TimeFactor::get() const
{
    return value;
}

void TimeFactor::set(const float &_value)
{
    value = _value;
    music.setPitch(value);
}
