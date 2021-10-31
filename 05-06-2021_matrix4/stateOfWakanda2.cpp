#include<iostream>
using namespace std;

int main()
{
    int rows;

    cin>>rows;
    
    int arr[rows][rows];
    
    for (int rowidx=0; rowidx<rows; rowidx++)
    {
        for (int colidx=0; colidx<rows; colidx++)
        {
            cin>>arr[rowidx][colidx];
        }
    }
    
    int rowidx=0;
    int Row=rows-1,Col=0;
    
    while (Row>=0)
    {
    
        int rowidx=0;
    
        for (int colidx=Col; colidx<rows; colidx++)  // printing the upper half matrix 
        {
            cout<<arr[rowidx][colidx]<<endl;        
            rowidx = rowidx+1;
        }

        Col++;
        Row-=1;
    }

    return 0;
}
    // 11  12  13  14
    // 15  16  17  18
    // 19  20  21  22
    // 23  24  25  26
    // output 11 16 21 26 12 17 22 13 18 14