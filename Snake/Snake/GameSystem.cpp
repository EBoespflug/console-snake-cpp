#include "GameSystem.hpp"

#include <cassert>

#include "Map.hpp"
#include "Snake.hpp"
#include "Event.hpp"

GameSystem::GameSystem(Map& map, Snake& snake, std::size_t vs) :
    map_{ map },
    snake_{ snake },
    victorySize{ vs }
{ }

GameSystem::GameState GameSystem::handleEvent(Event event)
{
    if (state_ != GameState::PLAYING)
        return state_;
    if (event == Event::NONE)
        return state_;
    if (event == Event::USER_INPUT_EXIT)
        return state_ = GameState::LOSE;

    pos targetPos{};
    if (event == Event::USER_INPUT_DOWN)
    {
        targetPos = {snake_.head().x, (snake_.head().y >= map_.height - 1) ? 0u : snake_.head().y + 1};
    }
    else if (event == Event::USER_INPUT_UP)
    {
        targetPos = { snake_.head().x, (snake_.head().y == 0u) ? map_.height - 1 : snake_.head().y - 1 };
    }
    else if (event == Event::USER_INPUT_LEFT)
    {
        targetPos = { (snake_.head().x == 0u) ? map_.width - 1 : snake_.head().x - 1,  snake_.head().y };
    }
    else if (event == Event::USER_INPUT_RIGHT)
    {
        targetPos = { (snake_.head().x >= map_.width - 1) ? 0u : snake_.head().x + 1,  snake_.head().y };
    }
    else
        return state_;

    assert(map_.isValid(targetPos) && "Invalid snake position.");

    if (snake_.isPresent(targetPos))
        return state_ = GameState::LOSE;

    snake_.newHead(targetPos);
    if (map_.isFood(targetPos))
    {
        do map_.generateFood();  // Food shouldn't pop on the snake.
        while (snake_.isPresent(map_.foodPos()));
    }
    else
        snake_.removeTail();

    if (snake_.size() >= victorySize)
        return state_ = GameState::VICTORY;

    return state_;
}
