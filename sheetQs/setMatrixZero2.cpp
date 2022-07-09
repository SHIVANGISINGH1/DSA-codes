#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    
    void setZeroes(vector<vector<int>>& matrix) {
        
        int R = matrix.size();
        int C = matrix[0].size();
        
        // solution of m + n memory
        
        vector<int> rowSpace(R, 0);
        vector<int> colSpace(C, 0);
        
        for (int rIdx=0; rIdx<R; rIdx++) {
            for (int cIdx=0; cIdx<C; cIdx++) {
                
                if (matrix[rIdx][cIdx] == 0) {
                    rowSpace[rIdx] = 1;
                    colSpace[cIdx] = 1;
                }
            }
        }
        
        for (int idx=0; idx<R; idx++) {
            
            if (rowSpace[idx] == 1) {
                
                for (int cIdx=0; cIdx<matrix[0].size(); cIdx++) {
                    matrix[idx][cIdx] = 0;
                }
                
            }
        }
        
        
        for (int idx=0; idx<C; idx++) {
            
            if (colSpace[idx] == 1) {
                
                for (int rIdx=0; rIdx<matrix.size(); rIdx++) {
                    matrix[rIdx][idx] = 0;
                }
                
            }
        }
        
        
    }
};