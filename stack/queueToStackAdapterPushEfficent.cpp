// you have to implement stack using queues and it is push efficient

#include <iostream>
#include <exception>
#include <queue>
using namespace std;

class QueueToStackAdapter {
public:
  queue<int> mainQ;
  queue<int> helperQ;

  int size() {
    return mainQ.size(); 
  }

  void push(int data) {
    mainQ.push(data);
  }

  int top() {
    while(mainQ.size()!=1) {
        int val = mainQ.front();
        helperQ.push(val);
        mainQ.pop();
    }
    int ans = mainQ.front();
    helperQ.push(ans);
    mainQ.pop();
    
    while(helperQ.size()>0) {
        int val = helperQ.front();
        mainQ.push(val);
        helperQ.pop();
    }
    return ans;
  }

  int pop() {
     
    while(mainQ.size()!=1) {
    int val = mainQ.front();
    helperQ.push(val);
    mainQ.pop();
    }
    int ans = mainQ.front();
    mainQ.pop();
    
    while(helperQ.size()>0) {
        int val = helperQ.front();
        mainQ.push(val);
        helperQ.pop();
    }
    return ans;

  }
};

int main() {
  QueueToStackAdapter st;
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
    cin >> str;
  }
  return 0;
}