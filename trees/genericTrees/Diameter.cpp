#include<bits/stdc++.h>
using namespace std;

class Node {
public:
  int data;
  vector<Node*>children;
};

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
int dia = 0;
int diameter(Node* root) {

    int dch = -1;
    int sdc = -1;
    for (int idx=0; idx<root->children.size(); idx++) {
        int height = diameter(root->children[idx]);
        
        if (height>dch) {
            sdc = dch;
            dch = height;
        }
        else if (height>sdc) {
            sdc = height;
        }
    }
    
    if (dch + sdc + 2>dia) {
        dia = dch + sdc + 2;
    }
    
    dch += 1;
    return dch;
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
  dia = 0;
  diameter(root);
  cout << dia << endl;

}