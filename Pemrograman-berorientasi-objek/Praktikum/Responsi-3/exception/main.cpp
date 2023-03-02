#include "exception.h"
#include "memo.h"
#include "sekretaris.h"
#include <string>
#include <iostream>
using namespace std;

int main()
{
    Sekretaris a;

    string pesan = "haiaiaiaiaiaiaiaiiaiaiaiaiaiaiaiaaa";
    string untuk = "aku";

    a.buatMemo(pesan, untuk);
    a.printStatus();

    Memo b(pesan, untuk);
    cout << b.getPesan() << " " << b.getUntuk() << endl;

    a.buatMemo(pesan, untuk);
    a.printStatus();

    a.buatMemo(pesan, untuk);
    a.printStatus();

    return 0;
}