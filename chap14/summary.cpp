#include <iostream>
#include <cmath>

class Point2d
{
    double m_x{0.0};
    double m_y{0.0};

public: 
    Point2d()
    : Point2d(0.0, 0.0) {}

    Point2d(double x, double y)
    : m_x {x}, m_y {y} {}

    void print() const
    {
        std::cout << "Point2d(" << m_x << ", " << m_y << ")\n";
    }

    double distanceTo(Point2d& point) const
    {
        return std::sqrt((m_x - point.m_x)*(m_x - point.m_x) + (m_y - point.m_y)*(m_y - point.m_y));
    }


};

void test_point2d()
{
    Point2d first{};
    Point2d second{ 3.0, 4.0 };

    // Point2d third{ 4.0 }; // should error if uncommented

    first.print();
    second.print();

    std::cout << "Distance between two points: " << first.distanceTo(second) << '\n';

}


class Fraction
{
    int numerator{ 0 };
    int denominator{ 1 };

public:
    explicit Fraction()
    : Fraction(0, 1) {}
    
    Fraction(int x, int y)
    : numerator{x}, denominator{y} {}
    
    Fraction getFraction() const
    {
        Fraction temp{};
        std::cout << "Enter a value for numerator: ";
        std::cin >> temp.numerator;
        std::cout << "Enter a value for denominator: ";
        std::cin >> temp.denominator;
        std::cout << '\n';

        return temp;
    }

    Fraction multiply(const Fraction& f1) const
    {
        return { f1.numerator * numerator, f1.denominator * denominator };
    }
    
    void printFraction() const
    {
        std::cout << numerator << '/' << denominator << '\n';
    }
};


int main()
{
    return 0;
}
