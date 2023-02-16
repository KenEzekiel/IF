
#include <iostream>
#include "User.h"

using namespace std;

int User::n_user = 0;

// ctor, parameter: nama pengguna
User::User(char *nm)
{
    this->name = new char[strlen(nm) + 1];
    strcpy(this->name, nm);
    this->num_of_favourite_music = 0;
    this->music_list = new char *[1000];
    n_user++;
}

// cctor
User::User(const User &other)
{
    this->name = new char[strlen(other.name) + 1];
    strcpy(this->name, other.name);
    this->num_of_favourite_music = other.num_of_favourite_music;
    this->music_list = new char *[1000];
    for (int i = 0; i < num_of_favourite_music; i++)
    {
        this->music_list[i] = new char[strlen(other.music_list[i]) + 1];
        strcpy(this->music_list[i], other.music_list[i]);
    }
    n_user++;
}

// dtor
// selain implementasi, print juga "User <nama user> deleted<endl>"
// Contoh:
// User A deleted
//
User::~User()
{
    cout << "User " << this->name << " deleted" << endl;
    delete[] this->name;
    delete[] this->music_list;
}

// Asumsi: musik unik, parameter: judul musik
void User::addFavouriteMusic(char *title)
{
    this->music_list[num_of_favourite_music] = new char[strlen(title) + 1];
    strcpy(this->music_list[num_of_favourite_music], title);
    this->num_of_favourite_music++;
}
void User::deleteFavouriteMusic(char *title)
{
    int idx = -1;
    int i = 0;
    while (idx == -1 && i < this->num_of_favourite_music)
    {
        if (strcmp(title, this->music_list[i]) == 0)
        {
            idx = i;
        }
        else
        {
            i++;
        }
    }

    if (idx == -1)
    {
        return;
    }

    for (int j = idx; j < this->num_of_favourite_music - 1; j++)
    {
        this->music_list[j] = new char[strlen(this->music_list[j + 1])];
        strcpy(this->music_list[j], this->music_list[j + 1]);
    }

    this->num_of_favourite_music--;
}

void User::setName(char *nm)
{
    this->name = new char[strlen(nm) + 1];
    strcpy(this->name, nm);
}
char *User::getName() const { return this->name; }
int User::getNumOfFavouriteMusic() const { return this->num_of_favourite_music; }

// format print:
// <No>. <Judul musik><endl>
// contoh:
// 1. Starship - Nicki Minaj
// 2. To Be Human - Sia, Labrinth
//
// jika tidak ada musik, print: "No music in your favourite list<endl>"
void User::viewMusicList() const
{
    if (this->num_of_favourite_music == 0)
    {
        cout << "No music in your favourite list" << endl;
    }
    else
    {
        for (int i = 0; i < this->num_of_favourite_music; i++)
        {
            cout << i + 1 << ". " << this->music_list[i] << endl;
        }
    }
}

int User::getNumOfUser()
{
    return n_user;
}

// char *name;
// int num_of_favourite_music; // jumlah musik yang ada pada music_list
// char **music_list;          // daftar judul musik
// static int n_user;
