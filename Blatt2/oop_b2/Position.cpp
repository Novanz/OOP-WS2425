//
// Created by nan on 10/15/24.
//

#include "Position.h"
int Position::getY() const {
    return m_y;
}
int Position::getX() const {
    return m_x;
}
const std::string &Position::getName() const { // Warum geben wir eine Referenz zurück?
    return m_name;
}
void Position::set(const std::string &name, int x, int y) { // wieso benutzt man hier eine Referenz?
    m_name = name; // was ist besser bzw. richtig? dies
    this->m_y = y; // oder das?
    this->m_x = x;
}
