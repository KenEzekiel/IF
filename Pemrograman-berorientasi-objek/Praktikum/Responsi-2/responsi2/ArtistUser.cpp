
#include "User.h"
#include "ArtistUser.h"
#include <iostream>

using namespace std;

int ArtistUser::num_of_artist = 0;

// ctor, parameter: nama pengguna
ArtistUser::ArtistUser(char *nm) : User(nm)
{
    this->num_of_music_uploaded = 0;
    this->uploaded_music_list = new char *[1000];
    num_of_artist++;
}

// cctor
ArtistUser::ArtistUser(const ArtistUser &other) : User(other)
{
    this->num_of_music_uploaded = other.num_of_music_uploaded;
    this->uploaded_music_list = new char *[1000];

    for (int i = 0; i < this->num_of_music_uploaded; i++)
    {
        this->uploaded_music_list[i] = new char[strlen(other.uploaded_music_list[i]) + 1];
        strcpy(this->uploaded_music_list[i], other.uploaded_music_list[i]);
    }
    num_of_artist++;
}

// dtor
// selain implementasi, print juga "Artist user <nama user> deleted"
// Contoh:
// Artist user A deleted
ArtistUser::~ArtistUser()
{
    cout << "Artist user " << name << " deleted" << endl;
    delete[] this->uploaded_music_list;
}

// Asumsi: musik unik, parameter: judul musik
void ArtistUser::uploadMusic(char *title)
{
    this->uploaded_music_list[num_of_music_uploaded] = new char[strlen(title) + 1];
    strcpy(this->uploaded_music_list[num_of_music_uploaded], title);
    this->num_of_music_uploaded++;
}
void ArtistUser::deleteUploadedMusic(char *title)
{
    int idx = -1;
    int i = 0;
    while (idx == -1 && i < this->num_of_music_uploaded)
    {
        if (strcmp(title, this->uploaded_music_list[i]) == 0)
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

    for (int j = idx; j < this->num_of_music_uploaded - 1; j++)
    {
        this->uploaded_music_list[j] = new char[strlen(this->uploaded_music_list[j + 1]) + 1];
        strcpy(this->uploaded_music_list[j], this->uploaded_music_list[j + 1]);
    }

    num_of_music_uploaded--;
}

// format print:
// <No>. <Judul musik><endl>
// contoh:
// 1. Starship - Nicki Minaj
// 2. To Be Human - Sia, Labrinth
//
// jika tidak ada musik, print: "No music uploaded<endl>"
void ArtistUser::viewUploadedMusicList() const
{
    if (this->num_of_music_uploaded == 0)
    {
        cout << "No music in uploaded" << endl;
    }
    else
    {
        for (int i = 0; i < this->num_of_music_uploaded; i++)
        {
            cout << i + 1 << ". " << this->uploaded_music_list[i] << endl;
        }
    }
}
int ArtistUser::getNumOfMusicUploaded() const { return this->num_of_music_uploaded; }
int ArtistUser::getNumOfArtist()
{
    return num_of_artist;
}

// int num_of_music_uploaded; // jumlah musik dalam uploaded_music_list
// char **uploaded_music_list;
// static int num_of_artist;
