#include <iostream>
#include <string>

template <typename T, typename U, typename V>
class Triad
{
private:
    T m_var1 {};
    U m_var2 {};
    V m_var3 {};

public:
    Triad(const T& var1, const U& var2, const V& var3)
    : m_var1{var1}
    , m_var2{var2}
    , m_var3{var3} {}

    const T& first() {return m_var1;}
    const U& second() {return m_var2;}
    const V& third() {return m_var3;}

    void print() const;
};

template <typename T, typename U, typename V>
void Triad<T,U,V>::print() const
{
    std::cout << "[" << m_var1 << ", " << m_var2 << ", " << m_var3 << "]";
}



int main()
{
    Triad<int, int, int> t1{ 1, 2, 3 };
	t1.print();
	std::cout << '\n';
	std::cout << t1.first() << '\n';

	using namespace std::literals::string_literals;
	const Triad t2{ 1, 2.3, "dneeme"s};
	t2.print();
	std::cout << '\n';
    return 0;
}
