#pragma once
#ifndef GAMESYSTEM_HPP
#define GAMESYSTEM_HPP

#include <cstddef>

enum class Event;
class Map;
class Snake;

class GameSystem
{
public:
    GameSystem(Map& map, Snake& snake_, std::size_t victorysize);
    GameSystem(const GameSystem&) = delete;
    GameSystem& operator=(const GameSystem&) = delete;

    enum class GameState{ PLAYING, VICTORY, LOSE };
    GameState handleEvent(Event event);

    const std::size_t victorySize;
private:
    GameState state_{ GameState::PLAYING };
    Snake& snake_;
    Map& map_;
};

#endif // GAMESYSTEM_HPP
