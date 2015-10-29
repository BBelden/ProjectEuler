//
//  main.cpp
//  11
//
//  Created by Belden on 10/18/13.
//  Copyright (c) 2013 bpb. All rights reserved.
//


/*
 
 In the 2020 grid below, four numbers along a diagonal line have been marked with stars.
 
 08 02 22 97 38 15 00 40 00 75 04 05 07 78 52 12 50 77 91 08
 49 49 99 40 17 81 18 57 60 87 17 40 98 43 69 48 04 56 62 00
 81 49 31 73 55 79 14 29 93 71 40 67 53 88 30 03 49 13 36 65
 52 70 95 23 04 60 11 42 69 24 68 56 01 32 56 71 37 02 36 91
 22 31 16 71 51 67 63 89 41 92 36 54 22 40 40 28 66 33 13 80
 24 47 32 60 99 03 45 02 44 75 33 53 78 36 84 20 35 17 12 50
 32 98 81 28 64 23 67 10*26*38 40 67 59 54 70 66 18 38 64 70
 67 26 20 68 02 62 12 20 95*63*94 39 63 08 40 91 66 49 94 21
 24 55 58 05 66 73 99 26 97 17*78*78 96 83 14 88 34 89 63 72
 21 36 23 09 75 00 76 44 20 45 35*14*00 61 33 97 34 31 33 95
 78 17 53 28 22 75 31 67 15 94 03 80 04 62 16 14 09 53 56 92
 16 39 05 42 96 35 31 47 55 58 88 24 00 17 54 24 36 29 85 57
 86 56 00 48 35 71 89 07 05 44 44 37 44 60 21 58 51 54 17 58
 19 80 81 68 05 94 47 69 28 73 92 13 86 52 17 77 04 89 55 40
 04 52 08 83 97 35 99 16 07 97 57 32 16 26 26 79 33 27 98 66
 88 36 68 87 57 62 20 72 03 46 33 67 46 55 12 32 63 93 53 69
 04 42 16 73 38 25 39 11 24 94 72 18 08 46 29 32 40 62 76 36
 20 69 36 41 72 30 23 88 34 62 99 69 82 67 59 85 74 04 36 16
 20 73 35 29 78 31 90 01 74 31 49 71 48 86 81 16 23 57 05 54
 01 70 54 71 83 51 54 69 16 92 33 48 61 43 52 01 89 19 67 48
 
 The product of these numbers is 26  63  78  14 = 1788696.
 
 What is the greatest product of four adjacent numbers in the same direction (up, down, left, right, or diagonally) in the 2020 grid?
 
 Answer: 70600674
 */

#include <iostream>
#include <fstream>

using namespace std;

long getProductUp (int row, int col, int array[20][20])
{
    return array[row][col] * array[row-1][col] * array[row-2][col] * array[row-3][col];
}

long getProductDown (int row, int col, int array[20][20])
{
    return array[row][col] * array[row+1][col] * array[row+2][col] * array[row+3][col];
}

long getProductLeft (int row, int col, int array[20][20])
{
    return array[row][col] * array[row][col-1] * array[row][col-2] * array[row][col-3];
}

long getProductRight (int row, int col, int array[20][20])
{
    return array[row][col] * array[row][col+1] * array[row][col+2] * array[row][col+3];
}

long getProductDiagUR (int row, int col, int array[20][20])
{
    return array[row][col] * array[row-1][col+1] * array[row-2][col+2] * array[row-3][col+3];
}

long getProductDiagUL (int row, int col, int array[20][20])
{
    return array[row][col] * array[row-1][col-1] * array[row-2][col-2] * array[row-3][col-3];
}

long getProductDiagLR (int row, int col, int array[20][20])
{
    return array[row][col] * array[row+1][col+1] * array[row+2][col+2] * array[row+3][col+3];
}

long getProductDiagLL (int row, int col, int array[20][20])
{
    return array[row][col] * array[row+1][col-1] * array[row+2][col-2] * array[row+3][col-3];
}

