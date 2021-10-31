#include<iostream>
using namespace std;

int main()
{
    int rows,cols;

    cin>>rows>>cols;
    
    int **arr = new int *[rows];
    
    for (int index=0; index<rows; index++)
    {
        arr[index] = new int[cols];
    }
  
    for (int rowidx=0; rowidx<rows; rowidx++)
    {
        for (int colidx=0; colidx<cols; colidx++)
        {
            cin>>arr[rowidx][colidx];
        }
    }

    // we will run loop column times and we will print from rows-1 when colNo is odd and from top when colNo is even     
    int colNo=0;
    
    for (int colidx=0; colidx<cols; colidx++)
    {   
        if (colNo%2!=0 && colNo!=0)
        {
            for (int rowidx=rows-1; rowidx>=0; rowidx--)
            {
                cout<<arr[rowidx][colidx]<<endl;
            }
        }
        else
        {
            for (int rowidx=0; rowidx<rows; rowidx++)
            {
                cout<<arr[rowidx][colidx]<<endl;
            }
        }

        colNo++;
    }

    return 0;
}