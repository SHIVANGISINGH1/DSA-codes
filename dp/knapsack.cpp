#include <bits/stdc++.h>
#include <vector>

using namespace std;

void zeroOneKnapsack(int n, vector<int> value, vector<int> weight, int cap) {
    
    int cols = cap + 1;
    int rows = n + 1;

    vector<vector<int>> dp(rows, vector<int> (cols,0));
    
    
    for (int rIdx=1; rIdx<rows; rIdx++) {

        int wt = weight[rIdx-1];
        int val = value[rIdx-1];

        for (int cIdx=1; cIdx<cols; cIdx++) {
            int prevVal = dp[rIdx-1][cIdx];//25
            int diff = cIdx-wt;

            dp[rIdx][cIdx] = prevVal;

            if (diff >= 0) {
                if (dp[rIdx-1][diff] >= 0)
                dp[rIdx][cIdx] = max(val + dp[rIdx-1][diff],dp[rIdx][cIdx]); //15
            }
           
        }
    }

    cout << dp[rows-1][cols-1];
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

    return 0;
}