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

//Display function
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


//Height function
int height(Node* node)
{
  return node == nullptr ? -1 : max(height(node->left), height(node->right)) + 1;
}


class bst {
    public:
    bool isbst;
    int min;
    int max;
};

bst Bst(Node* node) {
    
    if (node == NULL) {
        bst bp;
        bp.isbst = true;
        bp.min = INT_MAX;
        bp.max = INT_MIN;
        
        return bp;
    }
    bst leftsubtree = Bst(node->left);
    bst rightsubtree = Bst(node->right);
    
    bst np;
    np.isbst = (leftsubtree.isbst && rightsubtree.isbst) && (node->data >= leftsubtree.max && node->data <= rightsubtree.min);
    np.max = max(node->data , max(leftsubtree.max,rightsubtree.max));
    np.min = min(node->data , max(leftsubtree.min,rightsubtree.min));
    
    return np;
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
  if (r.isbst == 1)
    cout << "true";
  else
    cout << "false";



}