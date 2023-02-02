#include "Item.hpp"
#include <iostream>

int main()
{
    Item coklat;

    Item keju(5, 10);

    Item mangga(keju);

    std::cout << "Serial num keju:" << keju.getSerialNum() << std::endl;
    std::cout << "Serial num mangga:" << mangga.getSerialNum() << std::endl;
    std::cout << "mangga terjual: " << mangga.getSold() << " " << mangga.getStock() << std::endl;
    std::cout << "harga mangga: " << mangga.getPrice() << std::endl;

    mangga.addStock(5);
    std::cout << "mangga terjual: " << mangga.getSold() << " " << mangga.getStock() << std::endl;

    mangga.sell(5);
    std::cout << Item::totalRevenue << std::endl;
    std::cout << "mangga terjual: " << mangga.getSold() << " " << mangga.getStock() << std::endl;

    mangga.setPrice(20);
    mangga.sell(10);
    std::cout << Item::totalRevenue << std::endl;
    keju.setPrice(20);
    keju.sell(1);
    std::cout << Item::totalRevenue << std::endl;

    std::cout << "mangga terjual: " << mangga.getSold() << std::endl;
    std::cout << "keju terjual: " << keju.getSold() << std::endl;
    std::cout << "harga keju: " << keju.getPrice() << std::endl;

    std::cout << Item::totalItems << std::endl;
    std::cout << Item::totalRevenue << std::endl;

    return 0;
}