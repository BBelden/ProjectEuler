/*
 
 The number, 197, is called a circular prime because all rotations of the digits: 197, 971, and 719, are themselves prime.
 
 There are thirteen such primes below 100: 2, 3, 5, 7, 11, 13, 17, 31, 37, 71, 73, 79, and 97.
 
 How many circular primes are there below one million?
 
 answer: 55         took 3mins to run though
 
 */

#include <iostream>

bool isPrime (int inNum)
{
    if (inNum%2 == 0 || inNum%3 == 0 || inNum%5 == 0 || inNum%7==0)
        return false;
    for (int i=11; i<inNum; i++){
        if (inNum%i == 0)
            return false;
    }
    return true;
}

bool isCircular (int inNum)
{
    int ones,tens,hunds,thous,tenThous,hundThous,newNum;
    if (inNum < 10)
        return true;
    
    if (inNum < 100){
        tens = inNum/10;
        ones = inNum - tens*10;
        newNum = ones*10 + tens;
        if (isPrime(newNum))
            return true;
    }
    
    if (inNum < 1000){
        hunds = inNum/100;
        tens = (inNum - hunds*100)/10;
        ones = (inNum - hunds*100 - tens*10);
        newNum = tens*100 + ones*10 + hunds;
        if (isPrime(newNum)){
            newNum = ones*100 + hunds*10 + tens;
            if (isPrime(newNum))
                return true;
        }
    }
    
    if (inNum < 10000){
        thous = inNum/1000;
        hunds = (inNum - thous*1000)/100;
        tens = (inNum - thous*1000 - hunds*100)/10;
        ones = (inNum - thous *1000 - hunds*100 - tens*10);
        newNum = hunds*1000 + tens*100 + ones*10 + thous;
        if (isPrime(newNum)){
            newNum = tens*1000 + ones*100 + thous*10 + hunds;
            if (isPrime(newNum)){
                newNum = ones*1000 + thous*100 + hunds*10 + tens;
                if (isPrime(newNum))
                    return true;
            }
        }
    }
    
    if (inNum < 100000){
        tenThous = inNum/10000;
        thous = (inNum - tenThous*10000)/1000;
        hunds = (inNum - tenThous*10000 - thous*1000)/100;
        tens = (inNum - tenThous*10000 - thous*1000 - hunds*100)/10;
        ones = (inNum - tenThous*10000 - thous *1000 - hunds*100 - tens*10);
        newNum = thous*10000 + hunds*1000 + tens*100 + ones*10 + tenThous;
        if (isPrime(newNum)){
            newNum = hunds*10000 + tens*1000 + ones*100 + tenThous*10 + thous;
            if (isPrime(newNum)){
                newNum = tens*10000 + ones*1000 + tenThous*100 + thous*10 + hunds;
                if (isPrime(newNum)){
                    newNum = ones*10000 + tenThous*1000 + thous*100 + hunds*10 + tens;
                    if (isPrime(newNum))
                        return true;
                }
            }
        }
    }
    
    if (inNum < 1000000){
        hundThous = inNum/100000;
        tenThous = (inNum - hundThous*100000)/10000;
        thous = (inNum - hundThous*100000 - tenThous*10000)/1000;
        hunds = (inNum - hundThous*100000 - tenThous*10000 - thous*1000)/100;
        tens = (inNum - hundThous*100000 - tenThous*10000 - thous*1000 - hunds*100)/10;
        ones = (inNum - hundThous*100000 - tenThous*10000 - thous *1000 - hunds*100 - tens*10);
        newNum = tenThous*100000 + thous*10000 + hunds*1000 + tens*100 + ones*10 + hundThous;
        if (isPrime(newNum)){
            newNum = thous*100000 + hunds*10000 + tens*1000 + ones*100 + hundThous*10 + tenThous;
            if (isPrime(newNum)){
                newNum = hunds*100000 + tens*10000 + ones*1000 + hundThous*100 + tenThous*10 + thous;
                if (isPrime(newNum)){
                    newNum = tens*100000 + ones*10000 + hundThous*1000 + tenThous*100 + thous*10 + hunds;
                    if (isPrime(newNum)){
                        newNum = ones*100000 + hundThous*10000 + tenThous*1000 + thous*100 + hunds*10 + tens;
                        if (isPrime(newNum))
                            return true;
                    }
                }
            }
        }
    }
    
    return false;
}

int main(int argc, const char * argv[])
{
    int index=0;
    const int SIZE=5000;
    int cPrimes[SIZE]={0};
    
    for (int i=2; i<1000000; i++){
        if (isPrime(i) && isCircular(i)){
            cPrimes[index]=i;
            index++;
        }
    }
    
    std::cout << "There are " << index << " circular primes under 1,000,000.\n";
    
    return 0;
}

