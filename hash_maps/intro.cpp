// implement using inbuilt unordered maps

#include<iostream>
#include<unordered_map>
using namespace std;

int main() {
    unordered_map<string, int> mp;
    
    // insert
    pair<string,int> p("abc" , 1);

    mp.insert(p);

    mp["def"] = 2;

    mp.insert({"ghi" , 3});

    //access

    cout << mp["abc"] << endl;
    cout << mp.at("def") << endl;

    if (mp.count("k") == 1)
    cout << mp["k"] << endl;

    // size;

    cout << mp.size();

    // erase

    mp.erase("k");

    cout << mp.size();
}