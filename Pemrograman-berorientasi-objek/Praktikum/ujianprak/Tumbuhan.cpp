#include <iostream>
using namespace std;

class Tumbuhan {
private:
    string pemilik;
public:
    Tumbuhan(string pemilik) {
        this->pemilik = pemilik;
    };

    // Print dan Print 2 memiliki format yang sama yaitu
    // (X) <kalimat unik setiap kelas>
    // (X) diisi dengan (1) untuk print, (2) untuk print 2
    // berlaku untuk kelas turunan.
    void print() {
    }

    // Print dan Print 2 memiliki format yang sama yaitu
    // (X) <kalimat unik setiap kelas>
    // (X) diisi dengan (1) untuk print, (2) untuk print 2
    // berlaku untuk kelas turunan.
    void print2() {
    }

    ~Tumbuhan(){
    };
};


class TumbuhanMakan: public Tumbuhan {
protected:
    string idPot;
public:
    TumbuhanMakan(string pemilik, string idPot) : Tumbuhan(pemilik) {
        this->idPot = idPot;
    };

    void print() {
    }

    void print2() {
    }

    ~TumbuhanMakan(){
    };
};

class TumbuhanObat : public Tumbuhan {
protected:
    string idPot;
public:
    TumbuhanObat(string pemilik, string idPot) : Tumbuhan(pemilik) {
        this->idPot = idPot;
    };

    void print() {
    }

    void print2() {
    }

    ~TumbuhanObat(){
    };
};

class Jagung : public TumbuhanMakan {
public:
    Jagung(string pemilik, string idPot) : TumbuhanMakan(pemilik, idPot) {
    };

    void print() {
    }

    void print2() {
    }

    ~Jagung(){
    };
};


class Padi : public TumbuhanMakan {
public:
    Padi(string pemilik, string idPot) : TumbuhanMakan(pemilik, idPot) {
    };

    void print() {
    }

    void print2() {
    }

    ~Padi(){
    };
};

class Jahe : public TumbuhanObat {
public:
    Jahe(string pemilik, string idPot) : TumbuhanObat(pemilik, idPot) {
    };

    void print() {
    }

    void print2() {
    }

    ~Jahe(){
    };
};

class Kencur : public TumbuhanObat {
public:
    Kencur(string pemilik, string idPot) : TumbuhanObat(pemilik, idPot) {
    };

    void print() {
    }

    void print2() {
    }

    ~Kencur(){
    };
};