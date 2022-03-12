#include <iostream>
#include <queue>
using namespace std;

class MedianPriorityQueue {
public:
  priority_queue <int> left;
  priority_queue <int, vector<int>, greater<int>> right;
    
  void balance() {
      
    int diff = left.size() - right.size();
      
    if ( diff > 1) {
        int v = left.top();
        right.push(v);
        left.pop();
    }

    else if (diff == -2) {
        int v = right.top();
        left.push(v);
        right.pop();
    }
    
  }
  void push(int val) {
    
    if (right.size() > 0 && val > right.top()) {
        right.push(val);
    }
    else {
        left.push(val);
     
    }
    balance();
  }

  int pop() {
    
    int s1 = left.size();
    int s2 = right.size();
    int val = -1;
    
    if (size() == 0) {
        cout << "Underflow" << endl;
        return val;
    }
    if (s1 >= s2) {
        val = left.top();
        left.pop();
    }
    else {
        val = right.top();
        right.pop();
    }
    return val;
  }

  int top() {
        int s1 = left.size();
        int s2 = right.size();
        int val = -1;
        
        if (size() == 0) {
            cout << "Underflow" << endl;
            return val;
        }
        if (s1 >= s2) {
            val = left.top();
        }
        else {
            val = right.top();
        }
        return val;
      }

  int size() {
    int s = left.size() + right.size();
    return s;
  }
};

int main() {
  MedianPriorityQueue pq;

  string str;
  cin >> str;
  while (str != "quit") {
    if (str == "add") {
      int val;
      cin >> val;
      pq.push(val);
    }
    else if (str == "remove") {
      int val = pq.pop();
      if (val != -1) {
        cout << val << endl;
      }
    }
    else if (str == "peek") {
      int val = pq.top();
      if (val != -1) {
        cout << val << endl;
      }
    }
    else if (str == "size") {
      cout << pq.size() << endl;
    }
    cin >> str;
  }

  return 0;
}