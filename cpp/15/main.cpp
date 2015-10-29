//
//  main.cpp
//  15
//
//  Created by Belden on 10/21/13.
//  Copyright (c) 2013 bpb. All rights reserved.
//

/*
 
 Starting in the top left corner of a 2x2 grid, and only being able to move to the right and down,
 there are exactly 6 routes to the bottom right corner.
 
 How many such routes are there through a 20x20 grid?
 
 Answer: 137846528820 paths
  2 =            2
  3 =            6
  4 =           20
  5 =           70
  6 =          252
  7 =          924
  8 =         3432
  9 =        12870
 10 =        48620
 11 =       184756
 12 =       705432
 13 =      2704156
 14 =     10400600
 15 =     40116600
 16 =    155117520
 17 =    601080390
 18 =   2333606220
 19 =   9075135300
 20 =  35345263800
 21 = 137846528820

 */

#include <iostream>
#include <iomanip>

int main (int argc, const char * argv[])
{
    const int SIZE = 21;
    long pascal[SIZE*2][SIZE*2]={0};
    float sum=0;
    for (int s=0; s<(100000); s++){
        clock_t start=0, end=0;
        start = clock();
        pascal[1][1]=1;
        for (int i=2; i<(SIZE*2); i++)
            for (int j=1; j<(SIZE*2); j++)
                pascal[i][j] = pascal[i-1][j] + pascal[i-1][j-1];
        end = clock();
        sum += (end - start)/double(CLOCKS_PER_SEC);
    }
    std::cout <<std::fixed << std::setprecision(10) << "There are " << pascal[(SIZE*2)-1][SIZE] << " paths in a " << SIZE-1 << " by " << SIZE-1 << " square." << std::endl << (sum/100000) << " seconds." << std::endl;
    return 0;
}

/*
 const int SIZE = 20;
 void move (int row, int col, long& count)
 {
 if (row == SIZE-1 && col == SIZE-1){
 count++;
 return;
 }
 if (row+1 != SIZE)
 move (row+1, col, count);
 if (col+1 !=SIZE)
 move(row, col+1, count);
 }
 
 int main(int argc, const char * argv[])
 {
 int row=0, col=0;
 long count =0;
 move(row, col, count);
 std::cout << count << std::endl;
 return 0;
 }
 */
