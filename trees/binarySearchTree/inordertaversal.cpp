#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

class Node {
public:
  int data;
  Node* left = nullptr;
  Node* right = nullptr;
  Node (int data)
  {
    this->data = data;
  }
};

class Pair {
  Node* node = nullptr;
  int state = 0;

  Pair(Node* node, int state) {
    this->node = node;
    this->state = state;
  }
};

Node* construct(vector<int>& arr) {
  Node* root = new Node(arr[0]);
  pair<Node*, int> p = {root, 1};

  stack<pair<Node*, int>> st;
  st.push(p);

  int idx = 1;
  while (!st.empty()) {
    if (st.top().second == 1) {
      st.top().second++;
      if (arr[idx] != -1) {
        st.top().first->left = new Node(arr[idx]);
        pair<Node*, int> lp = {st.top().first->left, 1};
        st.push(lp);
      }
      else {
        st.top().first->left = nullptr;
      }
      idx++;
    }
    else if (st.top().second == 2) {
      st.top().second++;
      if (arr[idx] != -1) {
        st.top().first->right = new Node(arr[idx]);
        pair<Node*, int> rp = {st.top().first->right, 1};
        st.push(rp);
      } else {
        st.top().first->right = nullptr;
      }
      idx++;
    }
    else {
      st.pop();
    }

  }
  return root;
}

class ITpair {
    public:
    Node* node;
    int state;
    //ITpair() {};
    ITpair(Node* node, int state) {
        this->node = node;
        this->state = state;
    }
};

void inorderTraversal(Node* root) {
    stack<ITpair> st;

    ITpair it(root,1);

    st.push(it);

    while(st.size() > 0) {

        Node* node = st.top().node;

        if (st.top().state == 1) {
            st.top().state++;

            if (node->left != NULL) {
                st.push({node->left,1});
            }
        } 
        else if (st.top().state == 2) {
            st.top().state++;

            if (node->right != NULL) {
                st.push({node->right,1});
            }

            cout << node->data << " ";
        }
        else {
            st.pop();
        }
    }
}


int main() {
  int n;
  cin >> n;
  vector<int> arr(n, 0);

  for (int i = 0; i < n; i++) {
    string tmp;
    cin >> tmp;
    if (tmp == "n") {
      arr[i] = -1;
    } else {
      arr[i] = stoi(tmp);
    }
  }

  Node* root = construct(arr);
  inorderTraversal(root);
  
 
}