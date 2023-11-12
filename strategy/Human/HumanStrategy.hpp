#pragma once

#include "game/types/Turn.hpp"
#include "game/types/City.hpp"
#include "game/types/Color.hpp"

#include "strategy/StrategyBase.hpp"

#include <iostream>

class HumanStrategy : public StrategyBase
{
public:
    Turn takeTurn() override
    {
        std::cout << "How would you like to spend your turn?" << std::endl;
        std::cout << "(0) Draw destination tickets" << std::endl;
        std::cout << "(1) Take trains" << std::endl;
        std::cout << "(2) Claim route" << std::endl;
        std::cout << "Please enter the number of your choice: ";
        std::size_t myTurn;
        std::cin >> myTurn;

        return static_cast<Turn>(myTurn);
    }

    DestinationChoiceT drawDestinationTickets(DestinationOptionsT aOptions, std::size_t aNumberToChoose) override
    {
        std::cout << "Your destination options are: " << std::endl;
        for (std::size_t i = 0; i < aOptions.size(); i++)
        {
            std::cout << "(" << i <<  ") " << aOptions.at(i) << std::endl;
        }
        std::array<bool, 3> myChoices{false};
        for (std::size_t i = 0; i < aOptions.size(); i++)
        {
            std::cout << "Keep Ticket " << i <<  "? ";
            std::cin >> myChoices.at(i);
        }

        return DestinationChoiceT{myChoices[0], myChoices[1], myChoices[2]};
    }

    TrainChoice chooseTrain(std::size_t, const TrainOptionsT aOptions) override
    {
        std::cout << "Your train choices are: ";
        for (std::size_t i = 0; i < aOptions.size(); i++)
        {
            std::cout << "(" << i << ") " << aOptions.at(i).color() << std::endl;
        }
        std::cout << "(5) Top Deck" << std::endl;

        std::uint8_t myChoice = 0;
        std::cout << "Which train is for you? ";
        std::cin >> myChoice;

        return static_cast<TrainChoice>(myChoice);
    }

    ClaimedRoute claimRoute(RoutesT aRoutes) override
    {
        std::cout << "What is one city of the cities in the route you want to claim?";
        City myFirstCity = getCityFromUserInput();
        
        std::cout << "What is the other city?";
        City mySecondCity = getCityFromUserInput();

        std::cout << "What color would you like to use?";
        Color myColor = getColorFromUserInput();

        return ClaimedRoute{getRouteFromUserInput(aRoutes, myFirstCity, mySecondCity), myColor};
    }

private:
    Route& getRouteFromUserInput(RoutesT aRoutes, City aFirstCity, City aSecondCity)
    {
        for (std::size_t i = 0; i < aRoutes.size(); i++)
        {
            Route& myRoute = aRoutes.at(i);
            if ((aFirstCity == myRoute.cities().first && aSecondCity == myRoute.cities().second) ||
                (aFirstCity == myRoute.cities().second && aSecondCity == myRoute.cities().first))
            {
                return myRoute;
            }
        }

        throw std::runtime_error("Route specified by user does not exist.");
    }

