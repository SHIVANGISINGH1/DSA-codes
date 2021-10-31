// In this we will first calculate transpose and then interchange the columns

#include<iostream>
using namespace std;

int main()
{
    int rows,cols;

    cin>>rows;

    cols = rows;

    int **arr = new int *[rows];

    for (int idx=0; idx<rows; idx++)
    {
        arr[idx] = new int[cols];
    }
      
    for (int row=0; row<rows; row++)
    {
        for (int col=0; col<cols; col++)
        {
            cin>>arr[row][col];
        }
    }

    int idx=0;
    
    for (int row=0; row<rows; row++)
    {
        for ( int col=idx; col<cols; col++) // taking the transpose of the matrix
        {   
            int temp = arr[row][col];
            arr[row][col] = arr[col][row];
            arr[col][row]=temp;
        }
    
    idx++;
    }

    for (int row=0; row<rows; row++)
    {   
        int column = cols;
        
        for (int col=0; col<column; col++)    // interchanging the columns i.e column 3 with 0 and 1 with 2 
        {
            int temp = arr[row][col];
            arr[row][col]= arr[row][column-1];
            arr[row][column-1]=temp;
            column--;
        }
        
    }

    for (int row=0; row<rows; row++)   //  print the matrix 
    {
        for (int col=0; col<cols; col++)
        {
            cout<<arr[row][col]<<" ";
        }
        cout<<endl;
    }

    return 0;
}
    // 11  12  13  14
    // 21  22  23  24
    // 31  32  33  34
    // 41  42  43  44
    // output
    // 41  31  21  11
    // 42  32  22  12
    // 43  33  23  13
    // 44  34  24  14