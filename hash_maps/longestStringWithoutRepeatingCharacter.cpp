#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        unordered_map<char,int> mp;
        
        int a_ptr = 0;
        int b_ptr = 0;
        int mx = 0;
        while(b_ptr < s.size()) {
            
            if (mp.count(s[b_ptr]) > 0) {
                mp.erase(s[a_ptr]);
                a_ptr++;
            }
            else {
                mp.insert({s[b_ptr] , 1});
                int len = mp.size();
                mx = max(mx,len);
                b_ptr++;
            }
        }
        return mx;
        
    }
};