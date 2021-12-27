// In this also we need to give the minimum value in the stack but we need to use the contant space
#include<iostream>
#include <string>
#include <stack>

using namespace std;


class MinStack {
  stack<int> data;
  int minVal;


    public:
    int size() {
        return data.size();
    }

    public:
    void push(int val) {
    if (data.size() == 0) {
        minVal = val;
        data.push(val);
    }
    
    else if (val<=minVal) {
        
        data.push(val+val-minVal);
        minVal = val;
    }
    else {
        data.push(val);
    }
  }

public:
    int pop() {
    int y = data.top();
    data.pop();
    int minimum = minVal;
    if (y<=minimum) {
        minVal = 2*minimum - y;
        return minimum;
    }
    else 
    return y;
  }

    public:
    int top() {
    int y = data.top();
    if (y<=minVal) {
        return minVal;
    }
    else 
    return y;
  }

public:
    int min() {
        return minVal;
    }

};


int main() {
  MinStack st;

  string str;
  cin >> str;

  while (str != "quit") {

    if (str == "push") {
      int val;
      cin >> val;
      st.push(val);
    }
    else if (str == "pop") {
      int val = st.pop();
      if (val != -1) {
        cout << val << endl;
      }
    }
    else if (str == "top") {
      int val = st.top();
      if (val != -1) {
        cout << val << endl;
      }
    }
    else if (str == "size") {
      cout << st.size() << endl;
    }
    else if (str == "min" ) {
      int val = st.min();
      if (val != -1) {
        cout << val << endl;
      }
    }

    cin >> str;

  }

}