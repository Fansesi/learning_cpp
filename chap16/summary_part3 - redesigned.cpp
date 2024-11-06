#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include "Random.h"
#include <cassert>

namespace WordList
{
    using namespace std::literals::string_view_literals; // for sv suffix
 
    const std::vector words {"mystery"sv, "broccoli"sv, "account"sv, "almost"sv, "spaghetti"sv, "opinion"sv, "beautiful"sv, "distance"sv, "luggage"sv};

    const std::string_view pickRandomWord()
    {
        // std::cout << "The word is: " << words[Random::get<std::size_t>(0, words.size()-1)] << "\n";
        return words[Random::get<std::size_t>(0, words.size()-1)];
    }
} 

class Session
{
private:
    const std::string_view m_word {WordList::pickRandomWord()};
    std::string m_displayedWord {std::string(m_word.size(), '_')};
    
    static constexpr int m_guessNum {10}; // for some reason I can only use static constexpr here. 
    int m_currentGuessNum {};
    // To hold the guessed chars. Let's have 5 guesses for now. Also I'm trying out array here.
    // std::array<char, m_guessNum> m_guessedChars{};
    std::vector<char> m_guessedChars{std::vector(m_guessNum, '+')};

public:
    std::string_view getWord() const {return m_word;}
    std::string_view getDisplayWord() const {return m_displayedWord;}
    void printGuessedChars() const 
    {
        for (const auto& elmnt: m_guessedChars)
        {
            std::cout << elmnt;
        }    
    } 

    bool checkAlreadyWronglyGuessed(char c) const
    {
        for (char elmnt: m_guessedChars)
        {
            if(c == elmnt) {return true;}
        }
        return false;
    }
    bool updateDisplayedWord(char c)
    {
        bool in{false};
        for (size_t i = 0; i < m_word.size(); i++)
        {
            if(m_word[i] == c)
            {
                m_displayedWord.data()[i] = c;
                in = true;
            }
        }
        // if the answer is wrong, out the char into m_guessedChars.
        if (!in) {m_guessedChars.data()[m_guessNum-m_currentGuessNum-1] = c;}
        return in;
    }
    void debug() const
    {
        std::cout << "---DEBUG---" << "\n";
        std::cout << m_word << "\n";
        std::cout << m_displayedWord << "\n";
        for (char c: m_guessedChars)
            std::cout << c;
        std::cout << "\n---DEBUG---" << "\n";
    }

    bool checkWordIsFound() const
    {
        if (m_word == m_displayedWord) {return true;}
        else {return false;}
    }

    void incrementGuessNum() {m_currentGuessNum += 1;}
    bool checkIfEnds() {if (m_currentGuessNum==m_guessNum) {return true;} return false;}
};

void run(Session& ses)
{
    ses.debug();
    while (true)
    {
        // Display current session information.
        std::cout << "The word: " << ses.getDisplayWord() << "\t Wrong guesses: ";
        ses.printGuessedChars();
        std::cout << "\n";

        std::cout << "Enter your next letter: ";
        char input{};
        std::cin >> input;

        
        if (!std::cin) // if the previous extraction failed
        {
            std::cin.clear(); // put us back in 'normal' operation mode
            std::cout << "That wasn't a valid input. Try again.\n";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // and remove the bad input
            continue;
        }
        
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        // Some invalid input checking
        if (input < 'a' || input > 'z') {std::cout << "That wasn't a valid input. Try again.\n"; continue;}
        if (ses.checkAlreadyWronglyGuessed(input)) {std::cout << "You already guessed that. Try again.\n"; continue;}

        // Update and check if the game ends.
        bool in {ses.updateDisplayedWord(input)};
        if (ses.checkWordIsFound()) {std::cout << "Congratulations! You have found the word.\n\n"; exit(0);}
        if (ses.checkIfEnds()) {std::cout << "Unfortunately you couldn't find the word. It was " << ses.getWord() << ".\n\n"; exit(0);}
        if (in) {continue;};
        ses.incrementGuessNum();
    }
}


int main()
{
    std::cout << "Welcome to C++man (a variant of Hangman)\nTo win: guess the word.  To lose: run out of pluses.\n";
    // WordList::pickRandomWord();
    std::cout << "\n";
    Session curSession{};

    run(curSession);

    return 0;
}
