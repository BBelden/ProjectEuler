/*
 Starting with the number 1 and moving to the right in a clockwise direction a 5 by 5 spiral is formed as follows:
 
 21 22 23 24 25
 20  7  8  9 10
 19  6  1  2 11
 18  5  4  3 12
 17 16 15 14 13
 
 It can be verified that the sum of the numbers on the diagonals is 101.
 What is the sum of the numbers on the diagonals in a 1001 by 1001 spiral formed in the same way?
 
 answer: 669171001
 
 */

#include <iostream>

int main(int argc, const char * argv[])
{
    const int SIZE = 1001;
    int spiral[SIZE][SIZE]={0};
    int row=SIZE/2, col=SIZE/2, val=1, sum=0;
    
    // populate the array starting at the center
    spiral[row][col] = val;
    // first move right
    col++;
    val++;
    spiral[row][col] = val;
    
    // while not full, spiral clockwise
    while (spiral[0][SIZE-1] == 0){
        // while left is blocked, move down and increment by one
        while (spiral[row][col-1] != 0){
            row++;
            val++;
            spiral[row][col] = val;
        } // end while
        
       // while up is blocked, move left and increment by one
        while (spiral[row-1][col] != 0){
            col--;
            val++;
            spiral[row][col] = val;
        } // end while

        // while right is blocked, move up, increment by one
        while (spiral[row][col+1] != 0){
            row--;
            val++;
            spiral[row][col] = val;
        } // end while

        // while down is blocked, move right, increment by one
        while (spiral[row+1][col] != 0){
            col++;
            // tests for out of bounds ... is there a better way to do this?
            if (col >= SIZE)
                break;
            val++;
            spiral[row][col] = val;
        } // end while
    } // end while
    
    // sum diagonals
    row=col=0;
    for (int i=0; i<SIZE; i++){
        // start in upper left, sum to lower right
        sum+=spiral[row][col];
        row++;
        col++;
    } // end for
    row=0;
    col=SIZE-1;
    for (int i=0; i<SIZE; i++)
    {
        // start in upper right, sum to lower left
        sum+=spiral[row][col];
        row++;
        col--;
    } // end for
    // subtract duplicated center square
    sum-=spiral[SIZE/2][SIZE/2];
    // output sum
    std::cout << "The sum of the diagonals in a " << SIZE << " by " << SIZE << " spiral matrix is: " << sum << std::endl;
    
    return 0;
}

