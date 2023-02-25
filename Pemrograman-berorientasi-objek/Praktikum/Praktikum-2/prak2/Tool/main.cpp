#include "Tool.hpp"
#include "Pickaxe.hpp"
#include "ReinforcedAxe.hpp"


int main() {

    Pickaxe a;
    a.use();
    a.enchant();
    Pickaxe b(a);
    Pickaxe* c = new Pickaxe();
    *c = b;
    ReinforcedAxe* d = new ReinforcedAxe();

    d->use();
    ReinforcedAxe* e = new ReinforcedAxe(*d);
    d->enchant();
    ReinforcedAxe f = *d + *e;
    f.repair();
    delete d;
    delete e;

    return 0;
}