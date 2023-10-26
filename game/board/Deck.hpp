#pragma once

#include <algorithm>
#include <random>
#include <vector>

template<typename CardT>
class Deck
{
    std::vector<CardT> theDeck;

    std::random_device theRandom;
    std::mt19937_64 theShuffler{theRandom()};

public:
    CardT at (std::size_t aIndex)
    {
        return theDeck.at(aIndex);
    }

    void push_back(CardT aCard)
    {
        theDeck.push_back(aCard);
    }

    CardT back()
    {
        return theDeck.back();
    }

    void pop_back()
    {
        theDeck.pop_back();
    }
    
    std::size_t size()
    {
        return theDeck.size();
    }

    template <typename IterableT>
    void insert(IterableT anIterableStructure)
    {
        theDeck.insert(theDeck.end(), anIterableStructure.begin(), anIterableStructure.end());
    }

    void shuffle()
    {
        std::shuffle(theDeck.begin(), theDeck.end(), theShuffler);
    }
};