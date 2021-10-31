// Search in 2d array 2 limk:https://leetcode.com/problems/search-a-2d-matrix-ii/
// Here the 2d matrix was sorted row-wise and column-wise 
// So we fixed one element -> lastelement of first row if our target is smaller than ele we decrement the column else increment the row
// Alternate approch we can take lastrow first column element also , for that if target is smaller we will decrement row else inc col

#include<bits/stdc++.h>
using namespace std;

int main()
{
class Solution {
    public:
        bool searchMatrix(vector<vector<int>>& matrix, int target) {
            
            bool targetFound = false;
            int row = 0;
            int col = matrix[0].size() - 1;

            while((col >= 0 && row < matrix.size()))
            {
                if(matrix[row][col] == target)  // last element of first column
                {
                    targetFound = true;
                    return targetFound;
                }
                else if(target < matrix[row][col])
                {
                    col--;
                }else
                {
                    row++;
                }
            }

            return targetFound;
        }
};

return 0;
}