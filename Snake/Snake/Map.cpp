#include "Map.hpp"

#include <cassert>

bool operator== (const pos& a, const pos& b)
{
    return a.x == b.x && a.y == b.y;
}

Map::Map(size_t w, size_t h) :
    width{ w },
    height{ h },
    distWidth_{ 0u, width - 1 },
    distHeight_{ 0u, height - 1 },
    rng_{ std::random_device{}() }
{ 
    generateFood();
}

bool Map::isValid(const pos& p) const
{
    return p.x < width && p.y < height;
}

void Map::generateFood()
{
    miam_ = { distWidth_(rng_), distHeight_(rng_) };
    assert(isValid(miam_) && "Invalid food position.");
}

bool Map::isFood(const pos& p) const
{
    return p == miam_;
}