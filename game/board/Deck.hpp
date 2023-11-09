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
    CardT at(std::size_t aIndex)
    {
        return theDeck.at(aIndex);
    }

    CardT back()
    {
        checkNeedToShuffle();
        return theDeck.back();
    }

    void pop_back()
    {
        checkNeedToShuffle();
        theDeck.pop_back();
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