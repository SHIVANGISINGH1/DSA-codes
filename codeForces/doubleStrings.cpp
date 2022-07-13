#include<bits/stdc++.h>
using namespace std;

void calc(vector<string> &vt) {

    string ans = "";
    int size = vt.size();
    
    for (int idx1=0; idx1<size; idx1++) {

        string str1 = vt[idx1];
        bool flag = 0;

        for (int idx2=0; idx2<size; idx2++) {
            string str2 = vt[idx2]; 
            if (idx2 == idx1 || str2.size() > str1.size()) continue;

            for (int idx3=0; idx3<size; idx3++) {
                string str3 = vt[idx3]; 
                if (idx3 == idx1 || str3.size() > str2.size()) continue;

                
                string check1 = str2 + str3; 
                string check2 = str3 + str2;
               

                if (check1 == str1 || check2 == str1) {
                    flag = 1;
                    ans += "1";
                    break;
                }
            }

            if (flag == 1) break;
        }

        if (flag == 0) {
            ans += "0";
        }
    }

    cout << ans << endl;
}


int main() {

    int testCases;

    cin >> testCases;

    while(testCases--) {

        int length;

        cin >> length;
        
        vector<string> vt(length);

        for (int idx=0; idx<length; idx++) {
            
            string s;
            cin >> s;

            vt[idx] = s;
        }

        calc(vt);
    }
}