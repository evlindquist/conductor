#pragma once

#include "game/board/Route.hpp"
#include "game/gameState/Player.hpp"

#include "game/board/Deck.hpp"

#include "game/types/Types.hpp"

static constexpr std::size_t NUM_TRAINS_PER_COLOR = 12;
static constexpr std::size_t NUM_RAINBOW_TRAINS = 14;

class Board
{
    Deck<DestinationTicket> theDestinationsDeck;
    Deck<Train> theTrainsDeck;

    TrainOptionsT theTrainOptions;

public:
    Board()
    {
        initializeDecks();
    }

    const RoutesT& routes()
    {
        return theRoutesList;
    }
    
    TrainOptionsT& trains()
    {
        return theTrainOptions;
    }

    DestinationOptionsT destinationTickets()
    {
        DestinationOptionsT myOptions{};
        for (std::size_t i = 0; i < myOptions.size(); i++)
        {
            myOptions.at(i) = theDestinationsDeck.back();
            theDestinationsDeck.pop_back();
        }

        return myOptions;
    }

    void returnDestinations(DestinationsT aReturnedDestinations)
    {
        theDestinationsDeck.insert(aReturnedDestinations);
    }

    Train drawTrain(TrainChoice aChoice)
    {
        if (aChoice == TrainChoice::TOP_DECK)
        {
            Train myTopDeck = theTrainsDeck.back();
            theTrainsDeck.pop_back();

            return myTopDeck;
        }
        else
        {
            Train& myChoice = theTrainOptions.at(static_cast<std::size_t>(aChoice));
            Train myTrain = myChoice;

            myChoice = theTrainsDeck.back();
            theTrainsDeck.pop_back();

            return myTrain;
        }
    }

private:
    void initializeDecks()
    {
        for (std::size_t i = 0; i < NUM_TRAIN_COLORS; i++)
        {
            for (std::size_t j = 0; j < NUM_TRAINS_PER_COLOR; j++)
            {
                theTrainsDeck.insert(Train{static_cast<Color>(i)});
            }
        }
        theTrainsDeck.insert(Train{Color::Rainbow});
        theTrainsDeck.insert(Train{Color::Rainbow});

        for (std::size_t i = 0; i < theTrainOptions.size(); i++)
        {
            theTrainOptions.at(i) = theTrainsDeck.back();
            theTrainsDeck.pop_back();
        }

        theDestinationsDeck.insert(theDestionationsList);
    }

