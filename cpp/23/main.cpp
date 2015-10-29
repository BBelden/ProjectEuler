/*
 
 A perfect number is a number for which the sum of its proper divisors is exactly equal to the number. For example, the sum of the proper divisors of 28 would be 1 + 2 + 4 + 7 + 14 = 28, which means that 28 is a perfect number.
 
 A number n is called deficient if the sum of its proper divisors is less than n and it is called abundant if this sum exceeds n.
 
 As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16, the smallest number that can be written as the sum of two abundant numbers is 24. By mathematical analysis, it can be shown that all integers greater than 28123 can be written as the sum of two abundant numbers. However, this upper limit cannot be reduced any further by analysis even though it is known that the greatest number that cannot be expressed as the sum of two abundant numbers is less than this limit.
 
 Find the sum of all the positive integers which cannot be written as the sum of two abundant numbers.
 
 answer: 4179871
 
 */

#include <iostream>
#include <iomanip>

int main(int argc, const char * argv[])
{
    const int SIZE=28123;
    int abundant[SIZE]={0}, notAbundant[SIZE]={0}, abundantSums[SIZE]={0};
    std::cout << std::fixed << std::setprecision(6);
    
    // identify whether an integer is abundant or not and place it in the appropriate array at its index
    clock_t start=0, end=0;
    start = clock();
    for (int i=1; i<SIZE; i++){
        int sum=0;
        for (int j=1; j<i; j++)
            if (i%j==0)
                sum+=j;
        if (sum<=i)
            notAbundant[i]=i;
        else if (sum > i)
            abundant[i]=i;
    }
    end = clock();
    std::cout << (end - start)/double(CLOCKS_PER_SEC) << std::endl;
    
    start = end = 0;
    start = clock();
    // sum up all abundant numbers and put them in an array at the index of the sum
    for (int i=1; i<SIZE; i++){
        for (int j=i; j<SIZE; j++){
            int temp=0;
            if ((abundant[i] !=0) && (abundant[j] !=0))
                temp = abundant[i] + abundant[j];
            if (temp <= SIZE)
                abundantSums[temp]=temp;
        }
    }
    end = clock();
    std::cout << (end - start)/double(CLOCKS_PER_SEC) << std::endl;
    
    start = end = 0;
    start = clock();
    // sum up all numbers that arent abundant sums
    int sum=0;
    for (int i=0; i<SIZE; i++)
        if (abundantSums[i]==0)
            sum+=i;
    end = clock();
    std::cout << (end - start)/double(CLOCKS_PER_SEC) << std::endl;
    
    std::cout << sum << std::endl;
    return 0;
}

