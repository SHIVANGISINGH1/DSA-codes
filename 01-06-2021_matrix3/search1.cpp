// Link: https://leetcode.com/problems/search-a-2d-matrix/
// to search in the 2d matrix we converted it into 1d array and simply apply binary search but for that rows and columns are calculated
// all elements in the matrix are divided in multipls of column only ,so we applied formula and search for that element. 

#include<bits/stdc++.h>
using namespace std;

int main()
{
    class Solution {
    public:
        bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
            
            int rows = matrix.size();
            int cols = matrix[0].size();
            int start=0;
            int end = rows*cols-1;
            
            while (start<=end)
            {
                int  mid = start + (end - start)/2;
                int row = mid/cols; // for coordinates of mid element in the matrix
                int col = mid%cols;
                int ele = matrix[row][col];

                if (ele==target)
                {
                    return true;
                }
                else if (ele<target)
                {
                    start = mid+1;
                }
                else
                {
                    end = mid-1;
                }
                    
            }
            return false;
        }
};

return 0;
}