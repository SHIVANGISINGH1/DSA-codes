// 

#include<bits/stdc++.h>
using namespace std;

int main() {

    int n;

    cin >> n;

    long int endZero = 1;
    long int endOne = 1;
    long int currZero = 0;
    long int currOne = 0;

    for (int it=2; it<=n; it++) {
        currZero = endOne;
        currOne = endOne + endZero; 
        endOne = currOne; 
        endZero = currZero; 
    }

    long int ans = currZero + currOne;

    cout << ans*ans;

    return 0;
}