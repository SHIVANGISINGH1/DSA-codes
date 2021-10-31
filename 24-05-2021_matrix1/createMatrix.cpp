#include<iostream>
using namespace std;

int main()
{
    int rows,cols;

    cin>>rows>>cols;
    
    // creating a pointers to pointers integer which will point to the pointer arrays of rows
    int **arr = new int *[rows];
    
    // making seperate dynamic array for each element of row   
    for (int idx=0; idx<rows; idx++)
    {
        arr[idx] = new int[cols];
    }
    // taking input in matrix
    
    for (int rowidx=0; rowidx<rows; rowidx++)
    {
        for (int colidx=0; colidx<cols; colidx++)
        {
            cin>>arr[rowidx][colidx];
        }
    }
    
    // display matrix
    for (int rowidx=0; rowidx<rows; rowidx++)
    {
        for (int colidx=0; colidx<cols; colidx++)
        {
            cout<<arr[rowidx][colidx]<<" ";
        }
        cout<<endl;
    }

    return 0;
}