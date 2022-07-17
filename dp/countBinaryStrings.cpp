// 

#include<bits/stdc++.h>
using namespace std;

int main() {

    int n;

    cin >> n;

    int endZero = 1;
    int endOne = 1;
    int currZero = 0;
    int currOne = 0;

    for (int it=2; it<=n; it++) {
        currZero = endOne;
        currOne = endOne + endZero; 
        endOne = currOne; 
        endZero = currZero; 
    }

    cout << currOne + currZero;

    return 0;
}