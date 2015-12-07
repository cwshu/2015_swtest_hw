#include <iostream>

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

