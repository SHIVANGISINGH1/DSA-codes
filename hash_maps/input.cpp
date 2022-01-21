#include<bits/stdc++.h>
#include"seperateChaining.cpp"
using namespace std;

int main() {
    ourmap<int> map;

    for (int i=0; i<10; i++) {
        char c = '0' + i;
        string key = "abc";
        key = key + c;
        map.insert(key,i+1);
        cout << map.getLoadFactor() << endl;
    }
    
    map.removekey("abc2");
    map.removekey("abc7");

    for (int i=0; i<10; i++) {
        char c = '0' + i;
        string key = "abc";
        key = key + c;
        cout << key << map.getValue(key) << endl;
    }
    cout << map.size() << endl;
}