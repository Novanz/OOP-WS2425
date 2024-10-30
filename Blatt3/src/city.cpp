//
// Created by nan on 10/29/24.
//

#include <cassert>
#include <string>
#include "city.h"
#include "Position.h"

    nan::Position createPosition(){
        std::string mordor = "Mordor";
        nan::Position result(mordor, 47, 11);
        return result;
    }

    nan::City createCity(){
        auto position=createPosition();
        std::string pois[]={"Sauron", "Minas Morgul", "Orodruin"};
        nan::City result(position, pois, 3);
        return result;
    }

    void testCtor(){
        auto position=createPosition();
        std::string pois[]={"Sauron", "Minas Morgul", "Orodruin"};
        nan::City city(position,pois,3);
        pois[0]="Gandalf";
        assert(city.getPOI(0)=="Sauron");
    }

    void testGetNameXY(){
        auto position=createPosition();
        nan::City city(position, nullptr,0);
        assert(city.getName()=="Mordor");
        assert(city.getX()==47);
        assert(city.getY()==11);
    }


    void testGetPOI(){
        auto city=createCity();
        assert(city.getPOI(0)=="Sauron");
        assert(city.getPOI(1)=="Minas Morgul");
        assert(city.getPOI(2)=="Orodruin");
        try {
            city.getPOI(3);
            assert(false);
        }catch (...){}
        try {
            city.getPOI(-1);
            assert(false);
        }catch (...){}
    }

    void testSetPOI(){
        auto city=createCity();
        city.setPOI(0,"Gandalf");
        assert(city.getPOI(0)=="Gandalf");

        try {
            city.setPOI(3,"Gandalf");
            assert(false);
        }catch (...){}
        try {
            city.setPOI(-1,"Gandalf");
            assert(false);
        }catch (...){}
    }

    void testGetNumberOfPOIs(){
        auto city=createCity();
        assert(city.getNumberOfPOIs()==3);
    }


    void testCity() {
        testCtor();
        testGetNameXY();
        testGetPOI();
        testSetPOI();
        testGetNumberOfPOIs();
    }

    nan::City::City(const nan::Position &mPosition, std::string *mPOIs, int mNumberOfPOIs)
        : m_position(mPosition), m_pois(mPOIs), m_number_of_pois(mNumberOfPOIs){}
    const std::string &nan::City::getName() const {
        return m_position.getName();
    }
    int nan::City::getX() const {
        return m_position.getX();
    }
    int nan::City::getY() const {
        return m_position.getY();
    }
    std::string nan::City::getPOI(int i) const {
        return m_pois[i];
    }
    void nan::City::setPOI(int i, const std::string &poi) {
        m_pois[i]= poi;
    }
    int nan::City::getNumberOfPOIs() const {
        return m_number_of_pois;
    }
int main() {
    testCity();
}