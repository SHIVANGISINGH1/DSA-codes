// Similar to keyboard pattern, here we need to just tell the count of the combinations
// because we only have two digits numbers we will check for i-2 and i-1
// we will make the pattern by checking the values at i-1 and i // 4cases 0,0 !0,0 0,!0 !0,!0 


#include<bits/stdc++.h>
using namespace std;

int printEncodings(string inp) {

    int size = inp.size();
   
    vector<int> dp(size,0);
    dp[0] = 1;
    
    for (int idx=1; idx<size; idx++) {
    string str = inp.substr(idx-1,2);

    if (inp[idx-1] == '0' && inp[idx] == '0') {
        dp[idx] = 0;
    }
    else if(inp[idx-1] == '0' && inp[idx] != '0') {
        dp[idx] = dp[idx-1];
    }
    else if(inp[idx-1] != '0' && inp[idx] == '0') {
        if (inp[idx-1] == '1' || inp[idx-1] == '2') {
            dp[idx] = idx>=2 ? dp[idx-2] : 1;
        }
        else {
            dp[idx] = 0;
        }
    }
    else  {
        int val = stoi(str);
        if (val <= 26) {
            dp[idx] = idx>=2 ? dp[idx-1] + dp[idx-2] : dp[idx-1] + 1;
        }
        else {
            dp[idx] = dp[idx-1];
        }
    }
       
}
    
    return dp[size-1];
}


int main() {

    string inp;

    cin >> inp;
   
    cout << printEncodings(inp);

    return 0;
}