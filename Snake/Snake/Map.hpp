#pragma once
#ifndef MAP_HPP
#define MAP_HPP

#include <random>

struct pos
{
    size_t x;
    size_t y;
};

bool operator==(const pos& a, const pos& b);
inline bool operator!=(const pos& a, const pos& b) { return !(a == b); }

class Map
{
public:
    Map(size_t w, size_t h);
    Map(const Map&) = delete;
    Map& operator=(const Map&) = delete;

    const size_t height;
    const size_t width;

    bool isValid(const pos& p) const;
    void generateFood();
    bool isFood(const pos& p) const;
    pos foodPos() const { return miam_; }

private:
    pos miam_;

    std::mt19937 rng_;
    std::uniform_int_distribution<size_t> distWidth_;
    std::uniform_int_distribution<size_t> distHeight_;
};

#endif // MAP_HPP