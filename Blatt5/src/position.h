//
// Created by nan on 10/15/24.
//

#ifndef BLATT2_POSITION_H
#define BLATT2_POSITION_H

#include <string>

namespace nan {
    class position {
    private:
        std::string m_name;
        int m_x;
        int m_y;

    public:
        position(const std::string &mName, int mX, int mY);
        const std::string &getName() const;
        int getX() const;
        int getY() const;
        int compare(const position& other) const;
    };

}
#endif//BLATT2_POSITION_H
