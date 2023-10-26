#pragma once

#include <cstdint>
#include <iostream>

enum class City : std::uint8_t
{
    Vancouver,
    Seattle,
    Calgary,
    Portland,
    SanFrancisco,
    SaltLakeCity,
    Helena,
    Winnipeg,
    LosAngeles,
    LasVegas,
    Phoenix,
    ElPaso,
    SantaFe,
    Denver,
    Houston,
    Dallas,
    OkalahomaCity,
    KansasCity,
    Omaha,
    Duluth,
    SaultStMarie,
    NewOrleans,
    LittleRock,
    SaintLouis,
    Chicago,
    Toronto,
    Montreal,
    Nashville,
    Pittsburgh,
    NewYork,
    Boston,
    Atlanta,
    Raleigh,
    Washington,
    Miami,
    Charleston
};

std::ostream& operator<<(std::ostream& os, const City& aCity);

std::ostream& operator<<(std::ostream& os, const City& aCity)
{
    switch (aCity)
    {
        case City::Vancouver:
            os << "Vancouver";
            break;
        case City::Seattle:
            os << "Seattle";
            break;
        case City::Calgary:
            os << "Calgary";
            break;
        case City::Portland:
            os << "Portland";
            break;
        case City::SanFrancisco:
            os << "San Francisco";
            break;
        case City::SaltLakeCity:
            os << "Salt Lake City";
            break;
        case City::Helena:
            os << "Helena";
            break;
        case City::Winnipeg:
            os << "Winnipeg";
            break;
        case City::LosAngeles:
            os << "Los Angeles";
            break;
        case City::LasVegas:
            os << "Las Vegas";
            break;
        case City::Phoenix:
            os << "Phoenix";
            break;
        case City::ElPaso:
            os << "El Paso";
            break;
        case City::SantaFe:
            os << "Santa Fe";
            break;
        case City::Denver:
            os << "Denver";
            break;
        case City::Houston:
            os << "Houston";
            break;
        case City::Dallas:
            os << "Dallas";
            break;
        case City::OkalahomaCity:
            os << "Okalahoma City";
            break;
        case City::KansasCity:
            os << "Kansas City";
            break;
        case City::Omaha:
            os << "Omaha";
            break;
        case City::Duluth:
            os << "Duluth";
            break;
        case City::SaultStMarie:
            os << "Sault St Marie";
            break;
        case City::NewOrleans:
            os << "New Orleans";
            break;
        case City::LittleRock:
            os << "Little Rock";
            break;
        case City::SaintLouis:
            os << "Saint Louis";
            break;
        case City::Chicago:
            os << "Chicago";
            break;
        case City::Toronto:
            os << "Toronto";
            break;
        case City::Montreal:
            os << "Montreal";
            break;
        case City::Nashville:
            os << "Nashville";
            break;
        case City::Pittsburgh:
            os << "Pittsburgh";
            break;
        case City::NewYork:
            os << "NewYork";
            break;
        case City::Boston:
            os << "Boston";
            break;
        case City::Atlanta:
            os << "Atlanta";
            break;
        case City::Raleigh:
            os << "Raleigh";
            break;
        case City::Washington:
            os << "Washington";
            break;
        case City::Miami:
            os << "Miami";
            break;
        case City::Charleston:
            os << "Charleston";
            break;        
    }
}

