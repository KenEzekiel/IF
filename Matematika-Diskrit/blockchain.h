#include <stdlib.h>
#include <memory.h>
#include "sha256.h"

#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H

typedef struct list
{
    /* data */
    BYTE buffer[256];
} List;

typedef struct block *pBlock;

typedef struct block
{
    /* data */
    BYTE prevHash[SHA256_BLOCK_SIZE];
    List data;
    BYTE blockHash[SHA256_BLOCK_SIZE];
    pBlock nextBlock;

} Block;

typedef struct blockchain
{
    pBlock first;
    pBlock last;
} Blockchain;

// SHA-256 Cryptographic Hash Function, Implemented by Brad Conte
void hash(List Data, BYTE *Hash[]);

void hashBlock(Block B, BYTE Hash[32]);

// Make a new block
pBlock newBlock(List Data, BYTE prevHash[]);

// Initialize block with the address of the first block (empty)
Blockchain initBlock();

// Insert Data to a new block then insert it into the blockchain
void insertData(Blockchain *BC);

void printBlock(Blockchain BC);

#endif