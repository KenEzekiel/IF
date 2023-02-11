#include "Kompleks.h"
#include <iostream>

int main () {
	Kompleks a;
	Kompleks b(1, 2);

	a.Print();
	b.Print();
	(a + b).Print();
	(a * b).Print();
	(a - b).Print();




	return 0;
}