long getAllProducts (int row, int col, int array[20][20])
{
    long product = 0, tempProduct = 0;
    
    if (row > 2 && row < 17 && col > 2 && col < 17)
    {
        tempProduct = getProductUp(row, col, array);
        if (tempProduct > product)
            product = tempProduct;
        tempProduct = getProductDown(row, col, array);
        if (tempProduct > product)
            product = tempProduct;
        tempProduct = getProductLeft(row, col, array);
        if (tempProduct > product)
            product = tempProduct;
        tempProduct = getProductRight(row, col, array);
        if (tempProduct > product)
            product = tempProduct;
        tempProduct = getProductDiagLL(row, col, array);
        if (tempProduct > product)
            product = tempProduct;
        tempProduct = getProductDiagLR(row, col, array);
        if (tempProduct > product)
            product = tempProduct;
        tempProduct = getProductDiagUL(row, col, array);
        if (tempProduct > product)
            product = tempProduct;
        tempProduct = getProductDiagUR(row, col, array);
        if (tempProduct > product)
            product = tempProduct;
    }
    
    if (row < 3 && col < 3)
    {
        tempProduct = getProductDown(row, col, array);
        if (tempProduct > product)
            product = tempProduct;
        tempProduct = getProductRight(row, col, array);
        if (tempProduct > product)
            product = tempProduct;
        tempProduct = getProductDiagLR(row, col, array);
        if (tempProduct > product)
            product = tempProduct;
    }
    
    if (row < 3 && col > 16)
    {
        tempProduct = getProductDown(row, col, array);
        if (tempProduct > product)
            product = tempProduct;
        tempProduct = getProductLeft(row, col, array);
        if (tempProduct > product)
            product = tempProduct;
        tempProduct = getProductDiagLL(row, col, array);
        if (tempProduct > product)
            product = tempProduct;
    }
    
    if (row < 3 && col > 2 && col < 17)
    {
        tempProduct = getProductDown(row, col, array);
        if (tempProduct > product)
            product = tempProduct;
        tempProduct = getProductRight(row, col, array);
        if (tempProduct > product)
            product = tempProduct;
        tempProduct = getProductDiagLR(row, col, array);
        if (tempProduct > product)
            product = tempProduct;
        tempProduct = getProductLeft(row, col, array);
        if (tempProduct > product)
            product = tempProduct;
        tempProduct = getProductDiagLL(row, col, array);
        if (tempProduct > product)
            product = tempProduct;
    }
    
    if (row > 16 && col < 3)
    {
        tempProduct = getProductUp(row, col, array);
        if (tempProduct > product)
            product = tempProduct;
        tempProduct = getProductRight(row, col, array);
        if (tempProduct > product)
            product = tempProduct;
        tempProduct = getProductDiagUR(row, col, array);
        if (tempProduct > product)
            product = tempProduct;
    }

    if (row > 16 && col > 16)
    {
        tempProduct = getProductUp(row, col, array);
        if (tempProduct > product)
            product = tempProduct;
        tempProduct = getProductLeft(row, col, array);
        if (tempProduct > product)
            product = tempProduct;
        tempProduct = getProductDiagUL(row, col, array);
        if (tempProduct > product)
            product = tempProduct;
    }

    if (row > 16 && col > 2 && col < 17)
    {
        tempProduct = getProductUp(row, col, array);
        if (tempProduct > product)
            product = tempProduct;
        tempProduct = getProductLeft(row, col, array);
        if (tempProduct > product)
            product = tempProduct;
        tempProduct = getProductRight(row, col, array);
        if (tempProduct > product)
            product = tempProduct;
        tempProduct = getProductDiagUL(row, col, array);
        if (tempProduct > product)
            product = tempProduct;
        tempProduct = getProductDiagUR(row, col, array);
        if (tempProduct > product)
            product = tempProduct;
    }
    
    if (col < 3 && row > 2 && row < 16)
    {
        tempProduct = getProductUp(row, col, array);
        if (tempProduct > product)
            product = tempProduct;
        tempProduct = getProductDown(row, col, array);
        if (tempProduct > product)
            product = tempProduct;
        tempProduct = getProductRight(row, col, array);
        if (tempProduct > product)
            product = tempProduct;
        tempProduct = getProductDiagLR(row, col, array);
        if (tempProduct > product)
            product = tempProduct;
        tempProduct = getProductDiagUR(row, col, array);
        if (tempProduct > product)
            product = tempProduct;
    }
    
    if (col > 16 && row > 2 && row < 16)
    {
        tempProduct = getProductUp(row, col, array);
        if (tempProduct > product)
            product = tempProduct;
        tempProduct = getProductDown(row, col, array);
        if (tempProduct > product)
            product = tempProduct;
        tempProduct = getProductLeft(row, col, array);
        if (tempProduct > product)
            product = tempProduct;
        tempProduct = getProductDiagLL(row, col, array);
        if (tempProduct > product)
            product = tempProduct;
        tempProduct = getProductDiagUL(row, col, array);
        if (tempProduct > product)
            product = tempProduct;
    }
    
    return product;
    
}

int main(int argc, const char * argv[])
{
    
    int array [20][20];
    ifstream input;
    input.open("/Users/migration/Desktop/xCode/Project Euler/11/11/numbers.txt");
    long product = 0, tempProduct = 0;
    
    for (int i = 0; i < 20; i++)
        for (int j = 0; j < 20; j++)
            input >> array[i][j];
/*
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
            cout << array[i][j] << '\t';
        cout << endl;
    }
*/
    for (int i = 0; i < 20; i++)
        for (int j = 0; j < 20; j++)
        {
            if (array[i][j] > 0)
            {
                tempProduct = getAllProducts(i, j, array);
                if (tempProduct > product)
                    product = tempProduct;
                /*
                if (tempProduct > 70600674)
                {
                    cout << "Row: " << i+1 << " Col: " << j+1 << " is ";
                }
                cout << tempProduct << endl;
                 */
            }
        }
            
    cout << "Product is "<<product << endl;
    cout << "Should be  70600674\n";
    

    return 0;
}

