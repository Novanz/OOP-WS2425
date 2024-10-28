//
// Created by nan on 10/15/24.
//

#ifndef BLATT2_POSITION_H
#define BLATT2_POSITION_H

#include <string>
class Position {
private:
    std::string m_name; // TODO: Fragen ueber shadow und m_var
    int m_x;
    int m_y;
public:
    void set(const std::string& name, int x, int y);
    const std::string& getName() const;
    int getX() const;
    int getY() const;
};


#endif//BLATT2_POSITION_H
