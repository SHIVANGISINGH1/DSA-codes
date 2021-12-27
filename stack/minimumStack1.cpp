// in this we have to calculate a min value from the stack using a min stack

#include<iostream>
#include <string>
#include <stack>
using namespace std;
class MinStack {


stack<int> allData;
stack<int> minData;


public:
int size() {
    allData.size();
}

public:
  void push(int val) {
    allData.push(val);
    if (minData.size()>0) {
        if (minData.top()>=val) {
            minData.push(val);
        }
        
    }
    else minData.push(val);
  }

public:
  int pop() {
    int val = allData.top();
    allData.pop();
    if(minData.size()>0 && minData.top() == val) {
        minData.pop();
    }
    return val;
  }

public:
  int top() {
    return allData.top();
  }

public:
  int min() {
    return minData.top();
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