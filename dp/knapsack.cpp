#include <bits/stdc++.h>
#include <vector>

using namespace std;

void zeroOneKnapsack(int n, vector<int> value, vector<int> weight, int cap) {
    
    unordered_map<int,int> mp;
     
    for (int idx=0; idx<n; idx++) {
        mp.insert({weight[idx],value[idx]});
    }
    
    int cols = cap + 1;
    int rows = n + 1;
    
    sort(weight.begin(), weight.end());
    vector<vector<int>> dp(rows, vector<int> (cols,0));
    
    
    
    for (int rIdx=0; rIdx<rows; rIdx++) {
        dp[rIdx][0] = 1;
    }
    
    for (int cIdx=1; cIdx<cols; cIdx++) {
        dp[0][cIdx] = 0;
    }
    
    for (int rIdx=1; rIdx<rows; rIdx++) {
        
        int wt = weight[rIdx-1];
        
        int val = mp[wt];
        cout << wt << " ";
        
        for (int cIdx=1; cIdx<cols; cIdx++) {
            
            if (dp[rIdx-1][cIdx] > 0) {
                dp[rIdx][cIdx] = max(dp[rIdx][cIdx],dp[rIdx-1][cIdx]);
            }
            
            if (cIdx >= wt) {
                int diff = cIdx-wt;
                
                if (dp[rIdx-1][diff] > 0) {
                    int val1 = dp[rIdx-1][diff];
                    if (val1 == 1) val1 = 0;
                   
                    val += val1;
                    dp[rIdx][cIdx] = max(dp[rIdx][cIdx],val);
                }
            }    
            
            cout << dp[rIdx][cIdx] << " " << val << " ";
        }
        
        cout << endl;
    }
    
    //cout << dp[rows-1][cols-1];

}

int main() {

  int n;
  cin >> n;

  vector<int> val(n);
  for (int i = 0; i < n; i++) {
    cin >> val[i];
  }

  vector<int> weight(n);
  for (int i = 0; i < n; i++) {
    cin >> weight[i];
  }
  
 
  
  int cap;
  cin >> cap;
    
  zeroOneKnapsack(n, val, weight, cap);


}