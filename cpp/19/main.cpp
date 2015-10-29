//
//  main.cpp
//  19
//
//  Created by Belden on 12/16/13.
//  Copyright (c) 2013 bpb. All rights reserved.
//

/*
 
 You are given the following information, but you may prefer to do some research for yourself.
 
 1 Jan 1900 was a Monday.
 Thirty days has September, April, June and November.
 All the rest have thirty-one,
 Saving February alone,
 Which has twenty-eight, rain or shine.
 And on leap years, twenty-nine.
 A leap year occurs on any year evenly divisible by 4, but not on a century unless it is divisible by 400.
 How many Sundays fell on the first of the month during the twentieth century (1 Jan 1901 to 31 Dec 2000)?
 
 answer: 171
 
 */

#include <iostream>

int main(int argc, const char * argv[])
{
    const int IS_LEAP = 366, NOT_LEAP = 365;
    enum Days {Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday};
    Days day = Tuesday;
    int year = 1901;
    int total = 0;
    
    while (year != 2001){
        int date = 1;
        
        if (year%4 == 0){
            for (; date <= IS_LEAP; date++){
                if (day == Sunday &&
                    (date == 1 || date == 32 || date == 61 || date == 92 ||
                     date == 122 || date == 153 || date == 183 || date == 214 ||
                     date == 245 || date == 275 || date == 306 || date == 336))
                    total++;
                if (day == Saturday)
                    day = Sunday;
                else
                    day++;
            } // end for
        } // end if
        
        if (year%4 != 0){
            for (; date <= NOT_LEAP; date++){
                if (day == Sunday &&
                    (date == 1 || date == 32 || date == 60 || date == 91 ||
                     date == 121 || date == 152 || date == 182 || date == 213 ||
                     date == 244 || date == 274 || date == 305 || date == 335))
                    total++;
                if (day == Saturday)
                    day = Sunday;
                else
                    day++;
            } // end for
        } // end if
        
        year++;
    } // end while
    
    std::cout << total << std::endl;
    
    return 0;
} // end main
