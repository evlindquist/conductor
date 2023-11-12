#pragma once

#include <algorithm>
#include <random>
#include <vector>

template<typename CardT>
class Deck
{
    std::vector<CardT> theDeck{};
    std::vector<CardT> theDiscardPile{};

    std::random_device theRandom;
    std::mt19937_64 theShuffler{theRandom()};

public:
    CardT draw()
    {
        checkNeedToShuffle();

        CardT myCard = theDeck.back();
        theDeck.pop_back();
        return myCard;
    }
    
    std::size_t size()
    {
        return theDeck.size();
    }

    void insert(CardT aCard)
    {
        theDiscardPile.push_back(aCard);
    }

    template <typename IterableT>
    void insert(IterableT anIterableStructure)
    {
        theDiscardPile.insert(theDeck.end(), anIterableStructure.begin(), anIterableStructure.end());
    }

    void shuffle()
    {
        std::shuffle(theDeck.begin(), theDeck.end(), theShuffler);
    }

private:
    inline void checkNeedToShuffle()
    {
        if (size() == 0)
        {
            theDeck.insert(theDeck.begin(), theDiscardPile.begin(), theDiscardPile.end());
            shuffle();
        }
    }
};