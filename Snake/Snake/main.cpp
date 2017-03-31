#include "Game.hpp"
#include "Map.hpp"
#include "Snake.hpp"

constexpr auto MAP_WIDTH{ 15u };
constexpr auto MAP_HEIGHT{ 10u };
constexpr auto MAX_SNAKE_SIZE{ 16u };

int main()
{
    Map map(MAP_WIDTH, MAP_HEIGHT);
    Snake snake({ 0, MAP_HEIGHT / 2 });
    play(map, snake, MAX_SNAKE_SIZE);
}