#include <iostream>
#include <exception>
#include <stack>
using namespace std;

class StackToQueueAdapter {
public:
  stack<int> mainS;
  stack<int> helperS;

  int size() {
    mainS.size();
  }

  void add(int data) {
    mainS.push(data);
  }

  int peek() {
    
    if (mainS.size() == 0 && helperS.size() == 0) {
        cout << "Queue underflow" << endl;
        return -1;
    }
    while(mainS.size() > 0) {
       int y = mainS.top();
        helperS.push(y);
        mainS.pop();
    } 
    int ans = helperS.top();
    
    while(helperS.size() > 0) {
       int y = helperS.top();
        mainS.push(y);
        helperS.pop();
    }
    return ans;
  }

  int remove() {
      if (mainS.size() == 0 && helperS.size() == 0) {
        cout << "Queue underflow" << endl;
        return -1;
    }
    while(mainS.size() > 0) {
       int y = mainS.top();
        helperS.push(y);
        mainS.pop();
    } 
    int ans = helperS.top();
    helperS.pop();
    while(helperS.size() > 0) {
       int y = helperS.top();
        mainS.push(y);
        helperS.pop();
    }
    return ans;
  }
};

int main() {
  StackToQueueAdapter q;
  string str;
  cin >> str;

  while (str != "quit") {
    if (str == "add") {
      int val;
      cin >> val;
      q.add(val);
    }
    else if (str == "remove") {
      int val = q.remove();
      if (val != -1) {
        cout << val << endl;
      }
    }
    else if (str == "peek") {
      int val = q.peek();
      if (val != -1) {
        cout << val << endl;
      }
    }
    else if (str == "size") {
      cout << q.size() << endl;
    }
    cin >> str;
  }
  return 0;
}