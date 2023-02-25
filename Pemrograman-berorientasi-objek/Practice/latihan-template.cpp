#include <iostream>

using namespace std;

template <class T>
T MinArray(T x[], int N)
{
    T min = x[0];
    for (int i = 1; i < N; i++)
    {
        if (x[i] < min)
        {
            min = x[i];
        }
    }
    return min;
}

int main()
{
    int I[5] = {1, 2, 3, 4, 5};
    float F[5] = {1, 2.2, 0.5, 5, 0.1};

    int minI = MinArray<int>(I, 5);
    float minF = MinArray<float>(F, 5);

    cout << minI << endl
         << minF << endl;

    return 0;
}

// Untuk kelas Jam HH:MM:SS, mungkin MinArray digunakan untuk data bertipe Jam jika kelas Jam tersebut memiliki cara untuk membandingkan value nya (operator comparison)
