// similar to the previous question, climpStarisWithVariableJumps 
// here we have to calculate the min moves.

#include<bits/stdc++.h>
using namespace std;

int jumpT(int num, vector<int>& jumps, vector<int>& dp)
{
    
    dp[num] = 0;
    
    for (int idx=jumps.size()-1; idx>=0; idx--) {
           
        int temp = jumps[idx];

        if (temp == 0) {
            dp[idx] = 1000;
            continue;
        }
        
        int mn = INT_MAX;
        while(temp > 0) {
            
            if (idx+temp <= num)
            mn = min(mn,dp[idx + temp]); // caclu the minimum moves
            temp-=1;
        }
        
        dp[idx] = mn + 1; 
       
    }

    return dp[0];
}

int main() {

  int num;

  cin >> num;

  vector<int> jumps(num);

  for (int idx = 0; idx < num; idx++)
  {
    cin >> jumps[idx];
  }

  vector<int> dp(num + 1, 0);

  int ans = jumpT(num, jumps, dp);

  if (ans < 30) cout << ans;
  else cout << "null";
}