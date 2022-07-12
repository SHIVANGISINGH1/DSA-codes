#include<bits/stdc++.h>
using namespace std;

int output(string s , int n)
{
    //n  3+1+1 = 5
//3
    int ans=0;

    vector<int> store(26,0);

    for(int idx= 0 ; idx< n ; idx++)
    {   
        store[s[idx]-65]++;
    }
    //2 3 1 0 4
    int count = 0 ;    // 1 2   1
    

    for(int idx = 0 ; idx<store.size() ; idx++)           
    {
        if(store[idx]>1)
        {
            ans+=store[idx];   //2
            count++;
        }

        else if (store[idx]==1)
        {
            ans+=2;  
        }
    }
    //cout<<ans<<endl;
    //cout<<count<<endl;
    return ans+count;
}

int main()
{
    int t;

    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;

        string s;
        cin>>s;

        cout<<output(s , n)<<endl;


    }

    return 0;
}