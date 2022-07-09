// In this problem we have mine the gold kept at each cell and reach the last column of matrix with max gold
// we will start with second last column and calculate the max gold move as we can travell
// in three steps and reach the column with max gold 

#include <bits/stdc++.h>
using namespace std;

int collectGold(int n, int m, vector<vector<int>>& arr, vector<vector<int>>& dp) {
    
    for (int rIdx=0; rIdx<n; rIdx++) {
        dp[rIdx][m-1] = arr[rIdx][m-1];
    }
    
    for (int cIdx=m-2; cIdx>=0; cIdx--) {
        
        for (int rIdx=n-1; rIdx>=0; rIdx--) {
            
            int top = 0;
            int right = 0;
            int down = 0;
            
            if (rIdx-1 >= 0 && rIdx-1 <n && cIdx+1>=0 && cIdx+1<m) {
                top = dp[rIdx-1][cIdx+1];
            }
            
            if (rIdx >= 0 && rIdx <n && cIdx+1>=0 && cIdx+1<m) {
                right = dp[rIdx][cIdx+1];
            }
            
            if (rIdx+1 >= 0 && rIdx+1 <n && cIdx+1>=0 && cIdx+1<m) {
                down = dp[rIdx+1][cIdx+1];
            }
            
            int mx = max(top, max(down,right));

            dp[rIdx][cIdx] = arr[rIdx][cIdx] + mx;
        }
    }
    
    int ans = INT_MIN;
    
    for (int rIdx=0; rIdx<n; rIdx++) {
        ans = max(ans,dp[rIdx][0]);   
    }
    
    return ans;
}



int main() {

	int n, m;

	cin >> n >> m;

	vector<vector<int>> arr(n, vector<int>(m, 0));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	vector<vector<int>> dp(n, vector<int>(m, 0));

	cout << collectGold(n, m, arr, dp);

	return 0;

}