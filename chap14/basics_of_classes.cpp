
#include <iostream>

namespace IntPair_Example
{
    struct IntPair
    {
        int num1{};
        int num2{};

        void print()
        {
            std::cout << "Pair(" << num1 << ", " << num2 << ")\n";
        }

        bool isEqual(IntPair x)
        {
            return (x.num1 == num1) && (x.num2 == num2);
        }
    };

    void test_intpair()
    {
        IntPair p1{1, 2};
        IntPair p2{3, 4};

        std::cout << "p1: ";
        p1.print();

        std::cout << "p2: ";
        p2.print();

        std::cout << "p1 and p1 " << (p1.isEqual(p1) ? "are equal\n" : "are not equal\n");
        std::cout << "p1 and p2 " << (p1.isEqual(p2) ? "are equal\n" : "are not equal\n");
    }
}

class Point3d
{
    int m_x;
    int m_y;
    int m_z;

public:
    void setValues(const int x, const int y, const int z)
    {
        m_x = x;
        m_y = y;
        m_z = z;
    }

    void print()
    {
        std::cout << "<" << m_x << ", " << m_y << ", " << m_z << ">";
    }

    bool isEqual(Point3d p)
    {
        return (m_x == p.m_x) && (m_y == p.m_y) && (m_z == p.m_z);
    }
};

void test_Point3D()
{
    Point3d point1{};
    point1.setValues(1, 2, 3);

    Point3d point2{};
    point2.setValues(1, 2, 3);

    std::cout << "point 1 and point 2 are" << (point1.isEqual(point2) ? "" : " not") << " equal\n";

    Point3d point3{};
    point3.setValues(3, 4, 5);

    std::cout << "point 1 and point 3 are" << (point1.isEqual(point3) ? "" : " not") << " equal\n";
}

int main()
{
    test_Point3D();
    return 0;
}
