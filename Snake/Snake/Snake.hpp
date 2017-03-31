#pragma once
#ifndef SNAKE_HPP
#define SNAKE_HPP

#include <deque>
#include "Map.hpp"

class Snake
{
public:
    Snake(pos head);
    Snake(const Snake&) = delete;
    Snake& operator=(const Snake&) = delete;

    bool isPresent(const pos& p) const;
    void newHead(pos p);
    void removeTail();

    const pos& head() const;
    size_t size() const { return body_.size(); }
private:
    std::deque<pos> body_;
};

#endif // SNAKE_HPP