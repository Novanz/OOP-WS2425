//
// Created by nan on 10/15/24.
//

#ifndef BLATT2_POSITION_H
#define BLATT2_POSITION_H

#include <string>

namespace nan {
    class Position {
    private:
        std::string m_name;
        int m_x;
        int m_y;

    public:
        Position(const std::string &mName, int mX, int mY);
        Position(const Position &other);
        const std::string &getName() const;
        int getX() const;
        int getY() const;
        int compare(const Position& other) const;
    };

}
#endif//BLATT2_POSITION_H
