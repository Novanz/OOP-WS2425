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
        Position();
        ~Position();
        const std::string &getName() const;
        int getX() const;
        int getY() const;
        // TODO: Wo schreibt man Doku zu Methode? Hier oder in .h?
        int compare(Position other);
        std::string to_string();
    };

}
#endif//BLATT2_POSITION_H
