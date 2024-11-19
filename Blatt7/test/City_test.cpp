//
// Created by nan on 10/29/24.
//

#include "../src/Position.h"
#include "../src/City.h"
#include <cassert>
#include <iostream>
#include <string>

nan::Position createPosition() {
    std::string mordor = "Mordor";
    nan::Position result(mordor, 47, 11);
    return result;
}

nan::City createCity() {
    auto position = createPosition();
    std::string pois[] = {"Sauron", "Minas Morgul", "Orodruin"};
    nan::City result("Mordor", 47, 11, pois, 3);
    return result;
}

void testCtor() {
    auto position = createPosition();
    std::string pois[] = {"Sauron", "Minas Morgul", "Orodruin"};
    nan::City city("Mordor", 47, 11, pois, 3);
    pois[0] = "Gandalf";
    assert(city.getPOI(0) == "Sauron");
}

void testGetNameXY() {
    auto position = createPosition();
    nan::City city("Mordor", 47, 11, nullptr, 0);
    assert(city.getName() == "Mordor");
    assert(city.getX() == 47);
    assert(city.getY() == 11);
}


void testGetPOI() {
    auto city = createCity();
    assert(city.getPOI(0) == "Sauron");
    assert(city.getPOI(1) == "Minas Morgul");
    assert(city.getPOI(2) == "Orodruin");
    try {
        city.getPOI(3);
        assert(false);
    } catch (...) {}
    try {
        city.getPOI(-1);
        assert(false);
    } catch (...) {}
}

void testSetPOI() {
    auto city = createCity();
    city.setPOI(0, "Gandalf");
    assert(city.getPOI(0) == "Gandalf");

    try {
        city.setPOI(3, "Gandalf");
        assert(false);
    } catch (...) {}
    try {
        city.setPOI(-1, "Gandalf");
        assert(false);
    } catch (...) {}
}

void testGetNumberOfPOIs() {
    auto city = createCity();
    assert(city.getNumberOfPOIs() == 3);
}

void testCityCopyCtor() {
    std::string pois[]={"Sauron", "Minas Morgul", "Orodruin"};
    nan::City mordor("Mordor", 47, 11, pois, 3);
    auto copy = mordor;
    mordor.setPOI(2,"Cirith Ungol");
    assert(copy.getPOI(2)=="Orodruin");
}

void testCityCtorAgainstNullptr() {
    nan::City city("Mordor", 47, 11, nullptr, 0);
    assert(city.getNumberOfPOIs()==0);
    try {
        nan::City city("Mordor", 47, 11, nullptr, 23);
        assert(false);
    } catch (...) {}
    nan::City empty("Mordor", 47, 11);
    assert(empty.getNumberOfPOIs()==0);
}

void testCityAddPOI() {
    std::string pois[]={"Sauron", "Minas Morgul"};
    nan::City city("Mordor", 47, 11,pois,2);
    city.addPOI("Orodruin");
    assert(city.getNumberOfPOIs()==3);
    assert(city.getPOI(2)=="Orodruin");
    nan::City empty("Mordor", 47, 11);
    empty.addPOI("Orodruin");
    assert(empty.getNumberOfPOIs()==1);
    assert(empty.getPOI(0)=="Orodruin");
}

void testRemovePOI() {
    std::string pois[]={"Sauron", "Minas Morgul", "Orodruin"};
    nan::City city("Mordor", 47, 11, pois, 3);
    nan::City copy1=city;
    assert(true==copy1.removePOI("Orodruin"));
    assert(copy1.getNumberOfPOIs()==2);
    assert(false== copy1.removePOI("Shire"));
    nan::City copy2=city;
    assert(true==copy2.removePOI("Sauron"));
    assert(copy2.getNumberOfPOIs()==2);
    assert(copy2.getPOI(0)=="Minas Morgul");
    std::string saurons[]={"Sauron","Sauron","Sauron"};
    nan::City same("Mordor", 47, 11, saurons, 3);
    assert(true==same.removePOI("Sauron"));
    assert(same.getNumberOfPOIs()==0);
}

void testCity() {
    testCtor();
    testGetNameXY();
    testGetPOI();
    testSetPOI();
    testGetNumberOfPOIs();
    testCityCopyCtor();
    testCityCtorAgainstNullptr();
    testCityAddPOI();
    testRemovePOI();
}

int main() {
    testCity();
}