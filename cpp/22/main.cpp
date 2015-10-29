//
//  main.cpp
//  22
//
//  Created by Belden on 12/20/13.
//  Copyright (c) 2013 Double Bee Designs. All rights reserved.
//

/*
 
 Using names.txt (right click and 'Save Link/Target As...'), a 46K text file containing over five-thousand first names, begin by sorting it into alphabetical order. Then working out the alphabetical value for each name, multiply this value by its alphabetical position in the list to obtain a name score.
 
 For example, when the list is sorted into alphabetical order, COLIN, which is worth 3 + 15 + 12 + 9 + 14 = 53, is the 938th name in the list. So, COLIN would obtain a score of 938 × 53 = 49714.
 
 What is the total of all the name scores in the file?
 answer: 871198282
 
 */

#include <iostream>
#include <fstream>
#include <string>
#include <array>
#include <algorithm>

int main(int argc, const char * argv[])
{
    const int SIZE = 5164, LTRS=27;
    std::ifstream inNames;
    inNames.open("/Users/migration/Desktop/xCode/Project Euler/22/22/names.txt");
    std::array<std::string, SIZE> names;
    char c;
    std::string temp;
    
    inNames.ignore(50,'"');
    int itr = 1;
    
    while (inNames){
        inNames >> c;
        while (c != '"'){
            temp = temp + c;
            inNames >> c;
        }
        names[itr] = temp;
        itr++;
        temp.clear();
        inNames.ignore(50,'"');
    }
    std::sort(names.begin(), names.end());
    char letters[LTRS]={' ','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    std::string work;
    int nameTotal=0, runningTotal=0;
    for (int i=1; i<SIZE; i++){
        nameTotal=0;
        work = names[i];
        for (int j=0; j<work.length(); j++){
            for (int k=0; k<LTRS; k++){
                if (work[j]==letters[k]){
                    nameTotal = nameTotal + k;
                    break;
                }
            }
        }
        runningTotal = runningTotal + (i * nameTotal);
    }
    std::cout << runningTotal << std::endl;
    return 0;
}

