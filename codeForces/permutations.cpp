#include<bits/stdc++.h>
using namespace std;
// 24 7 16 7
// 0 0 3 1

int main() {
    int t;
    cin >> t;
    while(t--) {
        int size;
        cin >> size;

        vector<int> arr(size);
        vector<int> freq(size+1,0);
        for (int idx=0; idx<size; idx++) {
            cin >> arr[idx];
            
            while(arr[idx] > size) {
                arr[idx] = arr[idx]/2;
            }
            freq[arr[idx]]++;
        }

        bool flag = 0;
        for (int idx=size; idx>0; idx--) {
            if (freq[idx] == 0) {
                flag = 1;
                break;
            }

            if (freq[idx] > 1) {
                int i = idx;
                int y = idx/2;
                freq[y] += y;
            }
        }

        if (flag == 1) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
}