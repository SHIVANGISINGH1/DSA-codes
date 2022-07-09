#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int maxProf = 0;
        int buy = prices[0]; 
        
        for(int idx=1; idx<prices.size(); idx++) {
            
            int sell = prices[idx] - buy; 
            buy = min(buy,prices[idx]);  
            maxProf = max(sell,maxProf); 
            
        }
        
        return maxProf;
    }
};