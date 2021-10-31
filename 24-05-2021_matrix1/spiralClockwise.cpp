// link : https://leetcode.com/problems/spiral-matrix/

// we will take 4 pointers for rowstart,colstart,rowend,colend then we will traverse in clockwise direction
// when first row is printed we will increment rowstrt then we will print last column and decrement colend then print last row
// and decrement rowend then print first column and increment colstart 
// we will continue till all the elements are printed . Increase count at every step in loop

#include<iostream>
#include<vector>
using namespace std;

int main()
{
    class Solution {
    public:
        vector<int> spiralOrder(vector<vector<int>>& matrix) {
            
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        int count=1;
        int rowstrt = 0 , colstrt = 0, rowend = rows-1, colend = cols-1;
        vector<int> ans;
            
        while (count <= (rows*cols))
        {

            for (int colidx = colstrt; colidx <= colend && count <= (rows*cols); colidx++)
            {
                ans.push_back(matrix[rowstrt][colidx]);
                count++;
            }

            rowstrt++;

            for (int rowidx = rowstrt; rowidx <= rowend && count <= (rows*cols); rowidx++)
            {
                ans.push_back(matrix[rowidx][colend]);
                count++;
            }

            colend--;

            for (int colidx = colend; colidx >= colstrt && count <= (rows*cols); colidx--)
            {
                ans.push_back(matrix[rowend][colidx]);
                count++;
            }

            rowend--;

            for (int rowidx = rowend; rowidx >= rowstrt && count <= (rows*cols); rowidx--)
            {
                ans.push_back(matrix[rowidx][colstrt]);
                count++;
            }

            colstrt++;

        }
        
        return ans;
            
        }
    };

    return 0;
}