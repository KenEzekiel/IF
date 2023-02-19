//
// Created by akbar on 16/02/2023.
//
#include "User.h"
#include <iostream>

using namespace std;

int User::n_user = 0;

User::User(char * name) {
    this->name = new char[strlen(name)];
    strcpy(this->name, name);
    this->num_of_favourite_music = 0;
    this->music_list = new char*[3000];
    User::n_user++;
}

User::User(const User &other) {
    this->name = new char[strlen(other.name)];
    this->music_list = new char*[3000];
    strcpy(this->name, other.getName());

    this->num_of_favourite_music = other.num_of_favourite_music;

    for (int i = 0; i < this->num_of_favourite_music; i++) {
        this->music_list[i] = new char[strlen(other.music_list[i])];
        strcpy(this->music_list[i], other.music_list[i]);
    }

    User::n_user++;
}

User::~User() {
    cout << "User " << this->name << " deleted" << endl;
    delete[] this->music_list;
    delete[] name;
}

void User::addFavouriteMusic(char * music) {
    this->music_list[num_of_favourite_music] = new char[strlen(music)];
    strcpy(this->music_list[num_of_favourite_music], music);
    num_of_favourite_music++;
}

void User::deleteFavouriteMusic(char * toDelete) {
    int deleteIdx = -1;
    int i = 0;
    while (deleteIdx == -1 && i < num_of_favourite_music) {
        if (strcmp(toDelete, this->music_list[i]) == 0) {
            deleteIdx = i;
        } else {
            i++;
        }
    }

    if (deleteIdx == -1) {
        return;
    }

    for (int j = deleteIdx; j < num_of_favourite_music - 1; j++) {
        this->music_list[j] = new char[strlen(this->music_list[j+1])];
        strcpy(this->music_list[j], this->music_list[j+1]);
    }

    num_of_favourite_music--;
}

void User::setName(char * newName) {
    this->name = new char[strlen(newName)];
    strcpy(this->name, newName);
}

char *User::getName() const {
    return this->name;
}

int User::getNumOfFavouriteMusic() const {
    return this->num_of_favourite_music;
}

void User::viewMusicList() const {
    if (this->num_of_favourite_music == 0) {
        cout << "No music in your favourite list" << endl;
    } else {
        for (int i = 0; i < num_of_favourite_music; i++) {
            cout << i+1 << ". " << this->music_list[i] << endl;
        }
    }
}

int User::getNumOfUser() {
    return User::n_user;
}

