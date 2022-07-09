#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    
    void setZeroes(vector<vector<int>>& matrix) {
        
        int R = matrix.size();
        int C = matrix[0].size();
        
        // solution of O(1) memory
        
        bool firstBlock = true;
        
        for (int cIdx=0; cIdx<C; cIdx++) {
            if (matrix[0][cIdx] == 0) {
                firstBlock = false;
            }
        }
        
        
        for (int rIdx=1; rIdx<R; rIdx++) {
            
            for (int cIdx=0; cIdx<C; cIdx++) {
                
                if (matrix[rIdx][cIdx] == 0) {
                    matrix[0][cIdx] = 0;
                    matrix[rIdx][0] = 0;
                }
            }
        }
       
        
        for (int rIdx=1; rIdx<R; rIdx++) {
            for (int cIdx=1; cIdx<C; cIdx++) {
                
                if (matrix[rIdx][0] == 0 || matrix[0][cIdx] == 0) {
                    matrix[rIdx][cIdx] = 0;
                }
            }
        }
        
        if (matrix[0][0] == 0) {
            for (int rIdx=0; rIdx<R; rIdx++) {
                matrix[rIdx][0] = 0;
            }
        }
        
        if (!firstBlock) {
            for (int cIdx=0; cIdx<C; cIdx++) {
                 matrix[0][cIdx] = 0;
            }
        }
    
    }
};