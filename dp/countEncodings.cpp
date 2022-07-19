#include<bits/stdc++.h>
using namespace std;


int printEncodings(string inp) {

    int size = inp.size();
   
    vector<int> dp(size,0);
    dp[0] = 1;
    
    for (int idx=1; idx<size; idx++) {
    string str = inp.substr(idx-1,2);

    if(inp[idx] == '0') {
        if(idx+1<size && inp[idx+1] == '0') return 0;
     
        int s = stoi(str);
       
        if(s<=26) {
            dp[idx] = 1;
        }else {
            dp[idx] = 0;
            return 0;
        }
        
        if(idx+1<size && inp[idx+1] != '0') {
            dp[idx+1] = dp[idx];
            idx+=1;
        }
    }   
    else  {
        int val = stoi(str);
        if (val <= 26) {
            dp[idx] = dp[idx-1] + 1;//3
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
}