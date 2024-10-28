//
// Created by nan on 10/15/24.
//

#include <gtest/gtest.h>
#include "../src/Position.h"

TEST(PositionTest, ReturnsCorrectMembers) {
    Position mordor;
    mordor.set("Mordor", 3, 4);
    EXPECT_EQ(mordor.getName(), "Mordor");
    mordor.set("ordor", 3, 4);
    EXPECT_NE(mordor.getName(), "Mordor");
    EXPECT_EQ(mordor.getX(), 3);
    EXPECT_EQ(mordor.getY(), 4);
    EXPECT_NE(mordor.getY(), 9);

    Position numinor;
    numinor.set("Numinor", -4, 4);
    EXPECT_NE(numinor.getX(), 3);
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

