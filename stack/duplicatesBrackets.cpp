// In this problem we need to tell if the given expression have any duplicates bracket or not
// our approach will be simple first add everything from opening bracket and the expression in the stack
// then on encountering closing bracket we will remove the entire expression 
// like (a+b = ) => empty repeat this and if you encouter just a opening bracket means you had duplicates
// eg ((a+b)) => (( a+b => encouter ) => start poping till ( = again encouter ) => now you have no expression just a opening means you had duplactes
 
#include<bits/stdc++.h>
using namespace std;

bool brackets(string input)
{   
    stack<char> s;
    int count=0;

    for (int idx=0; idx<input.size(); idx++)
    {   
        if (input[idx] == ')')
        {   
            if(s.top() == '(')
            return 1;
            else 
            {   while(s.top() != '(')
                {
                    s.pop(); // b+a d+c
                }
                
                s.pop(); 
            }
        }
        else
        {
            s.push(input[idx]); // (a+b)+((c+d))
        }
    }
    
    return 0;
}

int main() 
{
    string input;

    getline(cin,input);
    
    if (brackets(input) == 0)
    cout<<"false";
    else
    cout<<"true";
}