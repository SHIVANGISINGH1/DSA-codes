// In this we have to find The saddle price : defined as the least price in the row but the maximum price in the column of the matrix.

#include<iostream>
using namespace std;

int main()
{
    int rows,cols;
    
    cin>>rows;

    cols= rows;
    
    int **arr= new int *[rows];
    
    for (int idx=0; idx<rows; idx++)
    {
        arr[idx] = new int[cols];
    }
    
    for (int rowidx=0; rowidx<rows; rowidx++)
    {
        for (int colidx=0; colidx<cols; colidx++)
        {
            cin>>arr[rowidx][colidx];
        }
    }
    
    int idx,check=1;
    
    for (int rowidx=0; rowidx<rows; rowidx++)
    {       
        int min= arr[rowidx][0];   // find the min element in the row then find max ele in that column if they are equal = saddle point
        idx=0;

        for (int col=0; col<rows; col++)
        {
            if (arr[rowidx][col]<min)
            {
                min = arr[rowidx][col];
                idx = col;
            }
        } 

        int max= arr[0][idx];

        for (int row=0; row<rows; row++)
        {
            if (max<arr[row][idx])
            {
                max = arr[row][idx];
            }
        }
    
        if (max==min)
        {   
            check=0;
            cout<<max;
        }
    }

    if (check==1) cout<<"Invalid input";

    return 0;
}