    const RoutesT theRoutesList = {
        Route{City::Vancouver,      City::Seattle,          Color::Gray,    Color::Gray,    1 },
        Route{City::Vancouver,      City::Calgary,          Color::Gray,    Color::None,    3 },
        Route{City::Seattle,        City::Calgary,          Color::Gray,    Color::None,    4 },
        Route{City::Seattle,        City::Portland,         Color::Gray,    Color::Gray,    1 },
        Route{City::Calgary,        City::Helena,           Color::Gray,    Color::None,    4 },
        Route{City::Seattle,        City::Helena,           Color::Yellow,  Color::None,    6 },
        Route{City::Portland,       City::SaltLakeCity,     Color::Blue,    Color::None,    6 },
        Route{City::Portland,       City::SanFrancisco,     Color::Green,   Color::Pink,    5 },
        Route{City::SanFrancisco,   City::SaltLakeCity,     Color::Orange,  Color::White,   5 },
        Route{City::SanFrancisco,   City::LosAngeles,       Color::Yellow,  Color::Pink,    3 },
        Route{City::LosAngeles,     City::LasVegas,         Color::Gray,    Color::None,    2 },
        Route{City::LasVegas,       City::SaltLakeCity,     Color::Orange,  Color::None,    3 },
        Route{City::SaltLakeCity,   City::Helena,           Color::Pink,    Color::None,    3 },
        Route{City::Calgary,        City::Winnipeg,         Color::White,   Color::None,    6 },
        Route{City::Helena,         City::Winnipeg,         Color::Blue,    Color::None,    4 },
        Route{City::Helena,         City::Denver,           Color::Green,   Color::None,    4 },
        Route{City::SaltLakeCity,   City::Denver,           Color::Red,     Color::Yellow,  3 },
        Route{City::LosAngeles,     City::Phoenix,          Color::Gray,    Color::None,    3 },
        Route{City::LosAngeles,     City::ElPaso,           Color::Black,   Color::None,    6 },
        Route{City::Phoenix,        City::Denver,           Color::White,   Color::None,    5 },
        Route{City::Phoenix,        City::SantaFe,          Color::Gray,    Color::None,    3 },
        Route{City::Phoenix,        City::ElPaso,           Color::Gray,    Color::None,    3 },
        Route{City::Denver,         City::SantaFe,          Color::Gray,    Color::None,    2 },
        Route{City::SantaFe,        City::ElPaso,           Color::Gray,    Color::None,    2 },
        Route{City::Winnipeg,       City::SaultStMarie,     Color::Gray,    Color::None,    6 },
        Route{City::Winnipeg,       City::Duluth,           Color::Black,   Color::None,    4 },
        Route{City::Helena,         City::Duluth,           Color::Orange,  Color::None,    6 },
        Route{City::Helena,         City::Omaha,            Color::Red,     Color::None,    4 },
        Route{City::Denver,         City::Omaha,            Color::Pink,    Color::None,    4 },
        Route{City::Denver,         City::KansasCity,       Color::Black,   Color::Orange,  4 },
        Route{City::Denver,         City::OklahomaCity,     Color::Red,     Color::None,    4 },
        Route{City::SantaFe,        City::OklahomaCity,     Color::Blue,    Color::None,    3 },
        Route{City::ElPaso,         City::OklahomaCity,     Color::Yellow,  Color::None,    5 },
        Route{City::ElPaso,         City::Dallas,           Color::Red,     Color::None,    4 },
        Route{City::ElPaso,         City::Houston,          Color::Green,   Color::None,    6 },
        Route{City::Duluth,         City::SaultStMarie,     Color::Gray,    Color::None,    3 },
        Route{City::Duluth,         City::Omaha,            Color::Gray,    Color::Gray,    2 },
        Route{City::Omaha,          City::KansasCity,       Color::Gray,    Color::Gray,    1 },
        Route{City::KansasCity,     City::OklahomaCity,     Color::Gray,    Color::Gray,    2 },
        Route{City::OklahomaCity,   City::Dallas,           Color::Gray,    Color::Gray,    2 },
        Route{City::Dallas,         City::Houston,          Color::Gray,    Color::Gray,    1 },
        Route{City::Duluth,         City::Chicago,          Color::Red,     Color::None,    3 },
        Route{City::Duluth,         City::Toronto,          Color::Pink,    Color::None,    6 },
        Route{City::Omaha,          City::Chicago,          Color::Blue,    Color::None,    4 },
        Route{City::KansasCity,     City::SaintLouis,       Color::Blue,    Color::Pink,    2 },
        Route{City::OklahomaCity,   City::LittleRock,       Color::Gray,    Color::None,    2 },
        Route{City::Dallas,         City::LittleRock,       Color::Gray,    Color::None,    2 },
        Route{City::Houston,        City::NewOrleans,       Color::Gray,    Color::None,    2 },
        Route{City::Chicago,        City::SaintLouis,       Color::Green,   Color::White,   2 },
        Route{City::SaintLouis,     City::LittleRock,       Color::Gray,    Color::None,    2 },
        Route{City::LittleRock,     City::NewOrleans,       Color::Green,   Color::None,    3 },
        Route{City::SaultStMarie,   City::Montreal,         Color::Black,   Color::None,    5 },
        Route{City::SaultStMarie,   City::Toronto,          Color::Gray,    Color::None,    2 },
        Route{City::Chicago,        City::Toronto,          Color::White,   Color::None,    4 },
        Route{City::Chicago,        City::Pittsburgh,       Color::Orange,  Color::Black,   3 },
        Route{City::SaintLouis,     City::Pittsburgh,       Color::Green,   Color::None,    5 },
        Route{City::SaintLouis,     City::Nashville,        Color::Gray,    Color::None,    2 },
        Route{City::LittleRock,     City::Nashville,        Color::White,   Color::None,    3 },
        Route{City::NewOrleans,     City::Atlanta,          Color::Yellow,  Color::Orange,  4 },
        Route{City::Nashville,      City::Atlanta,          Color::Gray,    Color::None,    1 },
        Route{City::Nashville,      City::Pittsburgh,       Color::Yellow,  Color::None,    4 },
        Route{City::Nashville,      City::Raleigh,          Color::Black,   Color::None,    3 },
        Route{City::Montreal,       City::Toronto,          Color::Gray,    Color::None,    3 },
        Route{City::Toronto,        City::Pittsburgh,       Color::Gray,    Color::None,    2 },
        Route{City::Pittsburgh,     City::Raleigh,          Color::Gray,    Color::None,    2 },
        Route{City::Raleigh,        City::Atlanta,          Color::Gray,    Color::Gray,    2 },
        Route{City::Atlanta,        City::Miami,            Color::Blue,    Color::None,    5 },
        Route{City::NewOrleans,     City::Miami,            Color::Red,     Color::None,    6 },
        Route{City::Atlanta,        City::Charleston,       Color::Gray,    Color::None,    2 },
        Route{City::Charleston,     City::Miami,            Color::Pink,    Color::None,    4 },
        Route{City::Raleigh,        City::Charleston,       Color::Gray,    Color::None,    2 },
        Route{City::Washington,     City::Raleigh,          Color::Gray,    Color::Gray,    2 },
        Route{City::Pittsburgh,     City::Washington,       Color::Gray,    Color::None,    2 },
        Route{City::Pittsburgh,     City::NewYork,          Color::White,   Color::Green,   2 },
        Route{City::Montreal,       City::NewYork,          Color::Blue,    Color::None,    3 },
        Route{City::Montreal,       City::Boston,           Color::Gray,    Color::Gray,    2 },
        Route{City::Boston,         City::NewYork,          Color::Yellow,  Color::Red,     2 },
        Route{City::NewYork,        City::Washington,       Color::Orange,  Color::Black,   2 }
    };  
};