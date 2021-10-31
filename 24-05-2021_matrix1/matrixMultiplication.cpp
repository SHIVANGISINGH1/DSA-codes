#include<iostream>
using namespace std;

int main()
{
    int rows1,cols1,rows2,cols2;
    
    // take input for the 1st matrix
    cin>>rows1>>cols1;
    
    int **arr1 = new int *[rows1];
    
    for (int idx=0; idx<rows1; idx++)
    {
        arr1[idx] = new int[cols1];
    }
    
    for (int rowidx=0; rowidx<rows1; rowidx++)
    {
        for (int colidx=0; colidx<cols1; colidx++)
        {
            cin>>arr1[rowidx][colidx];
        }
    }
    // take input for the 2nd matrix 
    
    cin>>rows2>>cols2;
    
    int **arr2 = new int *[rows2];
    
    for (int idx=0; idx<rows2; idx++)
    {
        arr2[idx] = new int[cols2];
    }
    
    for (int rowidx=0; rowidx<rows2; rowidx++)
    {
        for (int colidx=0; colidx<cols2; colidx++)
        {
            cin>>arr2[rowidx][colidx];
        }
    }

    // we will multiply elements of matrix only when column of 1st matrix is equal to row of 2nd matrix
    // the resulting matrix will have rows = row1 and column = column2
    
    if (rows2==cols1)
    {   
        for (int rowidx=0; rowidx<rows1; rowidx++)
        {
            for (int colidx=0; colidx<cols2; colidx++)
            {     
                int ans =0;
                // we will multiply value at ist idx of matrix1 -> entire row with entire column of 2nd matrix                  
                for (int colidx1=0; colidx1<cols1; colidx1++)
                {
                    ans += arr1[rowidx][colidx1] * arr2[colidx1][colidx];
                }

                cout<<ans<<" ";
            }
            cout<<endl;
        }
    }
    else
    {
        cout<<"Invalid input";
    }

return 0;    
}