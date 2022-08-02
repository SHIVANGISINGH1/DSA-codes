#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        
        
        int n = matrix.size();
        
        
        int left = matrix[0][0];
        int right = matrix[n-1][n-1];
        
        while(left<right) {
            
            int mid = left + (right-left)/2;
            
            int count = 0;
            for (int idx=0; idx<n; idx++) {
                count += upper_bound(matrix[idx].begin(), matrix[idx].end(), mid) - matrix[idx].begin();
            }
            if (count < k) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }
        
        return left;

    }
};