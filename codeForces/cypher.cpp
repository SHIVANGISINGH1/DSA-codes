#include<bits/stdc++.h>
using namespace std;

int output(string s , int destination) {

    for (int idx=s.size()-1; idx>=0; idx--) {

        if (s[idx] == 'D') {
            if (destination == 9) {
                destination = 0; // 9
            }
            else {
                destination += 1; // 1
            }
        }

        else {
            if (destination == 0) {
                destination = 9;
            }
            else {
                destination -= 1;
            } 
        }

    }

    return destination;
}

int main() {

    int t;

    cin>>t;

    while(t--) {

        int n;
        
        cin>>n;

        int arr[n];

        for (int idx=0; idx<n; idx++) {

            int num;

            cin >> num;
            
            arr[idx] = num;

        }
        
        int ans[n];

        for (int idx=0; idx<n; idx++) {

            int op;
            cin >> op;

            string s;
            cin >> s;

            int i = output(s,arr[idx]);
            ans[idx] = i;
        }

        for (int idx=0; idx<n; idx++) {
            cout << ans[idx] << " ";
        }

        cout << endl;
    }

    return 0;
}