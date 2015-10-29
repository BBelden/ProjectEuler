//
//  main.cpp
//  20
//
//  Created by Belden on 12/12/13.
//  Copyright (c) 2013 bpb. All rights reserved.
//

/*
 n! means n × (n − 1) × ... × 3 × 2 × 1
 
 For example, 10! = 10 × 9 × ... × 3 × 2 × 1 = 3628800,
 and the sum of the digits in the number 10! is 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27.
 
 Find the sum of the digits in the number 100!
 answer: 648
 */

#include <iostream>

int main(int argc, const char * argv[])
{
    const int SIZE=175;
    int n = 0;
    int array[SIZE]={0};
    array[SIZE-1]=1;
    std::cout << "Enter a number to !\n";
    std::cin >> n;
    
    for(int i=2; i <= n; i++)
    {
        for (int j=0; j<SIZE; j++)
        {
            int temp1,temp2 = 0;
            temp1 = array[j]*i;
            if (temp1 == 0)
                continue;
            array[j] = temp1;
            if (array[j] > 9)
            {
                array[j-1] = array[j-1] + ((temp1-(temp1%10))/10);
                array[j] = temp1%10;
            }
            if (array[j-1] >9)
            {
                array[j-2]= array[j-2] + ((array[j-1]-(array[j-1]%10))/10);
                array[j-1] = array[j-1]%10;
            }
            if (array[j-2] >9)
            {
                array[j-3] = array[j-3] + ((array[j-2]-(array[j-2]%10))/10);
                array[j-2] = array[j-2]%10;
            }
            if (array[j-3] >9)
            {
                array[j-4] = array[j-4] + ((array[j-3]-(array[j-3]%10))/10);
                array[j-3] = array[j-3]%10;
            }
            if (array[j-4] >9)
            {
                array[j-5] = array[j-5] + ((array[j-4]-(array[j-4]%10))/10);
                array[j-4] = array[j-4]%10;
            }
        }
    }

    int sum=0;
    for (int i=0; i<SIZE;i++)
        sum+=array[i];
    std::cout << "The sum of the digits in " <<n<< "! is: " << sum << std::endl << std::endl;
    
    return 0;
}

