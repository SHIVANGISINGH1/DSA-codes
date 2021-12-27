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
      helperQ.push(data);
      
    while(mainQ.size()!=1) {
      int val = mainQ.front();
      helperQ.push(val);
      mainQ.pop();
    }
    mainQ.pop();
    while(helperQ.size()>0) {
        int val = helperQ.front();
        mainQ.push(val);
        helperQ.pop();
    }
  }

  int top() {
      return mainQ.front();
  }

  int pop() {
      int y = mainQ.front();
      mainQ.pop();
      return y;
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