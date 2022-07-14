// it is similar to knapsack but we can use a wt infinite number of times
// Here similar to coin change permuations we will use a array (repeatition) and not a 2d array

#include <bits/stdc++.h>
#include <vector>

using namespace std;

void unboundedKnapsack(int n, vector<int> value, vector<int> weight, int cap) {
    
    vector<int> dp(cap+1,0);

    for (int wtIdx=0; wtIdx<weight.size(); wtIdx++) {
        
        int wt = weight[wtIdx]; 
        int val = value[wtIdx];


        for (int dpIdx=1; dpIdx<=cap; dpIdx++) {

            int prevVal = dp[dpIdx]; 
            
            if (dpIdx >= wt) {
                int diff = dpIdx-wt;
                dp[dpIdx] = max(dp[diff] + val,prevVal);
            }
        }
    }
    
    
    cout << dp[cap];
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

    unboundedKnapsack(n, val, weight, cap);

    return 0;
}