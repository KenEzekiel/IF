#include "PremiumUser.h"
#include <iostream>

using namespace std;

PremiumUser::PremiumUser(char *name): User(name) {
    this->num_of_music_downloaded = 0;
    this->active = true;
}

PremiumUser::PremiumUser(const PremiumUser & other) : User(other) {
    this->num_of_music_downloaded = other.num_of_music_downloaded;
    this->active = other.active;
//    cout << "Premium User Copied" << endl; // todo: hapus?
}

PremiumUser::~PremiumUser() {
//    cout << "Premium user " << this->name << " deleted" << endl;
}

void PremiumUser::downloadMusic(char * musicName) {
    if (this->active) {
        cout << "Music Downloaded: " << musicName << endl;
        this->num_of_music_downloaded++;
    } else {
        cout << "Activate premium account to download music" << endl;
    }
}

void PremiumUser::inactivatePremium() {
    this->active = false;
}

void PremiumUser::activatePremium() {
    this->active = true;
}

int PremiumUser::getNumOfMusicDownloaded() const {
    return this->num_of_music_downloaded;
}

bool PremiumUser::getPremiumStatus() const {
    return this->active;
}
