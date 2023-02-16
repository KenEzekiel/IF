#include "User.h"
#include "PremiumUser.h"
#include "ArtistUser.h"
#include <iostream>

using namespace std;

int main()
{
    char *A = "A";
    char *B = "B";
    char *C = "C";
    char *X = "Titanix";
    char *Y = "Titanix";
    User a(A);
    a.addFavouriteMusic(X);
    a.addFavouriteMusic(Y);
    a.deleteFavouriteMusic(X);
    a.setName(A);
    a.viewMusicList();

    int n = a.getNumOfUser();

    PremiumUser b(B);
    b.addFavouriteMusic(X);
    b.addFavouriteMusic(Y);
    b.deleteFavouriteMusic(Y);
    b.setName(B);
    b.viewMusicList();
    b.downloadMusic(X);

    ArtistUser c(C);
    c.addFavouriteMusic(X);
    c.addFavouriteMusic(Y);
    c.deleteFavouriteMusic(Y);
    c.setName(C);
    c.viewMusicList();
    c.uploadMusic(X);
    c.uploadMusic(Y);
    c.deleteUploadedMusic(X);
    c.viewUploadedMusicList();

    int m = c.getNumOfMusicUploaded();
    int l = c.getNumOfArtist();

    cout << n
         << m
         << l
         << endl;

    return 0;
}
