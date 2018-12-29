#pragma once
#ifndef GAME_HPP
#define GAME_HPP

#include <cstddef>

class Map;
class Snake;
enum class Event;

Event getEvent();
void draw(const Map&, const Snake&);
void play(Map& map, Snake& snake, std::size_t victoryCondition);

#endif // GAME_HPP
