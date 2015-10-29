//
//  main.cpp
//  14
//
//  Created by Belden on 10/21/13.
//  Copyright (c) 2013 bpb. All rights reserved.
//

/*

 The following iterative sequence is defined for the set of positive integers:
 
 n --> n/2 (n is even)
 n --> 3n + 1 (n is odd)
 
 Using the rule above and starting with 13, we generate the following sequence:
 
 13 --> 40 --> 20 --> 10 --> 5 --> 16 --> 8 --> 4 --> 2 --> 1
 It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. 
 Although it has not been proved yet (Collatz Problem), it is thought that all starting 
 numbers finish at 1.
 
 Which starting number, under one million, produces the longest chain?
 
 Answer: 837799
 
 NOTE: Once the chain starts the terms are allowed to go above one million.

*/

#include <iostream>

int main(int argc, const char * argv[])
{
    long n=0, start=0, count=0, longest=0, longestCount=0;
    const long MAX = 1000000;
    
    for (long i = 1; i<MAX; i++)
    {
        start = i;
        n = i;
        count = 1;
        while(n>1)
        {
            if (n%2 == 0)
                n = n/2;
            else
                n = (3*n)+1;
            count++;
        }
        if (count > longestCount)
        {
            longestCount = count;
            longest = start;
        }
    }
    
    std::cout << longest <<std::endl;
    
    return 0;
}

