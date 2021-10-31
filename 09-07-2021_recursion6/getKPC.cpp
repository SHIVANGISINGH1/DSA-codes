// in this we have to print a keypad format where we are given keyMap 
// we will go recursively and iterate by idx+1 and return when index is equal to string size 
// we will store the string at that index and run two nested for loops
// In 1 we are iterating till string size at that index
// in inner loop we will run till store vector size 
// v + "" w + "" x + "" then t+v t+w t+x u+v u+w u+x = tv tw tx uv uw ux


#include<iostream>
#include<vector>
using namespace std;

string keyMap[10]= {".;","abc","def","ghi","jkl","mno","pqrs","tu","vwx","yz"};

vector<string> kpc(string str,int idx)
{   
    if (idx == str.size())
    {
        string empty = "";
        vector<string> baseCase;

        baseCase.push_back(empty);

        return baseCase;
    }
    
    int digit = str[idx] - '0'; // 7 8
    string key = keyMap[digit]; // tu vwx
    
    vector<string> ans;
    
    vector<string> store = kpc(str,idx+1); // 78,1  78,2 // "" 
    
    int Size = store.size(); // 1 // 3
    
    for (int idx1=0; idx1<key.size(); idx1++) //3 // 2
    {   
        for (int idx2=0; idx2<Size; idx2++) // 1 // 4
        {
            ans.push_back(key[idx1] + store[idx2]);  // v+"" w+"" x+"" = v w x //  tv tw tz  uv uw uz  
        }
    }

    return ans;
}


int main()
{
    string inputString;

    cin >> inputString;

    vector<string> ans = kpc(inputString,0);

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