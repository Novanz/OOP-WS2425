//
// Created by novan on 10.12.24.
//
#include <iostream>
#include "../src/Position.h"
#include "../src/City.h"
#include <cassert>

novan::Position createPosition() {
    std::string mordor = "Mordor";
    novan::Position result(mordor, 47, 11);
    return result;
}

novan::City createCity() {
    auto position = createPosition();
    std::string pois[] = {"Sauron", "Minas Morgul", "Orodruin"};
    novan::City result("Mordor", 47, 11, pois, 3);
    return result;
}

void testPosition() {
    auto position = createPosition();
    std::cout << position << std::endl;
}

void testCity() {
    auto city = createCity();
    std::cout << city << std::endl;
}

void testIndexOperator() {
    auto city = createCity();
    assert(city[0] == "Sauron");
    assert(city[1] == "Minas Morgul");
    assert(city[2] == "Orodruin");
    try {
        city[3];
        assert(false);
    } catch (...) {}
    try {
        city[-1];
        assert(false);
    } catch (...) {}
    city[0] = "Gandalf";
    assert(city[0] == "Gandalf");
    try {
        city[3] = "Gandalf";
        assert(false);
    } catch (...) {}
    try {
        city[-1] = "Gandalf";
        assert(false);
    } catch (...) {}
    const auto constCity = createCity();
    assert(constCity[0] == "Sauron");
}

void testCityTemplate() {
    std::string pois_morder[]={"Sauron", "Minas Morgul", "Orodruin"};
    novan::City left("Mordor", 47, 11,pois_morder,3);
    std::string pois_arrakis[]={"Arrakeen", "Desert"};
    novan::City right("Arrakis", 23, 42,pois_arrakis,2);
    std::cout << "Left: " << left << std::endl;
    left=right;
    std::cout << " New Left: " << left << std::endl;
    assert(left.getName()=="Arrakis");
    assert(left.getX()==23);
    assert(left.getY()==42);
    assert(left.getNumberOfPOIs()==2);
    assert(left[0]==pois_arrakis[0]);
    assert(left[1]==pois_arrakis[1]);
}

int main() {
    std::cout << "starting tests..." << std::endl;
    testIndexOperator();
    testCityTemplate();
    std::cout << "...finished" << std::endl;
}