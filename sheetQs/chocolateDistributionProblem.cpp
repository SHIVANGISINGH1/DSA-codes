#include <bits/stdc++.h>
using namespace std;


class Solution{
    public:
    
    long long findMinDiff(vector<long long> a, long long n, long long m){
    //code

        sort(a.begin(), a.end());
        long long ptr= m-1;
        long long ans = 1000000000;
        
        for (long long idx=0; idx<n && ptr<n; idx++, ptr=idx+m-1) {
            
            ans = min(ans,a[ptr]-a[idx]);
        }
        
        return ans;
    }   
};