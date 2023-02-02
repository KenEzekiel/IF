// Item.cpp

#include <iostream>
#include "Item.hpp"

int Item::totalItems = 0;
int Item::totalRevenue = 0;

// Implementasi Ctor

Item::Item() : serialNum(totalItems + 1)
{
    this->stock = 0;
    this->price = 0;
    this->sold = 0;
    totalItems++;
}

Item::Item(int stock, int price) : serialNum(totalItems + 1)
{
    this->stock = stock;
    this->price = price;
    this->sold = 0;
    totalItems++;
}

// Implementasi Cctor

Item::Item(const Item &other) : serialNum(totalItems + 1)
{
    this->stock = other.stock;
    this->price = other.price;
    this->sold = 0;
    totalItems++;
}

Item::~Item()
{
    // std::cout << "item desc" << std::endl;
    // totalItems--;
}

int Item::getSerialNum() const
{
    return this->serialNum;
}

int Item::getSold() const
{
    return this->sold;
}

int Item::getPrice() const
{
    return this->price;
}

void Item::addStock(int addedStock)
{
    if (this->stock + addedStock >= 0)
    {
        this->stock += addedStock;
    }
}

void Item::sell(int soldStock)
{
    if (this->stock < soldStock)
    {
        // urutannya kebalik tadi, kalo diset ke 0 dulu stocknya nanti malah ganambah total rev nya
        this->sold += this->stock;
        totalRevenue += this->stock * this->price;
        this->stock = 0;
    }
    else
    {
        this->sold += soldStock;
        totalRevenue += soldStock * this->price;
        this->stock -= soldStock;
    }
}

void Item::setPrice(int newPrice)
{
    this->price = newPrice;
}

// int Item::getStock() const
// {
//     return this->stock;
// }