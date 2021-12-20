#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>> n;
    
    int mat[n][n];
    
    for (int rIdx=0; rIdx<n; rIdx++) {
        string s;
        cin >> s;
        for (int cIdx=0; cIdx<n; cIdx++) {
            int val = s[cIdx] - '0';
            mat[rIdx][cIdx] = val;
        }
    }
    
    stack<int> s1;
    
    for (int it=0; it<n; it++) {
        s1.push(it);
    }
    
   //cout<<mat[3][2];
    while (s1.size()!=1) {
        int n1 = s1.top();
        s1.pop();
        int n2 = s1.top();
        s1.pop();
        
        if (mat[n1][n2] == 1) {
            s1.push(n2);
        }
        else {
            s1.push(n1);
        }
    }
    
    int ptAns = s1.top();

    bool flag1 = 0;
    bool flag2 = 0;
    for (int rIdx=0; rIdx<n; rIdx++) {
        if (rIdx!=ptAns && mat[rIdx][ptAns] != 1) {
            flag1 = 1;
        }
    }
    
    for (int cIdx=0; cIdx<n; cIdx++) {
        if (cIdx!=ptAns && mat[ptAns][cIdx] != 0) {
            flag2 = 1;
        }
    }
    
    if (flag1 == 1 || flag2 == 1) cout<<"none";
    else cout<<ptAns;
}