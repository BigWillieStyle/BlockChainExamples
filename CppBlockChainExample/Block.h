//
//  Block.h
//  Blockchain
//
//  Created by William Williams on 3/22/18.
//  Copyright © 2018 DSC. All rights reserved.
//

#ifndef Block_h
#define Block_h

#include <cstdint>
#include <iostream>

using namespace std;

class Block
{
public:
    Block(uint32_t transactionIndexIn, const string &transactionDataIn);
    string GetTransactionHash();
    void SetTransactionPrevHash(const string &transactionPrevHashIn);
    void GenerateValidHash(uint32_t nDifficulty);

private:
    uint32_t transactionIndex;
    int64_t powNonce;
    string transactionData;
    string transactionHash;
    string transactionPrevHash;
    time_t transactionTime;
    string _CalculateHash() const;
};

#endif /* Block_h */
