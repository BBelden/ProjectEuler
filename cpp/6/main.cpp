//
//  main.cpp
//  6
//
//  Created by Belden on 10/17/13.
//  Copyright (c) 2013 bpb. All rights reserved.
//


/*
 
 The sum of the squares of the first ten natural numbers is,
 
 1^2 + 2^2 + ... + 10^2 = 385
 The square of the sum of the first ten natural numbers is,
 
 (1 + 2 + ... + 10)^2 = 55^2 = 3025
 Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025  385 = 2640.
 
 Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.
 
 Answer: 25164150
 
 */
#include <iostream>

using namespace std;

int main(int argc, const char * argv[])
{

    long sumSquare = 0;
    long squareSum = 0;
    
    for (int i = 1; i <= 100; i++)
    {
        sumSquare = sumSquare + (i*i);
    }
    
    for (int i = 1; i <= 100; i++)
    {
        squareSum+= i;
    }
    squareSum = squareSum*squareSum;
    
    cout << squareSum - sumSquare << endl;
    
    return 0;
}

