#include <iostream>
#include "SpacingGuildShip.hpp"

float SpacingGuildShip::totalGuildTravel = 0;
int SpacingGuildShip::producedShips = 0;

SpacingGuildShip::SpacingGuildShip() : maxPassengerCap(50), guildNavigatorCount(3), serialNum(producedShips + 1)
{
    this->passengerCount = 0;
    this->operatingGuildNavigator = this->guildNavigatorCount;
    this->spiceStock = 50;
    producedShips++;
}

SpacingGuildShip::SpacingGuildShip(int maxPassengerCap, int guildNavigatorCount, int spiceStock) : maxPassengerCap(maxPassengerCap), guildNavigatorCount(guildNavigatorCount), serialNum(producedShips + 1)
{
    this->passengerCount = 0;
    this->operatingGuildNavigator = this->guildNavigatorCount;
    this->spiceStock = spiceStock;
    producedShips++;
}

SpacingGuildShip::SpacingGuildShip(const SpacingGuildShip &other) : maxPassengerCap(other.maxPassengerCap), guildNavigatorCount(other.guildNavigatorCount), serialNum(producedShips + 1)
{
    this->passengerCount = other.passengerCount;
    // gayakin ini pake this atau other operatingGuildNav
    this->operatingGuildNavigator = other.operatingGuildNavigator;
    this->spiceStock = other.spiceStock;
}

SpacingGuildShip::~SpacingGuildShip()
{
}

int SpacingGuildShip::getShipSerialNum() const
{
    return this->serialNum;
}

int SpacingGuildShip::getPassengerCount() const
{
    return this->passengerCount;
}

void SpacingGuildShip::travel(float distance)
{
    if (this->operatingGuildNavigator != 0)
    {
        totalGuildTravel += distance / (E * E * this->operatingGuildNavigator);
        this->operatingGuildNavigator--;
    }
}

void SpacingGuildShip::boarding(int addedPassengers)
{
    if (this->passengerCount + addedPassengers > this->maxPassengerCap)
    {
        this->passengerCount = this->maxPassengerCap;
    }
    else
    {
        this->passengerCount += addedPassengers;
    }
}

void SpacingGuildShip::dropOff(int droppedPassengers)
{
    if (this->passengerCount - droppedPassengers < 0)
    {
        this->passengerCount = 0;
    }
    else
    {
        this->passengerCount -= droppedPassengers;
    }
}

void SpacingGuildShip::refreshNavigator(int n)
{
    int i = 0;
    // is there a more objective approach?
    while (this->spiceStock >= GUILD_NAVIGATOR_SPICE_DOSE && i < n)
    {

        if (this->operatingGuildNavigator < this->guildNavigatorCount)
        {
            this->operatingGuildNavigator++;
        }
        else
        {
            break;
        }
        this->spiceStock -= GUILD_NAVIGATOR_SPICE_DOSE;
        i++;
    }
}

void SpacingGuildShip::transitToArrakis(int addedSpice)
{
    this->spiceStock += addedSpice;
}