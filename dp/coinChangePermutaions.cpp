// Similar to the previous coin change combination problem but here we have to print all the permuations
// of the sum so instead of taking one number from the array at the time, we will check for all the
// array to calculate the permutations

#include<iostream>
#include<vector>
using namespace std;

int coinChangePerm(vector<int>& arr, vector<int>& dp) {

    dp[0] = 1;

    for (int dpIdx=1; dpIdx<dp.size(); dpIdx++) {

        for (int arrIdx=0; arrIdx<arr.size(); arrIdx++) {

            if (arr[arrIdx] <= dpIdx) {
                int diff = dpIdx-arr[arrIdx];
               
                dp[dpIdx] += dp[diff];
                
            }
        }
    }

    return dp[dp.size()-1];
}

int main() {
    
    int inpSize;

    cin >> inpSize;

    vector<int> arr(inpSize);

    for (int idx=0; idx<inpSize; idx++) {
        
        int num;
        
        cin >> num;
        
        arr[idx] = num;
    }

    int target;

    cin >> target;

    vector<int> dp(target+1);

    cout << coinChangePerm(arr,dp);
        
    return 0;
}