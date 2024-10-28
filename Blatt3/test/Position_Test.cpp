//
// Created by nan on 10/15/24.
//

#include <gtest/gtest.h>
#include "../src/Position.h"

TEST(PositionTest, ReturnsCorrectMembers) {
    std::string mordor = "Mordor";
    nan::Position position(mordor, 47, 11);
    EXPECT_EQ(position.getName(), mordor);
    EXPECT_EQ(position.getX(), 47);
    EXPECT_EQ(position.getY(), 11);
    EXPECT_NE(position.getY(), 9);
    mordor[0]='X';
    EXPECT_EQ(position.getName(), "Mordor"); // Zu zeigen, dass m_name und das String mordor, was zur Initialisierung benutzt wurde, nichts miteinander zu tun haben
}

TEST(PositionCompareTest, CorrectComparison) {
    std::string mordor = "Mordor";
    nan::Position position(mordor, 47, 11);
    
    EXPECT_EQ(position.compare(position),0);
    
    nan::Position position_name("zordor", 47, 11);
    nan::Position position_x(mordor, 48, 11);
    nan::Position position_y(mordor, 47, 12);
    
    EXPECT_EQ(position.compare(position_name),-1);
    EXPECT_EQ(position.compare(position_x), -1);
    EXPECT_EQ(position.compare(position_y), -1);
    EXPECT_EQ(position_name.compare(position), 1);
    EXPECT_EQ(position_x.compare(position), 1);
    EXPECT_EQ(position_y.compare(position), 1);
    
}
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

