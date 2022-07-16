// In this problem we can include fractions of wt too.
// we will follow the greedy approach here, we will calculate val/wt ratios, sort them and add max value we can
#include <bits/stdc++.h>
using namespace std;

void fractionalKnapsack(int n, vector<int> value, vector<int> weight, int cap) {
    
    vector<pair <double,int>> ratios;

    for (int idx=0; idx<n; idx++) {
        double val = (1.0 * value[idx]);
        val = val/weight[idx];

        ratios.push_back(make_pair(val,weight[idx]));
    }

    sort(ratios.begin(), ratios.end());

    double ans = 0;
    
    for (int idx=n-1; idx>=0; idx--) {

        if (cap == 0) break;

        double rat = ratios[idx].first;
        int wt = ratios[idx].second;
        int wtUsed = 0;
        

        if (wt <= cap) {
            wtUsed = wt;
            double wtAdd = rat*wtUsed;
            ans += wtAdd;
            cap = cap-wtUsed; 
        } else {
            wtUsed = cap;
            double wtAdd = rat*wtUsed;
            ans += wtAdd;
            cap = cap-wtUsed;
        }
    }

    int check = (int)ans;
    check == ans ? cout << fixed << setprecision(1) << ans : cout << ans;
    
}

int main() {

    int n;
    cin >> n;

    vector<int> val(n);
    
    for (int i = 0; i < n; i++) {
        cin >> val[i];
    }

    vector<int> weight(n);
    
    for (int i = 0; i < n; i++) {
        cin >> weight[i];
    }

    int cap;
    cin >> cap;

    fractionalKnapsack(n, val, weight, cap);

    return 0;
}