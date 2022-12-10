#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sha256.h"
#include "blockchain.h"

void printHash(BYTE hash[32])
{
    // LOCAL ALGORITHM
    int i;
    // ALGORITHM
    for (i = 0; i < 32; i++)
    {
        if (i > 0)
            printf(":");
        printf("%02X", hash[i]);
    }
    printf("\n");
}

// SHA-256 Cryptographic Hash Function, Implemented by Brad Conte
void hash(List Data, BYTE *Hash[])
{
    // LOCAL DICTIONARY
    BYTE buf[SHA256_BLOCK_SIZE];
    SHA256_CTX ctx;

    // ALGORITHM

    sha256_init(&ctx);
    sha256_update(&ctx, Data.buffer, strlen(Data.buffer));
    sha256_final(&ctx, buf);

    *Hash = buf;
}

void hashBlock(Block B, BYTE Hash[32])
{
    // LOCAL DICTIONARY
    BYTE buf[SHA256_BLOCK_SIZE];
    SHA256_CTX ctx;
    int newSize = strlen(B.data.buffer) + strlen(B.prevHash);
    BYTE *newBuffer = (BYTE *)malloc(newSize);

    // ALGORITHM
    strcpy(newBuffer, B.data.buffer);
    strcat(newBuffer, B.prevHash);

    sha256_init(&ctx);
    sha256_update(&ctx, newBuffer, strlen(newBuffer));
    sha256_final(&ctx, buf);

    // printf("Hash: ");
    // printHash(buf);

    int i;
    for (i = 0; i < 32; i++)
    {
        strcpy(&Hash[i], &buf[i]);
    }
}

// Make a new block
pBlock newBlock(List Data, BYTE prevHash[])
{
    // LOCAL DICTIONARY
    pBlock p;

    // ALGORITHM
    p = (pBlock)malloc(sizeof(Block));
    if (p != NULL)
    {

        int i;
        for (i = 0; i < 32; i++)
        {
            strcpy(&p->prevHash[i], &prevHash[i]);
        }
        p->data = Data;
        p->nextBlock = NULL;
    }
    return p;
}

// Initialize block with the address of the first block
Blockchain initBlock()
{
    // LOCAL DICTIONARY
    List tempData;
    pBlock p;
    Blockchain BC;
    // arbitrary prevHash value
    BYTE hash[SHA256_BLOCK_SIZE] = {0xba, 0x78, 0x16, 0xbf, 0x8f, 0x01, 0xcf, 0xea, 0x41, 0x41, 0x40, 0xde, 0x5d, 0xae, 0x22, 0x23, 0xb0, 0x03, 0x61, 0xa3, 0x96, 0x17, 0x7a, 0x9c, 0xb4, 0x10, 0xff, 0x61, 0xf2, 0x00, 0x15, 0xad};
    BYTE blockHash[SHA256_BLOCK_SIZE];

    // ALGORITHM

    printf("Insert data string: \n");
    scanf("%s", tempData.buffer);
    p = newBlock(tempData, hash);
    hashBlock(*p, blockHash);

    int i;
    for (i = 0; i < 32; i++)
    {
        strcpy(&p->blockHash[i], &blockHash[i]);
    }

    BC.first = p;
    BC.last = p;
    return BC;
}

// Insert Data to a new block then insert it into the blockchain
void insertData(Blockchain *BC)
{
    // LOCAL DICTIONARY
    List tempData;
    pBlock p;
    BYTE prevhash[SHA256_BLOCK_SIZE];
    BYTE blockHash[SHA256_BLOCK_SIZE];
    int i;

    // ALGORITHM
    for (i = 0; i < 32; i++)
    {
        strcpy(&prevhash[i], &BC->last->blockHash[i]);
    }

    printf("Insert data string: \n");
    scanf("%s", tempData.buffer);
    p = newBlock(tempData, prevhash);
    // printf("prevhash:\n");
    // printHash(prevhash);
    hashBlock(*p, blockHash);
    // printf("blockhash:\n");
    // printHash(blockHash);

    for (i = 0; i < 32; i++)
    {
        strcpy(&p->blockHash[i], &blockHash[i]);
    }
    BC->last->nextBlock = p;
    BC->last = p;
}

void printBlock(Blockchain BC)
{
    // LOCAL DICTIONARY
    pBlock p;

    // ALGORITHM
    p = BC.first;
    while (p != BC.last)
    {
        printf("\nPrevious Block Hash: \n");
        printHash(p->prevHash);
        printf("Data: %s\n", p->data.buffer);
        printf("Block Hash: \n");
        printHash(p->blockHash);
        p = p->nextBlock;
    }
    printf("\nPrevious Block Hash: \n");
    printHash(p->prevHash);
    printf("Data: %s\n", p->data.buffer);
    printf("Block Hash: \n");
    printHash(p->blockHash);
    printf("\n");
}
