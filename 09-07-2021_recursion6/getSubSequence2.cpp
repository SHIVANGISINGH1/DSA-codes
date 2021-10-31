// 2nd: Here we have used one parameter index in place of substr
// we will simply call index+1 till we reach the length of the string (base case)
// here we are using just one vector ans in which we will make our ans 
// we will just run a loop till the size of the ans string and add str[index] with ans[index from loop] 
// finally we will return our ans


#include<iostream>
#include<vector>
using namespace std;

vector<string> getSubSeq(string str,int idx)
{
    if (idx == str.size())
    {   
        string res = "";
        vector<string> base;
        
        base.push_back(res);
        
        return base;
    }

    vector<string> ans = getSubSeq(str,idx+1); // str,1 str,2 str,3 

    int Size = ans.size(); // 1 2 4

    for (int index = 0; index<Size; index++)
    {
        ans.push_back(str[idx] + ans[index]); // c+""= c // b+""= b b+c= bc // a+""=a a+c=ac a+b=ab a+bc=abc
    }

    return ans; // "",c,b,bc,a,ac,ab,abc
}


int main()
{
    string input;

    cin >> input;

    vector<string> ans = getSubSeq(input,0);

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