// [6 2 5 4 5 1 6] -> 12 
// we need to find the area of largest rectangle formed by the array
// to solve this problem we need to find  
// To solve this we will calculate the smallest ele on the left and right for each ele and then calculate the max area

#include <bits/stdc++.h>
using namespace std;

vector<int> SEL(vector<int> arr)
{
    int n = arr.size();
    
    vector<int> ansLt(n,0);
    stack<int> s1;
    
    s1.push(0);
    ansLt[0] = -1;
    
    for (int idx=1; idx<n; idx++)
    {
        while (s1.size()>0 && arr[s1.top()]>=arr[idx])
        {
            s1.pop();
        }
        if (s1.size() == 0)
        {
            ansLt[idx] = -1;
        }
        else
        {
            ansLt[idx] = s1.top();
        }
        
        s1.push(idx);
    }
    
    return ansLt;
}

vector<int> SER(vector<int> arr)
{   
    int n = arr.size();
    vector<int> ansRt(n,0);
    stack<int> s2;
    
    ansRt[n-1] = n;
    s2.push(n-1);
    
    for (int idx=n-2; idx>=0; idx--)
    {
        while (s2.size()>0 && arr[s2.top()]>=arr[idx])
        {
            s2.pop();
        }
        if (s2.size() == 0)
        {
            ansRt[idx] = n;
        }
        else
        {
            ansRt[idx] = s2.top();
        }
        s2.push(idx);
    }
    
    return ansRt;
}


int main(int argc, char** argv)
{
  int n;
  cin >> n;

  vector<int>arr(n, 0);

  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  
  vector<int> lht = SEL(arr);
  vector<int> rht = SER(arr);
  
  int maxarea = 0;
  
  for (int idx=0; idx<n; idx++)
  {
      int ht = arr[idx];
      int wt = rht[idx] - lht[idx] - 1;
      
      int area = ht*wt;
      
      maxarea = max(maxarea,area);
  }
  
  cout<<maxarea;

  return 0;
}