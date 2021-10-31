// here we are given a number from where we have to reach the end stair(0) 
// you can do only 1 2 and 3 jumps
// so if our num is 3 the possiblities are
// from 3->2->1->0 jumps are 1 1 1
// from 3->2->0 jumps are 1 2
// from 3->1->0 jumps are 2 1
// from 3->0 jumps are 3
// so from this tree we will take 3 paths for 1 jump 2 jump and 3 jump and we will call the function and add 1 2 and 3 in our ans


#include<iostream>
#include<vector>
using namespace std;

vector<string> stairPath(int num)
{   
    if (num == 0)
    {
        string empty = "";
        vector<string> baseCase;

        baseCase.push_back(empty);

        return baseCase;
    }

    vector<string> ans ;
    
    vector<string> path1 = stairPath(num-1);   // call for num-1

    int Size = path1.size();
    
    for (int idx=0; idx<Size; idx++)   // adding 1 to our ans
    {
        ans.push_back("1" + path1[idx]);    
    }
    

    if (num-2>=0)   // for 2 jumps
    {
        vector<string> path2 = stairPath(num-2);   // call for num-2

        int Size = path2.size();
        
        for (int idx=0; idx<Size; idx++)   // adding 2 to our ans
        {
            ans.push_back("2" + path2[idx]);    
        }
    }
    
    
    if (num-3>=0)
    {
        vector<string> path3 = stairPath(num-3);  // call for num-3
        
        int Size = path3.size();
        
        for (int idx=0; idx<Size; idx++)  // addng 3 to our ans
        {
            ans.push_back("3" + path3[idx]);    
        }
    }
    

    return ans;
}


int main()
{
    int num;

    cin >> num;

    vector<string> ans = stairPath(num);

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