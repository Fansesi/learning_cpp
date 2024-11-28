#include <array>
#include <iostream>
#include "Random.h"
#include <algorithm>
#include <cassert>

struct Card
{
    enum Rank
    {
        rank_ace,
        rank_2,
        rank_3,
        rank_4,
        rank_5,
        rank_6,
        rank_7,
        rank_8,
        rank_9,
        rank_10,
        rank_jack,
        rank_queen,
        rank_king,

        max_ranks
    };

    enum Suit
    {
        suit_club,
        suit_diamond,
        suit_heart,
        suit_spade,

        max_suits
    };

    // These need to be static so they are only created once per program, not once per Card
    static constexpr std::array allRanks{rank_ace, rank_2, rank_3, rank_4, rank_5, rank_6, rank_7, rank_8, rank_9, rank_10, rank_jack, rank_queen, rank_king};
    static constexpr std::array allSuits{suit_club, suit_diamond, suit_heart, suit_spade};
    static constexpr std::size_t NUMBER_OF_CARDS{52};

    Rank rank{};
    Suit suit{};

    friend std::ostream &operator<<(std::ostream &out, const Card &card)
    {
        static constexpr std::array ranks{'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};
        static constexpr std::array suits{'C', 'D', 'H', 'S'};

        out << ranks[card.rank] << suits[card.suit];
        return out;
    }

    int value() const
    {
        static constexpr std::array rankValues{11, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10};
        return rankValues[rank];
    }
};

class Deck
{
private:
    std::array<Card, Card::NUMBER_OF_CARDS> m_deck{};
    std::size_t m_currentCardPos{0};

public:
    Deck()
    {
        std::size_t iter{0};
        for (auto suit : Card::allSuits)
            for (auto rank : Card::allRanks)
                m_deck[iter++] = Card{rank, suit};
    }

    Card dealCard()
    {
        assert(m_currentCardPos != 52 && "Deck::dealCard ran out of cards");
        return m_deck[m_currentCardPos++];
    }

    void shuffle()
    {
        std::shuffle(m_deck.begin(), m_deck.end(), Random::mt);
        m_currentCardPos = 0;
    }
};


struct Player
{
    int score{};
};

bool playRound()
{
    Deck deck{};
    deck.shuffle();

    Player player{deck.dealCard().value() + deck.dealCard().value()};
    Player dealer{deck.dealCard().value()};
    
    std::cout << "The dealer is showing: " << dealer.score;
    std::cout << "You have score: " << player.score;
    return (player.score > dealer.score);
}

int main()
{
    std::cout << "I'm not going to implement this.";
    return 0;
}
