//
//  Block.cpp
//  Blockchain
//
//  Created by William Williams on 3/22/18.
//  Copyright © 2018 DSC. All rights reserved.
//

#include <stdio.h>
#include <time.h>
#include <sstream>
#include "Block.h"
#include "./sha/sha256.h"

/*
 * Constructor
 */
Block::Block(uint32_t transactionIndexIn, const string &transactionDataIn) : transactionIndex(transactionIndexIn), transactionData(transactionDataIn)
{
    cout << "New Block with Index[ " << transactionIndexIn << " Data[" << transactionDataIn << "]" << endl;
    
    powNonce = -1;
    
    transactionTime = time(nullptr);
    
    transactionHash = _CalculateHash();
}

/*
 * Getters & Setters
 */
string Block::GetTransactionHash()
{
    return transactionHash;
}

void Block::SetTransactionPrevHash(const string &transactionPrevHashIn)
{
    transactionPrevHash = transactionPrevHashIn;
}



/*
 * "Proof of work" algorithm to generate a hash that start with nDifficulty number of zeros
 */
void Block::GenerateValidHash(uint32_t nDifficulty)
{
    time_t validationStartTime;
    
    time_t validationEndTime;
    
    time(&validationStartTime);
    
    char buffer [80];
    
    struct tm *tmp ;
    
    string strStartTime, strEndTime, strDiffTime;
    
    char cstr[nDifficulty + 1];
    
    for (uint32_t i=0; i< nDifficulty; ++i)
    {
        cstr[i] ='0';
    }
    
    cstr[nDifficulty] = '\0';
    
    string str(cstr);
    
    do
    {
        powNonce++;
        
        transactionHash = _CalculateHash();
    }
    while (transactionHash.substr(0, nDifficulty) != str);
    
    time(&validationEndTime);
    
    double diff_t = difftime(validationEndTime, validationStartTime);
    
    // Pretty Print StartTime
    tmp = localtime(&validationStartTime);
    
    strftime(buffer,80,"Now it's %I:%M%p.",tmp);
    
    puts (buffer);
    
    strStartTime = buffer;

    
    // Pretty Print EndTime
    tmp = localtime(&validationEndTime);
    
    strftime(buffer,80,"Now it's %I:%M%:%S%p.",tmp);
    
    puts (buffer);
    
    strEndTime = buffer;

    
    cout << "Block mined: " << transactionHash << " Start Time: ["<<strStartTime<<" ] EndTime: ["<<strEndTime<<"] Total Time to mine ="<<diff_t <<endl;
}

/*
 * Calculate hash function
 */
inline string Block::_CalculateHash() const
{
    stringstream ss;

    ss << transactionIndex << transactionTime << transactionData << powNonce << transactionPrevHash;
    
    return sha256(ss.str());
}
