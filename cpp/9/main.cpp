//
//  main.cpp
//  9
//
//  Created by Belden on 10/17/13.
//  Copyright (c) 2013 bpb. All rights reserved.
//

/*
 
 A Pythagorean triplet is a set of three natural numbers, a  b  c, for which,
 a^2 + b^2 = c^2
 
 For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.
 
 There exists exactly one Pythagorean triplet for which a + b + c = 1000.
 Find the product abc.
 
 Answer: 200 * 375 * 425 = 31875000
 */

#include <iostream>

using namespace std;

int main(int argc, const char * argv[])
{
    int a, b, c;
    int sumSquares;
    
    for (int i = 1; i < 1000; i++)
    {
        for (int j = 1; j < 1000; j++)
        {
            for (int k = 1; k < 1000; k++)
            {
                //cout << i << " + " << j << " + " << k << " = " << i+j+k << endl;
                if (i + j + k == 1000)
                {
                    sumSquares = (i*i)+(j*j);
                    if(sumSquares == (k*k))
                    {
                        a = i;
                        b = j;
                        c = k;
                        goto finish;
                    }
                }
            }
        }
    }
finish:
    cout << a << " * " << b << " * " << c << " = " << a*b*c << endl;
    
    return 0;
}

