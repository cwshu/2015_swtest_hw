#ifndef __TRIANGLE_H__
#define __TRIANGLE_H__

enum TriangleType{
    // invalid
    TRI_INVALID,
    // valid
    TRI_EQUILATERAL,
    TRI_ISOSCELES,
    TRI_SCALENE,
};
TriangleType check_triangle_type(int a, int b, int c);

#endif /* end of include guard: __TRIANGLE_H__ */
