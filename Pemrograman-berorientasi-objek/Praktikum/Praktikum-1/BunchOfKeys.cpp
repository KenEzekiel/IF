#include <iostream>
#include "BunchOfKeys.hpp"

using namespace std;

BunchOfKeys::BunchOfKeys() {
	this->n_keys = 0;
}

void BunchOfKeys::add() {
	this->n_keys += 1;
}

void BunchOfKeys::shake() {
	int nkeylocal = this->n_keys;

	if (nkeylocal > 1) {
		for (int i = 0; i < nkeylocal; i++) {
			cout << "krincing" << endl;
		}
	} else {
		cout << "Tidak terjadi apa-apa" << endl;
	}
}

// int main () {
// 	return 0;
// }