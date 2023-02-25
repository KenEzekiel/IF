#include <iostream>

using namespace std;

template <class T>
void PrintArray(const T x[], int N)
{
    if (N == 0)
    {
        cout << "Array kosong" << endl;
        return;
    }
    else
    {
        cout << "[";
        for (int i = 0; i < N; i++)
        {
            cout << x[i];
            if (i != N - 1)
            {
                cout << ",";
            }
        }
        cout << "]" << endl;
    }
}

int main()
{
    int I[5] = {1, 2, 3, 4, 5};
    float F[5] = {0.2, 1.4, 4.5, 9.8, 10.08};
    char A[5] = {'a', 'b', 'c', 'd', 'e'};

    PrintArray<int>(I, 5);
    PrintArray<float>(F, 5);
    PrintArray<char>(A, 5);

    return 0;
}

// Jika yang ingin dicetak adalah point, akan dilakukan dengan PrintArray<Point>, dan hanya bisa dilakukan dengan fungsi non-template, karena membutuhkan format sendiri yaitu self.x, self.y