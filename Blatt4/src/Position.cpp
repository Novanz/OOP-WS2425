//
// Created by nan on 10/15/24.
//
#include "Position.h"


int nan::Position::getY() const {
    return m_y;
}
int nan::Position::getX() const {
    return m_x;
}
const std::string &nan::Position::getName() const {
    return m_name;
}

// Return values:
// 0 == equals( all members have same value),
// 1 == this.name lexicographically > other.name || any of this.x/y > other.x/y,
// -1 ==  this.name lexicographically < other.name || any of this.x/y < other.x/y
int nan::Position::compare(const nan::Position& other) const {
    if (m_name < other.m_name) {
        return -1;
    } else if (m_name > other.m_name) {
        return 1;
    }

    if (m_x < other.m_x) {
        return -1;
    } else if (m_x > other.m_x) {
        return 1;
    }

    if (m_y < other.m_y) {
        return -1;
    } else if (m_y > other.m_y) {
        return 1;
    }

    return 0;
}

nan::Position::Position(const std::string &mName, int mX, int mY) : m_name(mName), m_x(mX), m_y(mY) {}

