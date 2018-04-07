//
//  main.cpp
//  Blockchain
//
//  Created by William Williams on 3/22/18.
//  Copyright © 2018 DSC. All rights reserved.
//

#include <iostream>
#include <sstream>
#include "Blockchain.h"

int main(int argc, const char * argv[])
{
    static const int number_of_blocks = 50;
    
    Blockchain bChain = Blockchain();
    
    time_t _mStartTime, _mEndTime;
    
    char buffer [80];
    
    struct tm *tmp ;
    
    string strStartTime, strEndTime, strDiffTime;
    
    std::ostringstream oss;
    
    time(&_mStartTime);
    
    // Pretty Print StartTime
    tmp = localtime( &_mStartTime);
    
    strftime(buffer,80,"Now it's %I:%M%p.",tmp);
    
    puts (buffer);
    
    strStartTime = buffer;
    
    // Loop to create blocks
    for (uint32_t i=0; i< number_of_blocks; ++i)
    {
        cout << "Mining block " << i << " ..." << endl;
        
        oss << "Block " << i<<" Data";
        
        bChain.AddBlock(Block(i,oss.str()));
        
        oss.str("");
    }
    
    time(&_mEndTime);
    
    // Pretty Print EndTime
    tmp = localtime( &_mEndTime);
    
    strftime(buffer,80,"Now it's %I:%M%p.",tmp);
    
    puts (buffer);
    
    strEndTime = buffer;
    
    double diff_t = difftime(_mEndTime, _mStartTime);
    
    cout << "Process Start Time: ["<<strStartTime<<" ] Process EndTime: ["<<strEndTime<<"] Total Process Time to mine ="<<diff_t <<endl;
    
    return 0;
}
