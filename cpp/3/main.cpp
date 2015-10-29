//
//  main.cpp
//  Euler Fun
//
//  Created by Belden on 10/16/13.
//  Copyright (c) 2013 bpb. All rights reserved.
//


/*
 The prime factors of 13195 are 5, 7, 13 and 29.
 
 What is the largest prime factor of the number 600851475143 ?
 
 Answer:
 6857
 
 */


#include <iostream>
#include <cmath>
#include <string>


using namespace std;

long primeFactor (long num)
{
    long largest_factor = 1;
    long p = 3;
    long div = num;
    
    /* remove any factors of 2 first */
    while (div % 2 == 0) {
        largest_factor = 2;
        div = div/2;
    }
    
    /* now look at odd factors */
    while (div != 1) {
        while (div % p == 0) {
            largest_factor = p;
            div = div/p;
        }
        p = p + 2;
    }
    
    return largest_factor;
}

int main()
{
    long   factor;
    long   max = 100000;
    long   i = 1;
    
    while (i <= max) {
        factor = primeFactor(600851475143);
        i++;
    }
    
    cout << factor << endl;
    return 0;
}


