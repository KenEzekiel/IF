#include "ExplodableBarrel.hpp"
#include "Explodable.hpp"
#include "Damageable.hpp"

// Default Constructor
  // health dari ExplodableBarrel selalu 1 dan
  // default radiusnya adalah 5
ExplodableBarrel::ExplodableBarrel() : Damageable(1) {
    this->radius = 5;
}

  // Masukan: radius (integer positif) dan baseDamage (integer positif)
  // health dari ExplodableBarrel selalu 1
ExplodableBarrel::ExplodableBarrel(int r, int bdmg) : Damageable(1), Explodable(bdmg) {
    this->radius = r;
}

  // Masukan: damage (integer positif) dan element (string)
  //
  // Berikut adalah urutan aksi yang dilakukan:
  //
  // Apabila barrel telah hancur, maka tidak akan terjadi
  // apa-apa.
  //
  // Barrel menerima damage dan tidak menghiraukan element.
  // Apabila barrel hancur setelah menerima damage, maka
  // barrel akan meledak sebesar radius yang telah ditentukan.
void ExplodableBarrel::takeDamage(int dmg, string elmt) {
    if (!this->isDestroyed()) {
        this->Damageable::takeDamage(dmg);
        if (this->isDestroyed()) {
            this->explode(this->radius);
        }
    }
} 