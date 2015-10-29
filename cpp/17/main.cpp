//
//  main.cpp
//  17
//
//  Created by Belden on 10/21/13.
//  Copyright (c) 2013 bpb. All rights reserved.
//

/*
 If the numbers 1 to 5 are written out in words: one, two, three, four, five, then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.
 
 If all the numbers from 1 to 1000 (one thousand) inclusive were written out in words, how many letters would be used?
 
 
 NOTE: Do not count spaces or hyphens. For example, 342 (three hundred and forty-two) contains 23 letters and 115 (one hundred and fifteen) contains 20 letters. The use of "and" when writing out numbers is in compliance with British usage.
 
 Answer: 21124
 */

#include <iostream>

int main(int argc, const char * argv[])
{

    int sum=0;
    for (int i = 1; i<=1000; i++)
    {
        int ones=0, tens=0, hunds=0, thous=0;
        if (i >= 1000)
            thous = i/1000;
        if ((i-(thous*1000)) >= 100)
            hunds = (i-(thous*1000))/100;
        if ((i-(thous*1000)-(hunds*100)) >= 20)
            tens = (i-(thous*1000)-(hunds*100))/10;
        if ((i-(thous*1000)-(hunds*100)-(tens*10)) > 0)
            ones = (i-(thous*1000)-(hunds*100)-(tens*10));
            
        switch (ones){
            case 1 : sum+=3; break; // one
            case 2 : sum+=3; break; // two
            case 3 : sum+=5; break; // three
            case 4 : sum+=4; break; // four
            case 5 : sum+=4; break; // five
            case 6 : sum+=3; break; // six
            case 7 : sum+=5; break; // seven
            case 8 : sum+=5; break; // eight
            case 9 : sum+=4; break; // nine
            case 10 : sum+=3; break; // ten
            case 11 : sum+=6; break; // eleven
            case 12 : sum+=6; break; // twelve
            case 13 : sum+=8; break; // thirteen
            case 14 : sum+=8; break; // fourteen
            case 15 : sum+=7; break; // fifteen
            case 16 : sum+=7; break; // sixteen
            case 17 : sum+=9; break; // seventeen
            case 18 : sum+=8; break; // eighteen
            case 19 : sum+=8; break; // nineteen
            default : break;
       };
        switch (tens){
            case 2 : sum+=6; break; // twenty
            case 3 : sum+=6; break; // thirty
            case 4 : sum+=5; break; // forty
            case 5 : sum+=5; break; // fifty
            case 6 : sum+=5; break; // sixty
            case 7 : sum+=7; break; // seventy
            case 8 : sum+=6; break; // eighty
            case 9 : sum+=6; break; // ninety
            default : break;
       };
        switch (hunds){
            case 1 : sum+=10; break; // one hundred
            case 2 : sum+=10; break; // two hundred
            case 3 : sum+=12; break; // three hundred
            case 4 : sum+=11; break; // four hundred
            case 5 : sum+=11; break; // five hundred
            case 6 : sum+=10; break; // six hundred
            case 7 : sum+=12; break; // seven hundred
            case 8 : sum+=12; break; // eight hundred
            case 9 : sum+=11; break; // nine hundred
            default : break;
       };
        switch (thous){
            case 1 : sum+=11; break; // one thousand
            default : break;
        };
        if (hunds > 0 && i%100 != 0)
            sum+=3;  // and
    }
    
    std::cout << sum << std::endl;
    
    return 0;
}

