// here we have to calculate all the indexes of a given num so we will iterate till thate num using recursion and 
// we will go to next index and check if it is equal to our data then we will store it into our vector 

#include <iostream>
#include <vector>
using namespace std;

vector<int> ans;

vector<int> allIndex(vector<int>& arr, int idx, int data, int count)
{   
    if (idx == count)
    {
        return ans;
    }

    if (arr[idx] == data) // check 
    {
        ans.push_back(idx);
    }

    allIndex(arr, idx+1, data, count); // calling the fuction recursively for next index

    return ans; 
}


int main() 
{
    int numOfEle;

    cin >> numOfEle;

    vector<int> arr;

    for (int index = 0 ; index < numOfEle ; index++) 
    {
        int num;

        cin >> num;

        arr.push_back(num);
    }

    int data;

    cin >> data;

    vector<int> ans = allIndex(arr, 0, data, numOfEle);

    if (ans.size() == 0) 
    {
        cout << endl;
    }

    for (int ele : ans) 
    {
        cout << ele << endl;
    }

    return 0;
}