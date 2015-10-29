//
//  main.cpp
//  7
//
//  Created by Belden on 10/17/13.
//  Copyright (c) 2013 bpb. All rights reserved.
//


/*
 By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see 
 that the 6th prime is 13.
 
 What is the 10001st prime number?
 
 Answer: 104743
 
 */

#include <iostream>

using namespace std;

bool isPrime (long num)
{
    for (long i = 2; i < num; i++)
        if (num % i == 0)
            return false;
    return true;
}

int main(int argc, const char * argv[])
{
    const long MAX = 999999999999;
    int counter = 0;
    for (long i = 2; i < MAX; i++)
    {
        if (isPrime(i))
            counter++;
        if (counter == 10001)
        {
            cout << i << endl;
            goto finish;
        }
        
    }
    
finish:
    
    return 0;
}

