//
//  Blockchain.cpp
//  Blockchain
//
//  Created by William Williams on 3/22/18.
//  Copyright © 2018 DSC. All rights reserved.
//

#include "Blockchain.h"

/*
 * Constructor
 */
Blockchain::Blockchain()
{
    vChain.emplace_back(Block(0, "Genesis Block"));

    nDifficulty = 6;
}

/*
 * Add Block to chain function
 */
void Blockchain::AddBlock(Block bNew)
{
    bNew.SetTransactionPrevHash(GetLastBlock().GetTransactionHash());

    bNew.GenerateValidHash(nDifficulty);

    vChain.push_back(bNew);
}

/*
 * Get Last block function
 */
Block Blockchain::GetLastBlock() const
{
    return vChain.back();
}
