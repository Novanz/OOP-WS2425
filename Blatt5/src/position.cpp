//
// Created by nan on 10/15/24.
//
#include "position.h"


int nan::position::getY() const {
    return m_y;
}
int nan::position::getX() const {
    return m_x;
}
const std::string &nan::position::getName() const {
    return m_name;
}

// Return values:
// 0 == equals( all members have same value),
// 1 == this.name lexicographically > other.name || any of this.x/y > other.x/y,
// -1 ==  this.name lexicographically < other.name || any of this.x/y < other.x/y
int nan::position::compare(const nan::position& other) const {
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

nan::position::position(const std::string &mName, int mX, int mY) : m_name(mName), m_x(mX), m_y(mY) {}
