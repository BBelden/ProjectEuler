/*
 
 An irrational decimal fraction is created by concatenating the positive integers:
 
 0.123456789101112131415161718192021...
 
 It can be seen that the 12th digit of the fractional part is 1.
 
 If dn represents the nth digit of the fractional part, find the value of the following expression.
 
 d1 × d10 × d100 × d1000 × d10000 × d100000 × d1000000
 
 answer: 210
 */

#include <iostream>

int main(int argc, const char * argv[])
{
    const int SIZE = 1001000;
    int array[SIZE]={0};
    int index=9, digit=1, ones=0, tens=0, hunds=0, thous=0, tenthous=0, total=0;
    
    // populate the array
    // begin with the first digits
    for (int i=1; i<=9; i++)
        array[i-1] = i;
    
    while (digit < 10){
        for(int i=0; i<10; i++){
            array[index]=digit;
            index++;
            array[index]=i;
            index++;
        }
        digit++;
    }

    while (digit < 100){
        tens = digit/10;
        ones = digit - tens*10;
        for(int i=0; i<10; i++){
            array[index]=tens;
            index++;
            array[index]=ones;
            index++;
            array[index]=i;
            index++;
        }
        digit++;
    }

    while (digit < 1000){
        hunds = digit/100;
        tens = (digit - (hunds*100))/10;
        ones = (digit - hunds*100 - tens*10);
        for(int i=0; i<10; i++){
            array[index]=hunds;
            index++;
            array[index]=tens;
            index++;
            array[index]=ones;
            index++;
            array[index]=i;
            index++;
        }
        digit++;
    }

    while (digit < 10000){
        thous = digit/1000;
        hunds = (digit - thous*1000)/100;
        tens = (digit - thous*1000 - hunds*100)/10;
        ones = (digit - thous*1000 - hunds*100 - tens*10);
        for(int i=0; i<10; i++){
            array[index]=thous;
            index++;
            array[index]=hunds;
            index++;
            array[index]=tens;
            index++;
            array[index]=ones;
            index++;
            array[index]=i;
            index++;
        }
        digit++;
    }

    while (digit < 100000 && index < 1000000){
        tenthous = digit/10000;
        thous = (digit - tenthous*10000)/1000;
        hunds = (digit - tenthous*10000 - thous*1000)/100;
        tens = (digit - tenthous*10000 - thous*1000 - hunds*100)/10;
        ones = (digit - tenthous*10000 - thous*1000 - hunds*100 - tens*10);
        for(int i=0; i<10; i++){
            array[index]=tenthous;
            index++;
            array[index]=thous;
            index++;
            array[index]=hunds;
            index++;
            array[index]=tens;
            index++;
            array[index]=ones;
            index++;
            array[index]=i;
            index++;
        }
        digit++;
    }
   
    // then do mathgic
    total = array[0] * array[99] * array[999] * array[9999] * array[99999] * array[999999];
    std::cout << "total is: " << total << std::endl;
    return 0;
}

