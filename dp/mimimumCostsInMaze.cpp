// Here we are given a matrix in which you can travel to right or down and you have to reach the end
// with minimum cost 
// each cell represent the cost of that cell
// we will start from the destination point and reach to the top by calculating the cost 
// with travelling right and down

#include <bits/stdc++.h>
using namespace std;

int minCost(int n, int m, vector<vector<int>>& arr, vector<vector<int>>& dp ) {

	dp[n-1][m-1] = arr[n-1][m-1];

	for (int rIdx=n-1; rIdx>=0; rIdx--) {
		
		for (int cIdx=m-1; cIdx>=0; cIdx--) {
			
			if (rIdx == n-1 && cIdx== m-1) {
				continue;
			}

			int right = cIdx+1;
			int rValue = INT_MAX;

			if (right >=0 && right <= m-1) {
				rValue  = dp[rIdx][right];
			}
			
			int down = rIdx+1;
			int dValue = INT_MAX;

			if (down >=0 && down <= n-1) {
				dValue  = dp[down][cIdx];
			}

			dp[rIdx][cIdx] = arr[rIdx][cIdx] + min(rValue,dValue);
		}
	}

	return dp[0][0];

}

int main()  {

	int n;
	int m;

	cin >> n >> m;

	vector<vector<int>> arr(n, vector<int>(m));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	vector<vector<int>> dp(n, vector<int>(m));

	cout << minCost(n, m, arr, dp);

	return 0;
}