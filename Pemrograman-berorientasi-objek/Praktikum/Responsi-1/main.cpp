#include "A.hpp"
#include "BigNumber.hpp"
#include <iostream>

int main()
{
	// A a('1');
	// A b('2');
	// A c(a);
	// c = b;
	// b.show();

	BigNumber HAHA(123);
	BigNumber hehe(107);

	BigNumber H = HAHA + hehe;
	for (int i = 0; i < BigNumber::getMaxDigit(); i++)
	{
		std::cout << H[i];
	}
}