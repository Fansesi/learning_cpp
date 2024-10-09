#include <iostream>
#include "Random.h"

int main()
{
    std::cout << "Write the minimum number: ";
    int minGuessRange;
    std::cin >> minGuessRange;

    std::cout << "Write the maximum number: ";
    int maxGuessRange;
    std::cin >> maxGuessRange;

    std::cout << "How many guesses do you want: ";
    int numGuess;
    std::cin >> numGuess;

    int compGuess{Random::get(minGuessRange, maxGuessRange)};

    int guessValue;
    for (int iter{1}; iter <= numGuess; iter++)
    {
        std::cout << "\n" <<"Guess #" << iter << ": ";
        std::cin >> guessValue;

        if (guessValue == compGuess)
        {
            std::cout << "Correct! You win!\n\n";
            exit(0);
        }
        else if (guessValue > compGuess)
        {
            std::cout << "Your guess is too high.";
        }
        else
        {
            std::cout << "Your guess is too low.";
        }
    }
    
    std::cout << "\nYou lost. The number was " << compGuess << "\n\n";

    
    return 0;
}
