#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;

void mergeOverlappingIntervals(vector<vector<int>>& arr) {

//   1 12
//   1 4
//   4 6
    sort(arr.begin(), arr.end());
    
    stack<int> s1;
    
    s1.push(arr[0][0]);
    s1.push(arr[0][1]);
    
    for (int rIdx=1; rIdx<arr.size(); rIdx++) {
        
        if (arr[rIdx][0]<=s1.top() && arr[rIdx][1]>=s1.top()) {
            s1.pop();
            s1.push(arr[rIdx][1]);
        }
        
        else if (arr[rIdx][0]<s1.top() && arr[rIdx][1]<=s1.top()) {
        continue;        
        }
        else {
            s1.push(arr[rIdx][0]);
            s1.push(arr[rIdx][1]);
        }
        
    }
    
    vector<vector<int>> ans;
    
    while(s1.size()>0) {
        vector<int> y;
        int a = s1.top(); // 30
        y.push_back(a); // 30
        s1.pop();
        int b = s1.top();
        y.push_back(b);
        s1.pop();
        ans.push_back(y);
    }
    
    for (int rIdx=ans.size()-1; rIdx>=0; rIdx--) {
        cout<<ans[rIdx][1]<<" "<<ans[rIdx][0]<<endl;
    }  

}


int main() {
    int n;
    cin >> n ;

    vector<vector<int>> arr( n, vector<int>(2) );



    // input
    for (int i = 0; i < n ; i++ ) {
        cin >> arr[i][0];
        cin >> arr[i][1];
    }


    mergeOverlappingIntervals(arr);

}