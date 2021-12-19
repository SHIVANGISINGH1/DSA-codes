// [(a + b) + {(c + d) * (e / f)}]   here we are just given a expression with brackets and we have to tell if 
// it a correct expression with proper opening and closing brackets 
// so we simply push opening brackets in the stack and if encouter closing bracket we would check if it is same bracket as closing if yes then pop it
// and if we encouter closing bracket and our stack is empty then simply return 0;
/* similar to valid paranthesis problem :: leetcode */

#include <bits/stdc++.h>
using namespace std;

bool brackets(string ip)
{
    stack<char> s;
    
    for (int idx=0; idx<ip.size(); idx++)
    {
        if (s.empty() && (ip[idx]=='}' || ip[idx]==']' || ip[idx] == ')')) return 0;
                
        if (ip[idx] == '(' || ip[idx]== '{' || ip[idx]== '[')
        {
            s.push(ip[idx]);//
        }
        
        if (ip[idx] == ')' && !s.empty())
        {
            if (s.top() == '(')
            s.pop();
        }
        
        if (ip[idx] == ']'&& !s.empty())
        {
            if (s.top() == '[')
            s.pop();
        }
        
        if (ip[idx] == '}' && !s.empty())
        {
            if (s.top() == '{')
            s.pop();
        }
        

    }

    if (s.empty()) return 1;
    return 0;
}


 
int main()
{
    //write your code
    string input;
    
    getline(cin,input);
    
    if(brackets(input)==0) cout<<"false";
    else cout<<"true";
    
    return 0;
}