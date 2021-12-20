// 2 + 6 * 4 / 8 - 3
//  2+ (5-3*6/2)
// here we are evaluating an infix expression 
// we will follow the preference rule 

#include <bits/stdc++.h>
#include <ctype.h>
using namespace std;

int pred(char opt) {

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


int main() {

    string str;

    getline(cin, str);


    stack<int> num;
    stack<char> optr;
  
    for (int idx=0; idx<str.size(); idx++) {

      if (str[idx] == '(') {
          optr.push(str[idx]);
    }
      
    else if (str[idx] == ')') {

        while(optr.size()>0 && optr.top()!='(') {

            char op = optr.top();
            optr.pop();
            int val2 = num.top();
            num.pop();
            int val1 = num.top();
            num.pop();
            int ans = calc(op,val1,val2);
            num.push(ans);
        }
          
          optr.pop();
    }
      
    else if (str[idx] == '+' || str[idx] == '-' || str[idx] == '*' || str[idx] == '/') {

        while(optr.size()>0 && optr.top() != '(' && pred(str[idx]) <= pred(optr.top())) { 
              
            char op = optr.top();
            optr.pop();
            int val2 = num.top();
            num.pop();
            int val1 = num.top();
            num.pop();
            
            int ans = calc(op,val1,val2); 
            num.push(ans);
        }
          
        optr.push(str[idx]); 
    }
      
        else if (str[idx] != ' ') {
            int n = str[idx] - '0';
            num.push(n);
        }
    }
  
  
  
    if (optr.size()>0) {

        while(optr.size()>0) {
          
            char op = optr.top(); 
            optr.pop();
            int val2 = num.top(); // 3
            num.pop();
            int val1 = num.top(); // 5 
            num.pop();
            
            int ans = calc(op,val1,val2);
            num.push(ans);
        }
    }
    cout<<num.top();

  return 0;
}