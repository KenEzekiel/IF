#include "Paper.hpp"

using namespace std;

int main() {
	Paper A('A');
	Paper B('B');
	Paper C('C');

	Paper D(C);

	A.fold();
	B.fold();
	C.fold();

	C.glue();

	C.setName('X');

	D.fold();

	D.glue();


}