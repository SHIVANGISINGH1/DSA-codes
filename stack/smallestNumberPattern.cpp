#include<iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
    string str;

    cin >> str;

    int num = 1;
    stack<int> s1;
    // i i d d d
    // 1 2 3 4 5  
    for (int idx=0; idx<str.size(); idx++) {
        if (str[idx] == 'd') {
            s1.push(num);
            num+=1;
        }
        else {
            
            s1.push(num);
            while(s1.size()>0) {
                cout<<s1.top();
                s1.pop();
            }
            num+=1;
        }
    }

    s1.push(num);

    while(s1.size()>0){
        cout<<s1.top();
        s1.pop();
    }

}