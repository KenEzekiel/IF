#include "BurnableBarrel.hpp"
#include "Burnable.hpp"
#include "Damageable.hpp"


// Default Constructor
BurnableBarrel::BurnableBarrel() {

}

  // Masukan: health (integer positif)
BurnableBarrel::BurnableBarrel(int h) : Damageable(h) {}

  // Masukan: damage (integer positif) dan element (string)
  //
  // Berikut adalah urutan aksi yang dilakukan:
  //
  // Apabila barrel telah hancur, maka tidak akan terjadi
  // apa-apa.
  //
  // Apabila barrel menerima damage element berupa "fire",
  // maka akan mengaktifkan status burned. Apabila barrel
  // menerima damage element berupa "water", maka status
  // burned akan dinonaktifkan.
  //
  // Setelah update status burned, Jika barrel dalam kondisi
  // burned, maka damagenya akan dikalikan dengan konstanta
  // multiplier. Jika tidak, maka damagenya tidak berubah.
void BurnableBarrel::takeDamage(int dmg, string elmt) {
    if (!this->isDestroyed()) {
        if (elmt == "fire") {
            this->burn();
        }
        if (elmt == "water") {
            this->watered();
        }
        if (this->isBurned()) {
            this->Damageable::takeDamage(dmg * this->multiplier);
        } else {
            this->Damageable::takeDamage(dmg);
        }
        
    }
}