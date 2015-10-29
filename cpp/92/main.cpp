//
//  main.cpp
//  92
//
//  Created by Belden on 12/14/13.
//  Copyright (c) 2013 bpb. All rights reserved.
//

/*
 A number chain is created by continuously adding the square of the digits in a number to form a new number until it has been seen before.
 
 For example,
 
 44 → 32 → 13 → 10 → 1 → 1
 85 → 89 → 145 → 42 → 20 → 4 → 16 → 37 → 58 → 89
 
 Therefore any chain that arrives at 1 or 89 will become stuck in an endless loop. What is most amazing is that EVERY starting number will eventually arrive at 1 or 89.
 
 How many starting numbers below ten million will arrive at 89?
 
 answer:
 8581146
 */

#include <iostream>

int main(int argc, const char * argv[])
{
    const int MAX=10000000, SIZE=10;
    long int nums[SIZE]={0}, count=0, temp=0, sum=0;
    for (long int i = 1; i<MAX; i++){
        temp=i;
        while (temp != 1 && temp != 89){
            for (int a=0; a< SIZE; a++)
                nums[a]=0;
            sum=0;
            if (temp > 999999){
                nums[SIZE-7] = ((temp - (temp%1000000))/1000000);
                temp = temp%1000000;
            }
            if (temp > 99999){
                nums[SIZE-6] = ((temp - (temp%100000))/100000);
                temp = temp%100000;
            }
            if (temp > 9999){
                nums[SIZE-5] = ((temp - (temp%10000))/10000);
                temp = temp%10000;
            }
            if (temp > 999){
                nums[SIZE-4] = ((temp - (temp%1000))/1000);
                temp = temp%1000;
            }
            if (temp > 99){
                nums[SIZE-3] = ((temp - (temp%100))/100);
                temp = temp%100;
            }
            if (temp > 9){
                nums[SIZE-2] = ((temp - (temp%10))/10);
                temp = temp%10;
            }
            nums[SIZE-1]=temp;
            for (int b=0; b<SIZE; b++)
                sum = sum + (nums[b] * nums[b]);
            temp = sum;
        }
        if (temp == 89)
            count++;
    }
    std::cout << count << std::endl;
    return 0;
}

