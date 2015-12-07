#include <gtest/gtest.h>

#include "triangle.h"

int main(int argc, char *argv[]){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

/* Testing Code */
// Weak Robust test for check_triangle_type()
// SideLength1to199
// SideLength0or200
// SideLengthTriInequalityNormal
// SideLengthTriInequalityRobust

// triangle boundary value of 0 ~ 200: {0, 1, 2, 110, 198, 199, 200}
TEST(CheckTriangleTypeTest, SideLength1to199){
    // all normal
    EXPECT_EQ(TRI_EQUILATERAL, check_triangle_type(110, 110, 110));
    EXPECT_EQ(TRI_ISOSCELES, check_triangle_type(150, 150, 110));
    EXPECT_EQ(TRI_SCALENE, check_triangle_type(110, 113, 116));

    // one boundary and others normal
    EXPECT_EQ(TRI_ISOSCELES, check_triangle_type(1, 110, 110));
    EXPECT_EQ(TRI_ISOSCELES, check_triangle_type(2, 110, 110));
    EXPECT_EQ(TRI_ISOSCELES, check_triangle_type(198, 110, 110));
    EXPECT_EQ(TRI_ISOSCELES, check_triangle_type(199, 110, 110));

    EXPECT_EQ(TRI_ISOSCELES, check_triangle_type(110, 1, 110));
    EXPECT_EQ(TRI_ISOSCELES, check_triangle_type(110, 2, 110));
    EXPECT_EQ(TRI_ISOSCELES, check_triangle_type(110, 198, 110));
    EXPECT_EQ(TRI_ISOSCELES, check_triangle_type(110, 199, 110));

    EXPECT_EQ(TRI_ISOSCELES, check_triangle_type(110, 110, 1));
    EXPECT_EQ(TRI_ISOSCELES, check_triangle_type(110, 110, 2));
    EXPECT_EQ(TRI_ISOSCELES, check_triangle_type(110, 110, 198));
    EXPECT_EQ(TRI_ISOSCELES, check_triangle_type(110, 110, 199));
}

TEST(CheckTriangleTypeTest, SideLength0or200){
    EXPECT_EQ(TRI_INVALID, check_triangle_type(0, 110, 110));
    EXPECT_EQ(TRI_INVALID, check_triangle_type(200, 110, 110));

    EXPECT_EQ(TRI_INVALID, check_triangle_type(110, 0, 110));
    EXPECT_EQ(TRI_INVALID, check_triangle_type(110, 200, 110));

    EXPECT_EQ(TRI_INVALID, check_triangle_type(110, 110, 0));
    EXPECT_EQ(TRI_INVALID, check_triangle_type(110, 110, 200));
}

// triangle boundary value of a < b+c, b < a+c, c < a+b: { a = b+c, a = b+c-1, a = b+c-2, a < b+c }
TEST(CheckTriangleTypeTest, SideLengthTriInequalityNormal){
    EXPECT_EQ(TRI_SCALENE, check_triangle_type(100, 75, 50));
    EXPECT_EQ(TRI_SCALENE, check_triangle_type(100, 52, 50));
    EXPECT_EQ(TRI_SCALENE, check_triangle_type(100, 51, 50));

    EXPECT_EQ(TRI_SCALENE, check_triangle_type(75, 100, 50));
    EXPECT_EQ(TRI_SCALENE, check_triangle_type(52, 100, 50));
    EXPECT_EQ(TRI_SCALENE, check_triangle_type(51, 100, 50));

    EXPECT_EQ(TRI_SCALENE, check_triangle_type(75, 50, 100));
    EXPECT_EQ(TRI_SCALENE, check_triangle_type(52, 50, 100));
    EXPECT_EQ(TRI_SCALENE, check_triangle_type(51, 50, 100));
}

TEST(CheckTriangleTypeTest, SideLengthTriInequalityRobust){
    EXPECT_EQ(TRI_INVALID, check_triangle_type(100, 50, 50));
    EXPECT_EQ(TRI_INVALID, check_triangle_type(50, 100, 50));
    EXPECT_EQ(TRI_INVALID, check_triangle_type(50, 50, 100));
}
