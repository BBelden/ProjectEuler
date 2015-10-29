//
//  main.cpp
//  10
//
//  Created by Belden on 10/17/13.
//  Copyright (c) 2013 bpb. All rights reserved.
//

/*
 The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
 
 Find the sum of all the primes below two million.
 
 Answer: 142913828922
 
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
    long sum = 0;
    int count = 0;
    
    for (long i = 2; i < 2000000; i++)
        if (isPrime(i))
        {
            sum += i;
            count++;
            //cout << "count: " << count<<"\ti: " << i << "\tsum: " << sum << endl;
        }
    
    cout << sum << endl;

    return 0;
}

