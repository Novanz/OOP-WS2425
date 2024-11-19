//
// Created by nan on 10/15/24.
//

#ifndef BLATT2_POSITION_H
#define BLATT2_POSITION_H

#include <string>
#include <compare>
#include <ostream>

namespace nan {
    class Position {
    private:
        std::string m_name;
        int m_x;
        int m_y;

        int compare(const Position &other) const;

    public:
        Position(const std::string &mName, int mX, int mY);
        const std::string &getName() const;
        int getX() const;
        int getY() const;

        // Spaceship operator:
        // When you provide the spaceship operator, the compiler will:
        //      • Use operator<=> to implement <, >, <=, and >=
        //      • Use the defaulted operator== for equality comparisons
        //      • Generate != as the logical opposite of ==

        auto operator<=>(const Position &other) const = default;
        bool operator==(const Position &other) const = default;

        friend std::ostream &operator<<(std::ostream &os, const Position &position);
    };

}
#endif//BLATT2_POSITION_H