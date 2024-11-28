#include <iostream>
#include <string>
#include "Random.h"
#include <array>

namespace Potion
{
    enum Type
    {
        healing,
        mana,
        speed,
        invisibility,
        numType
    };

    constexpr std::array<int, numType> costs{20, 30, 12, 50};
    constexpr std::array<std::string_view, numType> names{"healing", "mana", "speed", "invisibility"};
}

void shop()
{
    std::cout << "\nHere is our selection for today: \n";

    for (std::size_t i{0}; i < Potion::numType; i++)
    {
        std::cout << i << ") " << Potion::names[i] << " potion costs " << Potion::costs[i] << "\n";
    }
}

class Player
{
private:
    std::string_view m_name{};
    std::array<int, Potion::numType> m_inventory{};
    int m_gold{Random::get(80, 120)};

public:
    Player(std::string name)
        : m_name{name} {}

    std::string_view getName() { return m_name; }
    int getGold() { return m_gold; }

    void showInventory()
    {
        std::cout << "Your inventory contains: ";
        for (std::size_t i{0}; i < Potion::numType; i++)
        {
            if (!m_inventory[i])
            {
                std::cout << m_inventory[i] << "x potion of " << Potion::names[i];
            }
        }
        std::cout << "You escaped with " << m_gold << "gold remaining.";
    }

    void buy(int price) { m_gold -= price; }
    void greet()
    // this function may be on the initializer as well.
    {
        std::cout << "Hello " << m_name << "! ";
        std::cout << "You have " << m_gold << " gold.\n\n";
    }
};

void run(Player &player)
// run the main logic.
{
    while (true)
    {
        shop();
        std::cout << "Enter the number of the potion you'd like to buy, or 'q' to quit: ";
        std::size_t input{};
        std::cin >> input;

        if (input == "q")
        {
            break;
        }

        if (!std::cin) // if the previous extraction failed
        {
            std::cin.clear(); // put us back in 'normal' operation mode
            std::cout << "That wasn't a valid input. Try again.\n";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // and remove the bad input
            continue;
        }

        if (player.getGold() >= Potion::costs[input])
        {
            // update gold...
            player.buy(Potion::costs[input]);
            // print purchase message
            std::cout << "You purchased a potion of " << Potion::names[input] << ".  ";
            std::cout << "You have " << player.getGold() << " gold left.";
        }
        else
        {
            std::cout << "You can not afford that.";
        }
    }
}

int main()
{
    std::cout << "Welcome to Roscoe's potion emporium!" << "\n";
    std::cout << "Enter your name: ";
    std::string name;
    std::cin >> name;

    Player player{name};
    player.greet();    

    run(player);

    player.showInventory();
    std::cout << "Thanks for shopping at Roscoe's potion  emporium!" << "\n";
    return 0;
}
