// This is a question of forming target sum with the subsets with given array
// In this q we just have to return if it is possible to form the target sum with the subsets of array
// We will solve this question using a matrix 
// firstly we will fill the matrix with false values
// what are we trying to do : for checking if we can get the target sum we will check for each subset 
// if they can form the sum individually or with the help of previous ele 
// if we get our target sum we return yes

#include <iostream>
#include <vector>
using namespace std;

bool targetSumSubset(int givenSize, vector<int> arr, int tar) {

    int row = tar + 1;
    int col = givenSize + 1;
    
    vector<vector<bool>> dp(row, vector<bool>(col,false));
    
    for (int rIdx=0; rIdx<row; rIdx++) {
        dp[rIdx][0] = true;
    }
    
    for (int cIdx=1; cIdx<col; cIdx++) {
        dp[0][cIdx] = false;
    }
    
    for (int rIdx=1; rIdx<row; rIdx++) {
        
        int val = arr[rIdx-1];
        
        for (int cIdx=1; cIdx<col; cIdx++) {
            
            
            if (dp[rIdx-1][cIdx] == true) {
                dp[rIdx][cIdx] = true;
            }
            else {
                int diff = cIdx - val;
                if (diff >= 0) {
                    if (dp[rIdx-1][diff] == true) {
                        dp[rIdx][cIdx] = true;
                    }
                    else {
                        dp[rIdx][cIdx] = false;
                    }
                }
                else{
                    dp[rIdx][cIdx] = false;
                }
            }
        }
        
        
    }
    
    return dp[row-1][col-1];
}


int main() {

    int givenSize;

    cin >> givenSize;

    vector<int> arr(givenSize);

    for (int i = 0; i < arr.size(); i++) {
        cin >> arr[i];
    }

    int tar;

    cin >> tar;

    int val = targetSumSubset(givenSize, arr, tar);

    if (val == 1) {
        cout << "true";
    }
    else {
        cout << "false";
    }

    return 0;
}