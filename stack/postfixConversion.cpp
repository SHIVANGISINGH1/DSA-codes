#include <bits/stdc++.h>
using namespace std;

int prec(char opt) {
    if (opt == '+') return 1;
    else if (opt == '-') return 1;
    else if (opt == '*') return 2;
    else if (opt == '/') return 2;
}

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

string preCalc(char opt,string a,string b) {
    string op1(1,opt);
    if (opt == '+') return op1 + a + b;
    else if (opt == '/') return op1 + a + b;
    else if (opt == '*') return op1 + a + b;
    else if (opt == '-') return op1 + a + b;
}


int main() {
    string str;

    getline(cin, str);

    stack<string> in;
    stack<string> pre;
    stack<int> val;
    stack<char> opt;

    for (int idx=0; idx<str.size(); idx++) {
        
        if (str[idx] == '+' || str[idx] == '-' || str[idx] == '*' || str[idx] == '/') {
                
                char op = str[idx];
                
                int v2 = val.top();
                val.pop();
                
                int v1 = val.top();
                val.pop();
                
                int out = calc(op,v1,v2);
                val.push(out);
                
                string s2 = in.top();
                in.pop();
                
                string s1 = in.top();
                in.pop();
                
                string outi = inCalc(op,s1,s2);
                in.push(outi);
                
                string se2 = pre.top();
                pre.pop();
                
                string se1 = pre.top();
                pre.pop();
                
                string outp = preCalc(op,se1,se2);
                pre.push(outp); 
            
        }   
        
        else if (str[idx] != ' ') {
            string s1(1,str[idx]);
            int n = str[idx] - '0';
            val.push(n);
            in.push(s1);
            pre.push(s1);
        }
    }

    cout<< val.top()<<endl;
    cout<< in.top()<<endl;
    cout<< pre.top()<<endl;

    return 0;
}