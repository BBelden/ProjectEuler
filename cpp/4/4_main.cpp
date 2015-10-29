//
//  main.cpp
//  4
//
//  Created by Belden on 10/17/13.
//  Copyright (c) 2013 bpb. All rights reserved.
//

/*
 A palindromic number reads the same both ways.
 The largest palindrome made from the product of two 2-digit numbers is 9009 = 91*99.
 
 Find the largest palindrome made from the product of two 3-digit numbers.
 
 Answer:
 906609 is a palindrome
 the factors are: 993 and 913
 */

#include <iostream>
#include <sstream>
#include <string>

using namespace std;


bool isPalindrome(int inNum){
    bool palindrome = false;
    string result;
    ostringstream convert;
    convert << inNum;
    result = convert.str();
    //cout << "string version: " << result << endl;
    
    if (result.at(0) == result.at(result.length()-1))
        if (result.at(1) == result.at(result.length()-2))
            if (result.at(2) == result.at(result.length()-3))
                if (result.at(3) == result.at(result.length()-4))
                    palindrome = true;
    return palindrome;
}

int factorIt (int num){
    int minFactor = 100;
    int maxFactor = 999;
    int factor = -1;
    for (int i = minFactor; i < maxFactor; i++){
        if (num%i == 0)
            factor = i;
    }
    
    
    
    return factor;
}

int main(int argc, const char * argv[])
{

    int min = 10000;
    int max = 998001;
    int factor;
    
    // find all palindromic numbers from largest to smallest within range min:max
    
    for (int i = max; i > min; i--)
    {
        //cout << "number version: " << i << endl;
        if (isPalindrome(i))
        {
            //cout << i << " is a palindrome\n";
            factor = factorIt(i);
            if (factor != -1)
                //cout << "the factor is: " << factor << endl;
                if (i % factor == 0 && factor != -1 && (i/factor < 1000)){
                    cout << i << " is a palindrome\n";
                    cout << "the factors are: " << factor;
                    cout << " and " << i/factor << endl;
                    break;
                }
            
        }
            
    }

    
    return 0;
}

