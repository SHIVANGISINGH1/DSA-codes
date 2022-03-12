#include <bits/stdc++.h>
using namespace std;

int sortK(int arr[], int n, int k) {
   
   priority_queue<int> q;
   
   for (int idx=0; idx<n; idx++) {
       
       if (idx<=k) {
            q.push(-1 * arr[idx]);
       }
       else {
           int val = q.top();
           cout << -1 * val << endl;
           q.pop();
           q.push(-1 * arr[idx]);
       }
   }
    
    while(!q.empty()) {
        int val = q.top();
           cout << -1 * val << endl;
           q.pop();
    }
}

int main()
{
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0 ; i < n ; i++) {
    int data;
    cin >> data;
    arr[i] = data;
  }
  int k;
  cin >> k;
  sortK(arr, n, k);
  return 0;
}