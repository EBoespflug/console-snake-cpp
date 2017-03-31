#include "Snake.hpp"

#include <cassert>
#include <algorithm>

Snake::Snake(pos head) :
    body_{ head }
{}

const pos& Snake::head() const
{
    assert(body_.size() > 0 && "Snake size have to be greater than zero.");
    return *body_.begin();
}

bool Snake::isPresent(const pos& p) const
{
    return std::find(body_.begin(), body_.end(), p) != body_.end();
}

void Snake::newHead(pos p)
{
    body_.push_front(p);
}
void Snake::removeTail()
{
    body_.pop_back();
    assert(body_.size() > 0 && "Snake size have to be greater than zero.");
}