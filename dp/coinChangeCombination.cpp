// here we ware given a target and an array we have to form subsets but we can use an ele infinite number
// of times to form target
// we will solve this using a array dp of size target+1
// we will check if we can form the sum(idx) using sum(idx-ele) 
// if yes we will add and update the current sum [it will give the count of subsets we can use to make that sum]

#include<bits/stdc++.h>
using namespace std;

int coinChange(int givenSize, vector<int> &arr, vector<int> &dp, int tar) {
    
    dp[0] = 1;
    
    for (int idx=0; idx<givenSize; idx++) {
        
        int val = arr[idx];
        
        for (int innerIdx=val; innerIdx<=tar; innerIdx++) {
            
            int diff = innerIdx-val;
          
            dp[innerIdx] += dp[diff];
            
        }
    }
    
    return dp[tar];
}


int main() {
    
    int givenSize;
    
    cin >> givenSize;
    
    vector<int> arr(givenSize,0);
    
    for (int idx=0; idx<givenSize; idx++) {
        
        int val;
        
        cin >> val;
        
        arr[idx] = val;
    }
    
    int tar;
    
    cin >> tar;
    
    vector<int> dp(tar+1,0);
    
    cout << coinChange(givenSize,arr,dp,tar);

    return 0;

}