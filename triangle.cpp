#include <iostream>

#include <gtest/gtest.h>

#include "triangle.h"

// 0 < a, b, c < 200 and a < b+c and b < a+c and c < a+b
TriangleType check_triangle_type(int a, int b, int c){
    if( a <= 0 || a >= 200 )
        return TRI_INVALID;
    if( b <= 0 || b >= 200 )
        return TRI_INVALID;
    if( c <= 0 || c >= 200 )
        return TRI_INVALID;
    
    if( a >= b+c )
        return TRI_INVALID;
    if( b >= a+c )
        return TRI_INVALID;
    if( c >= a+b )
        return TRI_INVALID;

    int side_equal = 0;
    if( a == b )
        side_equal += 1;
    if( b == c )
        side_equal += 1;
    if( a == c )
        side_equal += 1;

    if( side_equal == 3 )
        return TRI_EQUILATERAL;
    if( side_equal == 1 )
        return TRI_ISOSCELES;

    return TRI_SCALENE;
}

#ifdef __USAGE_TEST__

void example_usage(){
    int a, b, c;
    std::cout << "Please input 3 sides length of triangle, every length should be integer:";
    std::cin >> a >> b >> c;
    
    if( check_triangle_type(a, b, c) == TRI_INVALID )
        std::cout << "(" << a << "," << b << "," << c << ") is not a triangle." << std::endl;
    else if( check_triangle_type(a, b, c) == TRI_EQUILATERAL )
        std::cout << "(" << a << "," << b << "," << c << ") is an equilateral triangle." << std::endl;
    else if( check_triangle_type(a, b, c) == TRI_ISOSCELES )
        std::cout << "(" << a << "," << b << "," << c << ") is an isosceles triangle." << std::endl;
    else if( check_triangle_type(a, b, c) == TRI_SCALENE )
        std::cout << "(" << a << "," << b << "," << c << ") is a scalene triangle." << std::endl;
    return;
}

int main(int argc, char *argv[]){
    example_usage();
}

#endif

#ifdef __UNIT_TEST__

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

#endif
