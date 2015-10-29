//
//  main.cpp
//  16
//
//  Created by Belden on 10/21/13.
//  Copyright (c) 2013 bpb. All rights reserved.
//

/*
 
 2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.
 
 What is the sum of the digits of the number 2^1000?
 
 Answer: 1366
 
 */

#include <iostream>
int main(int argc, const char * argv[])
{
    const int MAX_SIZE = 302, EXPONENT = 1000, BASE = 2;
    int carry = 0, sum = 0;
    int twosArray[MAX_SIZE] = {0};
    twosArray[0] = 1;
    for (int i = 1; i <= EXPONENT; i++){
        for (int j=0; j<MAX_SIZE; j++){
            twosArray[j] = (twosArray[j] * BASE) + carry;
            carry = 0;
            if (twosArray[j] > 9){
                carry = twosArray[j] / 10;
                twosArray[j] = twosArray[j] - (carry * 10);
            }  // end if
        }  // end for
    }  // end for
    std::cout << BASE << "^" << EXPONENT << " is: " << std::endl;
    for (int i = MAX_SIZE-1; i>=0; i--){
        std::cout << twosArray[i];
        sum += twosArray[i];
    }  // end for
    std::cout << std::endl << std::endl << "The sum of the digits is: " << std::endl << sum << std::endl;
    return 0;
}  // end main

