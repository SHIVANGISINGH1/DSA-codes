#include <bits/stdc++.h>
using namespace std;

// a*(b-c+d)/e


int prec(char ch) {
    if (ch == '+') return 1;
    if (ch == '-') return 1;
    if (ch == '/') return 2;
    else if (ch == '*') return 2;
}

string pre(char ch,string a, string b) {
    
    string opt(1,ch);
    if (ch == '+') return a + b + opt;
    if (ch == '-') return a + b + opt;
    if (ch == '/') return a + b + opt;
    else if (ch == '*') return a + b + opt;
}

string post(char ch,string a, string b) {
    
    string opt(1,ch);
    if (ch == '+') return opt + a + b;
    if (ch == '-') return opt +  a + b;
    if (ch == '/') return opt +  a + b;
    else if (ch == '*') return opt +  a + b;
}

// a*(b-c+d)/e


int main() {
  string str;
  getline(cin, str);
    
  stack<string> preS;
  stack<string> postS;
  stack<char> opt;
  
  
  for (int idx=0; idx<str.size(); idx++) {
    if (str[idx] == '(') {
        opt.push(str[idx]);//(
    }
      
    else if (str[idx] == ')') {
        while(preS.size() > 0 && postS.size() > 0 && opt.size()>0 && opt.top()!= '(') {
            char op1 = opt.top();
            opt.pop();
            
            string n2 = preS.top();
            preS.pop();
            
            string n1 = preS.top();
            preS.pop();
            
            string s = pre(op1,n1,n2);
            preS.push(s);
            
            string ne2 = postS.top();
            postS.pop();
            
            string ne1 = postS.top();
            postS.pop();
            
            string s2 = post(op1,ne1,ne2);
            postS.push(s2);
        }
        
        opt.pop();
    }
      
    else if (str[idx] == '+' || str[idx] == '-' || str[idx] == '*' || str[idx] == '/') {
        while(opt.size()>0 && opt.top() != '(' && prec(str[idx]) <= prec(opt.top())) {
            char op1 = opt.top();//-
            opt.pop();
            
            string n2 = preS.top(); //c
            preS.pop();
            
            string n1 = preS.top();//b
            preS.pop();
            
            string s = pre(op1,n1,n2);// -,b,c
            preS.push(s);
            
            string ne2 = postS.top();
            postS.pop();
            
            string ne1 = postS.top();
            postS.pop();
            
            string s2 = post(op1,ne1,ne2);
            postS.push(s2);
        }
        
        opt.push(str[idx]);//*(-
    }
      
    else if (str[idx] != ' ') {
        //cout<<str[idx];
        string s1(1,str[idx]);
        preS.push(s1);//abc
        postS.push(s1);//abc
    }
  }
  
if (opt.size() > 0) {
    while(opt.size()> 0) {
        char op1 = opt.top();
        opt.pop();
        
        string n2 = preS.top();
        preS.pop();
        
        string n1 = preS.top();
        preS.pop();
        
        string s = pre(op1,n1,n2);
        preS.push(s);
        
        string ne2 = postS.top();
        postS.pop();
        
        string ne1 = postS.top();
        postS.pop();
        
        string s2 = post(op1,ne1,ne2);
        postS.push(s2);
    }
  }
  
cout<<preS.top()<<endl;
cout<<postS.top();
  

return 0;
}