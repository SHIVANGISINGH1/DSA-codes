#include<bits/stdc++.h>
using namespace std;

class Node {
public:
  int data;
  vector<Node*>children;
};

void iterativePreAndPostOrder(Node* node) {
  stack<pair<Node*,int>> st;
  
  st.push({node,-1});
  string pre = "";
  string post = "";
  
  while(st.size() > 0) {
      
      Node* n = st.top().first;
      int val = n->data;
      string s = to_string(val);
      if (st.top().second == -1) {
          
          pre = pre + s + " ";
          st.top().second += 1;
      }
      else if (st.top().second == n->children.size()) {
          
          post = post + s + " ";
          st.pop();
      }
      else {
            int idx = st.top().second;
            st.top().second += 1;
            st.push({n->children[idx],-1});
      }
      
  }
  
  cout << pre << endl;
  cout << post;
}

Node* construct(vector<int>& arr) {
  Node* root = nullptr;

  stack <Node*> st;
  for (int i = 0; i < arr.size(); i++) {
    if (arr[i] == -1) {
      st.pop();
    } else {
      Node* t = new Node();
      t->data = arr[i];

      if (st.size() > 0) {
        st.top()->children.push_back(t);
      } else {
        root = t;
      }
      st.push(t);
    }
  }
  return root;
}

int main() {
  int n, x;
  cin >> n;
  vector<int>arr;
  for (int i = 0; i < n; i++) {
    cin >> x;
    arr.push_back(x);
  }
  Node* root = construct(arr);
  iterativePreAndPostOrder(root);
}