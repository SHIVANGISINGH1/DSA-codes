#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
  int data = 0;
  Node* left = nullptr;
  Node* right = nullptr;
  Node(int data)
  {
    this->data = data;
  }
};

class Pair {
public:
  Node* node = nullptr;
  int state = 0;

  Pair(Node* node, int state) {
    this->node = node;
    this->state = state;
  }
};

int idx = 0;
Node* constructTree(vector<int>& arr)
{

  if (idx == arr.size() || arr[idx] == -1)
  {
    idx++;
    return nullptr;
  }
  Node* node = new Node(arr[idx++]);
  node->left = constructTree(arr);
  node->right = constructTree(arr);
  return node;
}


void display(Node* node)
{
  if (node == nullptr)
    return;
  string str = "";
  str += node->left != nullptr ? to_string(node->left->data) : ".";
  str += " <- " + to_string(node->data) + " -> ";
  str += node->right != nullptr ? to_string(node->right->data) : ".";
  cout << str << endl;

  display(node->left);
  display(node->right);
}



int height(Node* node)
{
  return node == nullptr ? -1 : max(height(node->left), height(node->right)) + 1;
}

class bst {
public:
  bool isbst = false;
  int max = 0;
  int min = 0;
  Node* root = nullptr;
  int size = 0;
};

bst Bst(Node* node) {

  if (node == nullptr)
  {
    bst bres;
    bres.isbst = true;
    bres.size = 0;
    bres.root = NULL;
    bres.max = INT_MIN;
    bres.min = INT_MAX;
    return bres;
  }
  bst l = Bst(node->left);
  bst r = Bst(node->right);

  bst ans;

  ans.max = max(node->data, max(l.max, r.max));
  ans.min = min(node->data, min(l.min, r.min));

  if (l.isbst == true && r.isbst == true && (l.max < node->data && r.min > node->data)) {
    ans.isbst = true;
  }

 
  if (ans.isbst) {
      ans.size = l.size + r.size + ans.size;
      ans.size += 1;
      ans.root = node;
  }else {
      ans.size = max(l.size,r.size);
      if (ans.size == l.size) ans.root = l.root;
      else ans.root = r.root;
  }
  
  
  return ans;
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

  Node* root = constructTree(arr);

  bst r = Bst(root);
  cout << r.root->data << "@" << r.size;



}