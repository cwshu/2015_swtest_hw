#include <iostream>

#include <gtest/gtest.h>

enum TriangleType {
    // invalid
    TRI_INVALID,
    // valid
    TRI_EQUILATERAL,
    TRI_ISOSCELES,
    TRI_SCALENE,
    TRI_RIGHT,
};

TriangleType check_triangle_type(int a, int b, int c){
    return TRI_INVALID;
}

int main(int argc, char *argv[]){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
    /*
    int a, b, c;
    std::cout << "Please input 3 sides length of triangle, every length should be integer:";
    std::cin >> a >> b >> c;

    if( check_triangle_type(a, b, c) == TRI_INVALID )
        cout << "(" << a << "," << b << "," << c << ") is not a triangle." << std::endl;
    else if( check_triangle_type(a, b, c) == TRI_EQUILATERAL )
        cout << "(" << a << "," << b << "," << c << ") is an equilateral triangle." << std::endl;
    else if( check_triangle_type(a, b, c) == TRI_ISOSCELES )
        cout << "(" << a << "," << b << "," << c << ") is an isosceles triangle." << std::endl;
    else if( check_triangle_type(a, b, c) == TRI_SCALENE )
        cout << "(" << a << "," << b << "," << c << ") is a scalene triangle." << std::endl;
    else if( check_triangle_type(a, b, c) == TRI_RIGHT )
        cout << "(" << a << "," << b << "," << c << ") is a right triangle." << std::endl;
    return 0;
    */
}

// triangle boundary value of 0 ~ 200: {0, 1, 2, 100, 198, 199, 200}
// triangle boundary value of a < b+c, b < a+c, c < a+b: { a = b+c, a = b+c-1, a = b+c-2, a < b+c }
TEST(CheckTriangleTypeTest, SideLength1to199){
    // all normal
    EXPECT_EQ(TRI_EQUILATERAL, check_triangle_type(100, 100, 100));
    EXPECT_EQ(TRI_ISOSCELES, check_triangle_type(150, 150, 100));
    EXPECT_EQ(TRI_SCALENE, check_triangle_type(100, 103, 106));
    EXPECT_EQ(TRI_RIGHT, check_triangle_type(75, 100, 125));

    // one boundary and others normal
    EXPECT_EQ(TRI_ISOSCELES, check_triangle_type(1, 100, 100));
    EXPECT_EQ(TRI_ISOSCELES, check_triangle_type(2, 100, 100));
    EXPECT_EQ(TRI_ISOSCELES, check_triangle_type(198, 100, 100));
    EXPECT_EQ(TRI_ISOSCELES, check_triangle_type(199, 100, 100));

    EXPECT_EQ(TRI_ISOSCELES, check_triangle_type(100, 1, 100));
    EXPECT_EQ(TRI_ISOSCELES, check_triangle_type(100, 2, 100));
    EXPECT_EQ(TRI_ISOSCELES, check_triangle_type(100, 198, 100));
    EXPECT_EQ(TRI_ISOSCELES, check_triangle_type(100, 199, 100));

    EXPECT_EQ(TRI_ISOSCELES, check_triangle_type(100, 100, 1));
    EXPECT_EQ(TRI_ISOSCELES, check_triangle_type(100, 100, 2));
    EXPECT_EQ(TRI_ISOSCELES, check_triangle_type(100, 100, 198));
    EXPECT_EQ(TRI_ISOSCELES, check_triangle_type(100, 100, 199));
}
