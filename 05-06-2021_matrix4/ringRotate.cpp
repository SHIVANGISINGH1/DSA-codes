// first we will put the values of the shell we have to rotate in a 1D vector then we will rotate the vector and save 
// it in the 2D array given in the question 

#include<iostream>
#include<vector>
using namespace std;

void rotate(vector<int> &vec, int rotate) // to rotate the shell 
{   
    bool isNegative = false;
    
    if(rotate < 0)
    {   
        isNegative = true;
        rotate = - rotate;
    }
    
    rotate = rotate % vec.size();
    
    if(isNegative) // for negative rotation 
    {
        rotate = vec.size() - rotate;
    }
    
    if (rotate == 0)
    {
        return ;
    }
    
    for (int idx = 0; idx < vec.size()-rotate ; idx++) // to rotate the vector
    {
        vec.push_back(vec[0]) ;
        vec.erase(vec.begin()) ; 
    }
}

void storeRing(vector<vector<int>> &array , vector<int> linear , int shell)  // to save the rotated vector in the 2D given array
{
    int rStart = shell - 1 ;
    int rEnd = array.size() - shell ;
    int cStart = shell - 1 ;
    int cEnd = array[0].size() - shell ;
    int count = 0 ;
    
    for (int rowstart = rStart ; rowstart < rEnd ; rowstart++)
    {
        array[rowstart][cStart] = linear[count] ;
        count++ ;
    }
    
    for (int colstart = cStart ; colstart < cEnd ; colstart++)
    {
        array[rEnd][colstart] = linear[count] ;
        count++ ;
    }
    
    for (int rowend = rEnd ; rowend > rStart ; rowend--)
    {
        array[rowend][cEnd] = linear[count] ;
        count++ ;
    }
    
    for (int colend= cEnd ; colend > cStart ; colend--)
    {
        array[rStart][colend] = linear[count] ;
        count++ ;
    }
}

void print(vector<vector<int>> array)  // To print the matrix
{   
    int row = array.size() ;
    int col = array[0].size() ;
    
    for (int rowidx = 0 ; rowidx < row ; rowidx++)
    {
        for (int colidx = 0 ; colidx < col ; colidx++)
        {
            cout << array[rowidx][colidx] << " ";
        }
        cout << endl;
    }
}

void ringrotate( vector<vector<int>> array,int shell, int rotations )  // Here we are storing the elements of shell in linear vector
{
    int rStart = shell - 1 ;
    int rEnd = array.size() - shell ;
    int cStart = shell - 1 ;
    int cEnd = array[0].size() - shell ;
    
    vector<int> linear ;
    
    for ( int rowstart = rStart ; rowstart < rEnd ; rowstart++ )
    {
        linear.push_back( array[rowstart][cStart] ) ;
    }
    
    for (int colstart = cStart ; colstart < cEnd ; colstart++ )
    {
        linear.push_back( array[rEnd][colstart] ) ;
    }
    
    for (int rowend = rEnd ; rowend > rStart ; rowend-- )
    {
        linear.push_back( array[rowend][cEnd] ) ;
    }
    
    for (int colend = cEnd ; colend > cStart ; colend-- )
    {
        linear.push_back( array[rStart][colend] ) ;
    }
    
    rotate(linear, rotations) ;  // calling the rotate , storeRing and print function 
    storeRing(array, linear, shell) ;
    print(array) ;
}

int main() 
{
    int row,col;

    cin>>row>>col;
    
    vector<vector<int>> array;
    
    for (int idx=0; idx<row; idx++)
    {   
        vector<int> subarray;
    
        for (int idx1 =0; idx1<col; idx1++)
        {
        
            int temp; 
        
            cin>>temp;
        
            subarray.push_back(temp);
        }

        array.push_back(subarray);
    }
        
    int shell,rotations;
    
    cin>>shell>>rotations;
    
    ringrotate(array, shell, rotations);  
    
    return 0;
}

// 11 12 13 14 15 16 17
// 21 22 23 24 25 26 27
// 31 32 33 34 35 36 37
// 41 42 43 44 45 46 47
// 51 52 53 54 55 56 57
// Shell No. ->2 Rotate -> 3

// Shell 2 -> 22 23 24 . . 26 36 46 45 44 .. 42 32 
// rotate 3 -> 25 26 .. 45 44 43 42 32 22 .. 23 24 

// Output
// 11 12 13 14 15 16 17
// 21 25 26 36 46 45 27
// 31 24 33 34 35 44 37
// 41 23 22 32 42 43 47
// 51 52 53 54 55 56 57