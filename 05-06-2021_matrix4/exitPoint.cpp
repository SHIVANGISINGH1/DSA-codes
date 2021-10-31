// Exit Point : We are traversing the matrix from first row till element is 1 , at 1 we change the direction and traverse 

#include<iostream>
using namespace std;

int main()
{
    int rows,cols;

    cin>>rows>>cols;
    
    int **arr= new int *[rows];
    
    for (int idx=0; idx<rows; idx++)
    {
        arr[idx]=new int[cols];
    }
        
    for (int rowidx=0; rowidx<rows; rowidx++)
    {
        for (int colidx=0; colidx<cols; colidx++)
        {
            cin>>arr[rowidx][colidx];
        }
    }

    int rowidx = 0 , colidx = 0 , printrow = 0 , printcol = 0 ;
    int direction = 0 ;

    while ( rowidx>=0 && rowidx < rows && colidx>=0 && colidx < cols)
    {
        if (arr[rowidx][colidx] == 1)  // we will change the direction 
        {
            direction++ ;
        }
    
        direction = direction % 4 ;  // we will make direction again 0 when it is equal to 4 
        
        printrow = rowidx ;
        printcol = colidx ;
        
        switch(direction)
        {
            case 0 : colidx++ ; break ;  // we are traversing according to the direction 
            case 1 : rowidx++ ; break ;
            case 2 : colidx-- ; break ;
            case 3 : rowidx-- ; break ;
        }
    } 

    cout<<printrow<<"\n"<<printcol;

    return 0 ;
}

// 0 0 1 0
// 1 0 0 0 
// 0 0 0 0
// 1 0 1 0
// traverse -> right -> 0 0 1 -> down 0 0 1 -> left 0 1 -> up 0 1 -> right 0 0 0 : Exit