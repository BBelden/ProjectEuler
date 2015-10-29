//
//  main.cpp
//  80
//
//  Created by Belden on 12/16/13.
//  Copyright (c) 2013 bpb. All rights reserved.
//

/*
 
 In the 5 by 5 matrix below, the minimal path sum from the top left to the bottom right, by only moving to the right and down, is indicated in bold red and is equal to 2427.
 
 
    131	673	234	103	18
    201	96	342	965	150
    630	803	746	422	111
    537	699	497	121	956
    805	732	524	37	331
 
 Find the minimal path sum, in matrix.txt (right click and 'Save Link/Target As...'), a 31K text file containing a 80 by 80 matrix, from the top left to the bottom right by only moving right and down.
 
 answer:
 
 */

#include <iostream>
#include <fstream>

const int SIZE = 80;

int main(int argc, const char * argv[])
{
    int path=0;
    int deesNums[SIZE][SIZE];
    std::ifstream myFile;
    myFile.open("/Users/migration/Desktop/xCode/Project Euler/80/80/numbers.txt");
    
    for (int i=0; i<SIZE; i++)
    {
        for (int j=0; j<SIZE; j++)
            myFile >> deesNums[i][j];
    }
    
    int row=0, col=0;
    path = path + deesNums[row][col];
    
    while (row != SIZE-1 || row != col)
    {
        if (row+1 >= SIZE)
        {
            col++;
            path = path + deesNums[row][col];
            continue;
        }
        
        if (col+1 >= SIZE)
        {
            row++;
            path = path + deesNums[row][col];
            continue;
        }
        
        if (deesNums[row+1][col] < deesNums[row][col+1])
            row++;
        
        else if (deesNums[row][col+1] < deesNums[row+1][col])
            col++;
        
        path = path + deesNums[row][col];
    }
    
    std::cout << path << std::endl;
    return 0;
}
