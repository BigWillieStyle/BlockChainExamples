//
//  Blockchain.h
//  Blockchain
//
//  Created by William Williams on 3/22/18.
//  Copyright © 2018 DSC. All rights reserved.
//

#ifndef Blockchain_h
#define Blockchain_h

#include <cstdint>
#include <vector>
#include "Block.h"

using namespace std;

class Blockchain
{
public:
    Blockchain();
    void AddBlock(Block bNew);
    
private:
    uint32_t nDifficulty;
    vector<Block> vChain;
    Block GetLastBlock() const;
};

#endif /* Blockchain_h */
