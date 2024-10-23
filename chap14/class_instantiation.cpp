#include <iostream>
#include <string>

class Ball
{
    std::string m_color{"none"};
    float m_radius{0.0};

public:
    
    // This is the most basic type of initialization 
    // Ball(std::string_view x, float y)
    // : m_color{x}, m_radius{y}
    // {}
    
    Ball(float radius)
    : Ball("black", radius) {}

	Ball(std::string_view color="black", float radius=10.0)
		: m_color{ color }
		, m_radius{ radius } {}
    const std::string_view getColor() const {return m_color;}
    float getRadius() const {return m_radius;}

    // void printBall()
    // {
    //     std::cout << "Ball(" << m_color << ", " << m_radius << ")\n";
    // }
};

void printBall(Ball& ball)
{
    std::cout << "Ball(" << ball.getColor() << ", " << ball.getRadius() << ")\n";
}

int main()
{
	// Ball blue{ "blue", 10.0 };
	// printBall(blue);

	// Ball red{ "red", 12.0 };
	// printBall(red);

    Ball def{};
    Ball blue{ "blue" };
    Ball twenty{ 20.0 };
    Ball blueTwenty{ "blue", 20.0 };
    printBall(def);
    printBall(blue);
    printBall(twenty);
    printBall(blueTwenty);

    return 0;
}
