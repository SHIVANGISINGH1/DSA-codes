// [2 5 9 3 1 12 6 8 7] = 1 2 3 1 1 6 1 2 1
// basicaaly we need to print the value greater than the curr value on its left side
// and if it is not greater then print its index 
// for 2 print 1 for 5 no value on left greater then 5 then print 2 
// so to do this problem similar to the greatest ele on right we will find greatst ele on the left
// and if not found we will just add the index to the ans array

#include <bits/stdc++.h>
using namespace std;

void display(vector<int>arr) 
{
	for (int idx = arr.size()-1; idx >=0; idx--)
	{
		cout << arr[idx] << endl;
	}
}

vector<int> solve(vector<int>arr)
{
    
    vector<int> ans;
    stack<int> Stack;
    int count;

    Stack.push(0);
    ans.push_back(1);

    for (int idx=1; idx<arr.size(); idx++)
    {   
        
        while(Stack.size()>0 && arr[Stack.top()]<=arr[idx])
        {
            Stack.pop();
        }

        if (Stack.empty())
        {
            ans.push_back(idx+1);
        
        }

        else
        {   
            ans.push_back(idx-Stack.top());
        }
            
        Stack.push(idx); 
    }

    return ans;
}


int main()
{
	int size;
	
	cin >> size;

	vector<int>arr(size, 0);

	for (int idx = 0; idx < size; idx++)
	{
		cin >> arr[idx];
	}

	vector<int>span(size, 0);

	span = solve(arr);
	display(span);

	return 0;
}