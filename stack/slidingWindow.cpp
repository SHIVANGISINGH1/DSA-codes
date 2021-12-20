// 2 4 13 1 9 8 6 5 7 12 18 k = 4
// 13 13 13 9 8 12 18 
// here we will calculate firstly next greater element to the right then for each ele we will check
// if its nge lies in the sliding window if yes then we will check till we get a ele whose nge 
// does not lie in the range that will be our ans 


#include <bits/stdc++.h>
#include <ctype.h>
using namespace std;

int main() 
{
    int size;

    cin >> size;

    vector<int> arr(size);

    for (int idx = 0; idx < size; idx++) 
    {
        cin >> arr[idx];
    }

    int windowSize;

    cin >> windowSize;
      
    vector<int> ngr(size,0);
    stack<int> Stack;

    Stack.push(size-1);
    ngr[size-1] = size;

    for (int idx=size-2; idx>=0; idx--)
    {
        while(Stack.size() >0 && arr[Stack.top()]<arr[idx]) 
        {
            Stack.pop();
        }

        if (Stack.size() == 0) ngr[idx] = size;
        else ngr[idx] = Stack.top();
    
        Stack.push(idx);
    }

    vector<int> ans(size-windowSize+1,0);
    int ptr2 = 0;

    for (int ptr1=0; ptr1<=size-windowSize; ptr1++)
    {   
        if (ptr2<ptr1) 
        {
            ptr2 = ptr1;
        }

        while(ngr[ptr2]<ptr1+windowSize)
        {
            ptr2 = ngr[ptr2];
        }
        
        ans[ptr1] = arr[ptr2];
    }

    for (int idx=0; idx<ans.size(); idx++)
    {
        cout<<ans[idx]<<endl;
    }

    return 0;
}