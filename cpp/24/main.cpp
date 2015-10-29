/*
 
 A permutation is an ordered arrangement of objects. For example, 3124 is one possible permutation of the digits 1, 2, 3 and 4. If all of the permutations are listed numerically or alphabetically, we call it lexicographic order. The lexicographic permutations of 0, 1 and 2 are:
 
 012   021   102   120   201   210
 
 What is the millionth lexicographic permutation of the digits 0, 1, 2, 3, 4, 5, 6, 7, 8 and 9?
 
 answer: 2783915460
 
 */

#include <iostream>
#include <algorithm>
//bool isValid (long);
int main(int argc, const char * argv[])
{
    char ca[]="0123456789";
    for(int i=1;i<1000000;i++)
        std::next_permutation(ca,ca+10);
    std::cout << ca << std::endl;
    /*
    const long LOW=123456789, HI=9876543210;
    int count=0;
    for (long i=LOW; i<=HI; i++){
        if (isValid(i)){
            count++;
            if (count == 1000000){
                std::cout << i << std::endl;
                goto end;
            }
        }
    }
end:
    */
    return 0;
}

/*
bool isValid (long num)
{
    long testArray[10]={0};
    long one=0,ten=0,hund=0,thou=0,tThou=0,hThou=0,mil=0,tMil=0,hMil=0,bil=0;
    bil = num/1000000000;
    hMil = (num - bil*1000000000)/100000000;
    tMil = (num - bil*1000000000 - hMil*100000000)/10000000;
    mil = (num - bil*1000000000 - hMil*100000000 - tMil*10000000)/1000000;
    hThou = (num - bil*1000000000 - hMil*100000000 - tMil*10000000 - mil*1000000)/100000;
    tThou = (num - bil*1000000000 - hMil*100000000 - tMil*10000000 - mil*1000000 - hThou*100000)/10000;
    thou = (num - bil*1000000000 - hMil*100000000 - tMil*10000000 - mil*1000000 - hThou*100000 - tThou*10000)/1000;
    hund = (num - bil*1000000000 - hMil*100000000 - tMil*10000000 - mil*1000000 - hThou*100000 - tThou*10000 - thou*1000)/100;
    ten = (num - bil*1000000000 - hMil*100000000 - tMil*10000000 - mil*1000000 - hThou*100000 - tThou*10000 - thou*1000 - hund*100)/10;
    one = num - bil*1000000000 - hMil*100000000 - tMil*10000000 - mil*1000000 - hThou*100000 - tThou*10000 - thou*1000 - hund*100 - ten*10;
    
    testArray[bil]++;
    testArray[hMil]++;
    testArray[tMil]++;
    testArray[mil]++;
    testArray[hThou]++;
    testArray[tThou]++;
    testArray[thou]++;
    testArray[hund]++;
    testArray[ten]++;
    testArray[one]++;
    
    for (int i=0; i<10; i++)
        if (testArray[i]>1)
            return false;
    return true;
}
*/