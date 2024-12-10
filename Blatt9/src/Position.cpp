//
// Created by novan on 10/15/24.
//
#include "Position.h"

novan::Position::Position(const std::string &mName, int mX, int mY) : m_name(mName), m_x(mX), m_y(mY) {}

int novan::Position::getY() const { return m_y; }


int novan::Position::getX() const { return m_x; }
const std::string &novan::Position::getName() const { return m_name; }

// Return values:
// 0 == equals( all members have same value),
// 1 == this.name lexicographically > other.name || any of this.x/y > other.x/y,
// -1 ==  this.name lexicographically < other.name || any of this.x/y < other.x/y

int novan::Position::compare(const novan::Position &other) const {
    if (m_name < other.m_name) { return -1; } else if (m_name > other.m_name) { return 1; }

    if (m_x < other.m_x) { return -1; } else if (m_x > other.m_x) { return 1; }

    if (m_y < other.m_y) { return -1; } else if (m_y > other.m_y) { return 1; }

    return 0;
}

std::strong_ordering novan::Position::operator<=>(const novan::Position &other) const{
    int result = compare(other);
    if (result < 0) return std::strong_ordering::less;
    if (result > 0) return std::strong_ordering::greater;
    return std::strong_ordering::equal;
}

std::ostream &novan::operator<<(std::ostream &os, const Position &position) {
    os
            << "Name: " << position.getName() << ", "
            << "x = " << position.getX() << ", "
            << "y = " << position.getY() << std::endl;
    return os;
}