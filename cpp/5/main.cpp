//
//  main.cpp
//  5
//
//  Created by Belden on 10/17/13.
//  Copyright (c) 2013 bpb. All rights reserved.
//

/*
 
 2520 is the smallest number that can be divided by each of the numbers from 1 to 10 
 without any remainder.
 
 What is the smallest positive number that is evenly divisible by all of the 
 numbers from 1 to 20?
 
 Answer: 232792560
 
 */

#include <iostream>

using namespace std;

int main(int argc, const char * argv[])
{
    unsigned long max = 9999999999999999;
    long answer = 0;
    for (int i = 20; i < max; i = i + 20)
    {
        for (int j = 20; j >= 2; j--)
        {
            if(i%j == 0)
            {
                if (j == 2)
                {
                    answer = i;
                    goto jumpHere;
                }
            }
            else
                break;
        }
    }
    
jumpHere:
    cout << answer << endl;
    return 0;
}

