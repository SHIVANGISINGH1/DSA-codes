// another approach
// with stack and 0(2n) time complexity 
// [2 5 9 3 1 12 6 8 7] = 5 9 12 12 -1 8 -1 
// we will simply add the last ele of array in the stack then traverse backwards and check if the 
// val at that index is smaller or greater then the top of stack if smaller then just push that ele in the ans array
// or pop till we get a greater ele at top if stack is empty then we will push just -1  

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
	stack<int> help;

	help.push(arr[arr.size()-1]);
	ans.push_back(-1);

	for (int idx=arr.size()-2; idx>=0; idx--)
	{  
		while(!help.empty() && help.top()<=arr[idx] )
		{
			help.pop(); 
		}

		if(help.empty())
		{
			ans.push_back(-1);
		}

		if (!help.empty() && help.top()>arr[idx] ) 
		{
			ans.push_back(help.top());
		}
			
		help.push(arr[idx]); 
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

	vector<int>nge(size, 0);

	nge = solve(arr);
	display(nge);

	return 0;
}