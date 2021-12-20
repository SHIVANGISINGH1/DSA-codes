#include <bits/stdc++.h>
using namespace std;



int calc(char opt,int a,int b) {
    if (opt == '+') return a + b;
    else if (opt == '-') return a - b;
    else if (opt == '*') return a * b;
    else if (opt == '/') return a / b;
}

string inCalc(char opt,string a,string b) {
    string op1(1,opt);
    string op2(1,'(');
    string op3(1,')');
    if (opt == '+') return op2 + a + op1 + b + op3;
    else if (opt == '/') return op2 + a + op1 + b + op3;
    else if (opt == '*') return op2 + a + op1 + b + op3;
    else if (opt == '-') return op2 + a + op1 + b + op3;
}

string postCalc(char opt,string a,string b) {
    string op1(1,opt);
    if (opt == '+') return  a + b + op1;
    else if (opt == '/') return a + b  + op1 ;
    else if (opt == '*') return  a + b + op1 ;
    else if (opt == '-') return a + b + op1 ;
}

int main() {
    string str;
    
    cin >> str;
    
    stack<string> in;
    stack<string> post;
    stack<int> val;
    
    for (int idx=str.size()-1; idx>=0; idx--) {
        if (str[idx] == '+' || str[idx] == '-' || str[idx] == '*' || str[idx] == '/') {
             
            char op = str[idx];
            
            int v1 = val.top();
            val.pop();// 24
            
            int v2 = val.top();
            val.pop();// 8
            
            int out = calc(op,v1,v2);//24
            val.push(out);
            
            string s1 = in.top();
            in.pop();
            
            string s2 = in.top();
            in.pop();
            
            string outi = inCalc(op,s1,s2);
            in.push(outi);
            
            string se1 = post.top();
            post.pop();
            
            string se2 = post.top();
            post.pop();
            
            string outp = postCalc(op,se1,se2);
            post.push(outp); 
          
      }   
      
      else {
          string s1(1,str[idx]);
          int n = str[idx] - '0';
          val.push(n);
          in.push(s1);
          post.push(s1);
      }
}
    
    cout<<val.top()<<endl;
    cout<<in.top()<<endl;
    cout<<post.top()<<endl;
    
    return 0;
}