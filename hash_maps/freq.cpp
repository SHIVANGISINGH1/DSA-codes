#include<iostream>
#include<string>
#include<unordered_map>

using namespace std;

char highFreqChar(string inp) {
    
    unordered_map<char , int> mp;
    
    for (int idx=0; idx<inp.size(); idx++) {
        if (mp.count(inp[idx]) > 0) {
            mp.at(inp[idx])++;
        } 
        else {
            mp.insert({inp[idx],1});
        }
    }
    
    unordered_map<char, int>::iterator it = mp.begin(); 
    int val = 0;
    char ans;
    while(it!=mp.end()) {
        
        if (it->first > val) {
            val = it->second;
            ans = it->first;
        }
        
        it++;
    }
    
    return ans;
}

int main() {
    
    string inp;
    cin >> inp;
    
    cout << highFreqChar(inp);
}