    City getCityFromUserInput()
    {
        while (1 != 0)
        {
            std::string myCity{};
            std::cin >> myCity;
            if (myCity == "Vancouver")
            {
                return City::Vancouver;
            }
            if (myCity == "Seattle")
            {
                return City::Seattle;
            }
            if (myCity == "Calgary")
            {
                return City::Calgary;
            }
            if (myCity == "Portland")
            {
                return City::Portland;
            }
            if (myCity == "SanFrancisco" || myCity == "San Francisco")
            {
                return City::SanFrancisco;
            }
            if (myCity == "SaltLakeCity" || myCity == "Salt Lake City")
            {
                return City::SaltLakeCity;
            }
            if (myCity == "Helena")
            {
                return City::Helena;
            }
            if (myCity == "Winnipeg")
            {
                return City::Winnipeg;
            }
            if (myCity == "LosAngeles"|| myCity == "Los Angeles" || myCity == "LA")
            {
                return City::LosAngeles;
            }
            if (myCity == "LasVegas" || myCity == "Las Vegas" || myCity == "Vegas")
            {
                return City::LasVegas;
            }
            if (myCity == "Phoenix")
            {
                return City::Phoenix;
            }
            if (myCity == "ElPaso" || myCity == "El Paso")
            {
                return City::ElPaso;
            }
            if (myCity == "SantaFe" || myCity == "Santa Fe")
            {
                return City::SantaFe;
            }
            if (myCity == "Denver")
            {
                return City::Denver;
            }
            if (myCity == "Houston")
            {
                return City::Houston;
            }
            if (myCity == "Dallas")
            {
                return City::Dallas;
            }
            if (myCity == "OklahomaCity" || myCity == "Oklahoma City" || myCity == "OKC")
            {
                return City::OklahomaCity;
            }
            if (myCity == "KansasCity" || myCity == "Kansas City" || myCity == "KC")
            {
                return City::KansasCity;
            }
            if (myCity == "Omaha")
            {
                return City::Omaha;
            }
            if (myCity == "Duluth")
            {
                return City::Duluth;
            }
            if (myCity == "SaultStMarie" || myCity == "Sault St Marie" || myCity == "SaultSaintMarie" || myCity == "Sault Saint Marie")
            {
                return City::SaultStMarie;
            }
            if (myCity == "NewOrleans" || myCity == "New Orleans" || myCity == "Nola")
            {
                return City::NewOrleans;
            }
            if (myCity == "LittleRock" || myCity == "Little Rock")
            {
                return City::LittleRock;
            }
            if (myCity == "StLouis" || myCity == "St Louis" || myCity == "SaintLouis" || myCity == "Saint Louis" || myCity == "STL")
            {
                return City::SaintLouis;
            }
            if (myCity == "Chicago")
            {
                return City::Chicago;
            }
            if (myCity == "Toronto")
            {
                return City::Toronto;
            }
            if (myCity == "Montreal")
            {
                return City::Montreal;
            }
            if (myCity == "Nashville")
            {
                return City::Nashville;
            }
            if (myCity == "Pittsburgh")
            {
                return City::Pittsburgh;
            }
            if (myCity == "NewYork")
            {
                return City::NewYork;
            }
            if (myCity == "Boston")
            {
                return City::Boston;
            }
            if (myCity == "Atlanta")
            {
                return City::Atlanta;
            }
            if (myCity == "Raleigh")
            {
                return City::Raleigh;
            }
            if (myCity == "Washington")
            {
                return City::Washington;
            }
            if (myCity == "Miami")
            {
                return City::Miami;
            }
            if (myCity == "Charleston")
            {
                return City::Charleston;
            }

            std::cout << "Invalid city entered, please try again. " << std::endl;
        }
    }

    Color getColorFromUserInput()
    {
        while (1 != 0)
        {
            std::string myColor{};
            std::cin >> myColor;

            if (myColor == "white" || myColor == "White")
            {
                return Color::White;
            }
            if (myColor == "pink" || myColor == "Pink")
            {
                return Color::Pink;
            }
            if (myColor == "red" || myColor == "Red")
            {
                return Color::Red;
            }
            if (myColor == "orange" || myColor == "Orange")
            {
                return Color::Orange;
            }
            if (myColor == "yellow" || myColor == "Yellow")
            {
                return Color::Yellow;
            }
            if (myColor == "green" || myColor == "Green")
            {
                return Color::Green;
            }
            if (myColor == "blue" || myColor == "Blue")
            {
                return Color::Blue;
            }
            if (myColor == "black" || myColor == "Black")
            {
                return Color::Black;
            }
            if (myColor == "rainbow" || myColor == "Rainbow")
            {
                return Color::Rainbow;
            }
            
            std::cout << "Invalid color entered, please do better." << std::endl;
        }
    }
};