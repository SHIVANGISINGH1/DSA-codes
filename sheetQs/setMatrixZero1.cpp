#include<iostream>
#include<vector>
using namespace std;

// solution with a m*n memory 

class Solution {
public:
    
    void setZero(vector<vector<int>>& copyMatrix, int row, int col) {
        
        for (int idx=0; idx<copyMatrix[0].size(); idx++) {
            copyMatrix[row][idx] = 0;
        }
        
        for (int idx=0; idx<copyMatrix.size(); idx++) {
            copyMatrix[idx][col] = 0;
        }
    }
    
    void setZeroes(vector<vector<int>>& matrix) {
        
        int R = matrix.size();
        int C = matrix[0].size();
        
        // solution of mn memory
        
        vector<vector<int>> copyMatrix(R, vector<int> (C));
        
        for (int rIdx=0; rIdx<R; rIdx++) {
            for (int cIdx=0; cIdx<C; cIdx++) {
                copyMatrix[rIdx][cIdx] = matrix[rIdx][cIdx];
            }
        }
        
        for (int rIdx=0; rIdx<R; rIdx++) {
            for (int cIdx=0; cIdx<C; cIdx++) {
                
                if (matrix[rIdx][cIdx] == 0) {
                    setZero(copyMatrix,rIdx,cIdx);
                }
            }
        }
        
        for (int rIdx=0; rIdx<R; rIdx++) {
            for (int cIdx=0; cIdx<C; cIdx++) {
                matrix[rIdx][cIdx] = copyMatrix[rIdx][cIdx];
            }
        }
        
        
    }
};