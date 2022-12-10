#include <stdio.h>
#include "blockchain.h"
#include "sha256.h"

int main()
{
    Blockchain BC = initBlock();

    insertData(&BC);
    insertData(&BC);

    printBlock(BC);

    return 0;
}