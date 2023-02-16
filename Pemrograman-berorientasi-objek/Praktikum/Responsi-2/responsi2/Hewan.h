#ifndef HEWAN_HPP
#define HEWAN_HPP

#include <iostream>
#include <string>

using namespace std;

class Hewan
{
protected:
    string nama;

public:
    Hewan(string nm) { nama = nm; }
    ~Hewan() { cout << "Hewan mati " << nama << endl; }
    virtual void print() { cout << "Hewan ini namanya " << nama << endl; }
};

class Anjing : public Hewan
{
public:
    Anjing(string nm) : Hewan(nm) {}
    // biar pas anjing di dtor, child nya ga di dtor
    ~Anjing() { cout << "Anjing mati " << nama << endl; }
    virtual void print() { cout << "Anjing ini namanya " << nama << endl; }
};

class Kucing : public Hewan
{
public:
    Kucing(string nm) : Hewan(nm) {}
    virtual ~Kucing() { cout << "Kucing mati " << nama << endl; }
};

class AnjingBulldog : public Anjing
{
protected:
    string pemilik;

public:
    AnjingBulldog(string nm, string pm) : Anjing(nm) { pemilik = pm; }
    ~AnjingBulldog() { cout << "Anjing bulldog mati " << nama << endl; }
    void print() { cout << "Anjing bulldog ini namanya " << nama << ". Pemiliknya adalah " << pemilik << endl; }
};

class KucingAnggora : public Kucing
{
protected:
    string pemilik;

public:
    KucingAnggora(string nm, string pm) : Kucing(nm) { pemilik = pm; }
    ~KucingAnggora() { cout << "Kucing anggora mati " << nama << endl; }
    void print() { cout << "Kucing anggora ini namanya " << nama << ". Pemiliknya adalah " << pemilik << endl; }
};

#endif