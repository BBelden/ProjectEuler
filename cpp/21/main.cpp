/*
 
 Let d(n) be defined as the sum of proper divisors of n (numbers less than n which divide evenly into n).
 If d(a) = b and d(b) = a, where a ≠ b, then a and b are an amicable pair and each of a and b are called amicable numbers.
 
 For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 and 110; therefore d(220) = 284. The proper divisors of 284 are 1, 2, 4, 71 and 142; so d(284) = 220.
 
 Evaluate the sum of all the amicable numbers under 10000.
 
 answer: 31626
 
 */

#include <iostream>

int main(int argc, const char * argv[])
{
    const int SIZE=10000;
    int amicable[SIZE], amicableSum=0;
    for (int i=0; i<SIZE; i++)
        amicable[i]=i;
    // check each number (a) for amicability
    for (int a=1; a<SIZE; a++){
        int divSumA=0, divSumB=0;
        // find all divisors of (a)
        for (int i=1; i<a; i++)
            // sum the divisors (b)
            if (a%i==0)
                divSumA+=i;
        // find divisors of sum (b)
        int b = divSumA;
        for (int i=1; i<b; i++)
            // sum divisors of (b)
            if (b%i==0)
                divSumB+=i;
        // IF sum of divisors of (a) equal (b) AND sum of divisors of (b) equal (a)
        // AND (a) does not equal (b), (a) and (b) are amicable
        // ELSE remove (a) from amicable array
        if (a != divSumB || b != divSumA || a == b)
            amicable[a]=0;
    } // end for
    // sum all amicable numbers
    for (int i=0; i<SIZE; i++)
        amicableSum+=amicable[i];
    std::cout << "The sum of all amicable numbers under 10000 is: " << amicableSum << std::endl;
    return 0;
}

