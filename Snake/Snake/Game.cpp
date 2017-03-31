#include "Game.hpp"

#include <iostream>

#include "Map.hpp"
#include "Snake.hpp"
#include "GameSystem.hpp"
#include "Event.hpp"

using std::cout;

void play(Map& map, Snake& snake, size_t victoryCondition)
{
    draw(map, snake);
    GameSystem gs(map, snake, victoryCondition);

    GameSystem::GameState state{ GameSystem::GameState::PLAYING };
    while (state == GameSystem::GameState::PLAYING)
    {
        state = gs.handleEvent(getEvent());
        draw(map, snake);
    }

    if (state == GameSystem::GameState::LOSE)
    {
        cout << "Sorry, try again !\n" << std::endl;
    }
    if (state == GameSystem::GameState::VICTORY)
    {
        cout << "You won, good job !" << std::endl;
    }

    system("pause");

    return;
}

Event getEvent()
{
    char input{};
    std::cin >> input;

    switch (input)
    {
    case 'z': case 'Z':
        return Event::USER_INPUT_UP;
    case 's': case 'S':
        return Event::USER_INPUT_DOWN;
    case 'q': case 'Q': case 'a': case 'A':
        return Event::USER_INPUT_LEFT;
    case 'd': case 'D':
        return Event::USER_INPUT_RIGHT;
    case 'e': case 'E':
        return Event::USER_INPUT_EXIT;
    default:
        return Event::NONE;
    }
}

void draw(const Map& map, const Snake& snake)
{
#ifdef __unix__
    system("clear");
#else
    system("cls");
#endif
    cout << "Score = " << (snake.size() - 1) * 100 << '\n';
    /* Draw game. */
    for (size_t i{}; i < map.width + 2; ++i)
        cout << '#';
    cout << '\n';
    for (size_t i{}; i < map.height; ++i)
    {
        cout << '#';
        for (size_t j{}; j < map.width; ++j)
        {
            pos p{ j, i };
            if (snake.head() == p)
                cout << 'X';
            else if (snake.isPresent(p))
                cout << 'O';
            else if (map.isFood(p))
                cout << '~';
            else
                cout << ' ';
        }
        cout << "#\n";
    }
    for (size_t i{}; i < map.width + 2; ++i)
        cout << '#';
    cout << '\n';

    /* Draw UI. */
    cout << "Snake move (z/q/s/d) : ";
}