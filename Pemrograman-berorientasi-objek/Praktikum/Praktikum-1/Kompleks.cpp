#include <iostream>
#include "Kompleks.h"

using namespace std;

int Kompleks::n_kompleks = 0;

Kompleks::Kompleks() {
	n_kompleks += 1;
	this->real = 0;
	this->imaginer = 0;
}

Kompleks::Kompleks(int real, int imaginer) {
	n_kompleks += 1;
	this->real = real;
	this->imaginer = imaginer;
}

int Kompleks::GetReal() const {
	return real;
}

int Kompleks::GetImaginer() const {
	return imaginer;
}

void Kompleks::SetReal(int r) {
	real = r;
}

void Kompleks::SetImaginer(int i) {
	imaginer = i;
}

Kompleks operator+(const Kompleks& a, const Kompleks& b) {
	Kompleks temp(a.GetReal() + b.GetReal(), a.GetImaginer() + b.GetImaginer());
	return temp;
}

Kompleks operator-(const Kompleks& a, const Kompleks& b) {
	Kompleks temp(a.GetReal() - b.GetReal(), a.GetImaginer() - b.GetImaginer());
	return temp;
}

Kompleks operator*(const Kompleks& a, const Kompleks& b) {
	// ac - bd , bc + ad
	int r = a.GetReal() * b.GetReal() - a.GetImaginer() * b.GetImaginer();
	int i = a.GetImaginer() * b.GetReal() + a.GetReal() * b.GetImaginer();
	Kompleks temp(r, i);
	return temp;
}

Kompleks operator*(const Kompleks& a, const int b) {
	Kompleks temp(a.GetReal() * b, a.GetImaginer() * b);
	return temp;
}

Kompleks operator*(const int b, const Kompleks& a) {
	Kompleks temp(a.GetReal() * b, a.GetImaginer() * b);
	return temp;
}

int Kompleks::CountKompleksInstance() {
	return n_kompleks;
}

void Kompleks::Print() {
	if (imaginer < 0) {
		cout << real << imaginer << "i" << endl;
	} else {
		cout  << real << "+" << imaginer << "i" << endl;		
	}
}