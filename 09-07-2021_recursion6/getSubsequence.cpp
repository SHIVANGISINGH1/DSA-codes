// we are given a string abc we have to print "" c b bc a ac ab abc
// we will solve this problem using two approches 
// 1st - we will pass the substring(1) of the given string and when its empty (base case) we will return an empty string
// to this we will first add "" and then the first character of string at that time
// this we will push_back in our ans and at the end return ans


#include<iostream>
#include<vector>
using namespace std;

vector<string> getSubSequence(string str)
{
    
    if (str.size()==0)
    {   
        string empty = "";
        vector<string> baseCase;

        baseCase.push_back(empty);

        return baseCase;
    }

    vector<string> ans;

    char get = str[0]; // c b a

    vector<string> store = getSubSequence(str.substr(1)); // "" // "" c // "" c b bc // "" c b bc a ac ab abc

    int Size = store.size(); // 1 2 4
        
    for (int idx=0; idx<Size; idx++)
    {
        ans.push_back("" + store[idx]); // ""+""= "" // ""+"" ""+c = "" c // ""+"" ""+c ""+b ""+bc = "" c b bc
    }

    for (int idx=0; idx<Size; idx++)
    {
        ans.push_back(get + store[idx]); // c+""= c // b+"" b+c = b bc // a+"" a+c a+b a+bc = a ac ab abc
    }

    return ans ;
}

int main()
{
    string input;

    cin >> input;

    vector<string> ans = getSubSequence(input);

    int index = 0;

    cout << '[';

    for (string str : ans)
    {
        if (index != ans.size() - 1)
        {
            cout << str << ", ";
        }
        else
        {
            cout << str;
        }
        index++;
    }

    cout << ']';

    return 0;
}