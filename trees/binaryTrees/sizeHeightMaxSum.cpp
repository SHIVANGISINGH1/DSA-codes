#include<iostream>
#include<climits>
#include<string.h>
#include<vector>

using namespace std;

// structure of node
class Node
{
public:
  int data;
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


int size(Node* node)
{   
    if (node == NULL) return 0;
    int totalSize = 0;
    int s1 = size(node->left);
    int s2 = size(node->right);
    totalSize += s1 + s2;
    
    return totalSize+1;
}

int height(Node* node)
{   
    if (node == NULL) return -1;
    int ht = -1;
    int h1 = height(node->left);
    int h2 = height(node->right);
    ht = max(ht,max(h1,h2));
    
    ht += 1;
    return ht;
}

int maximum(Node* node)
{
  if (node == NULL) return INT_MIN;
  int mx = INT_MIN;
  
  int mx1 = maximum(node->left);
  int mx2 = maximum(node->right);
  int val = max(mx1,mx2);
  mx = max(val,node->data);
  
  return mx;
}

int sum(Node* node)
{
    if (node == NULL) return 0;
    
    int sumTree = 0;
    
    int s1 = sum(node->left);
    int s2 = sum(node->right);
    sumTree = s1 + s2;
    sumTree += node->data;
    
    return sumTree;
  
}

int main()
{

  int n;
  cin >> n;

  vector<int> arr(n, 0);
  for (int i = 0; i < n; i++) {
    string temp;
    cin >> temp;

    if (temp == "n")
    {
      arr[i] = -1;
    }
    else
    {
      arr[i] = stoi(temp);
    }
  }

  Node* root = constructTree(arr);

  int sz = size(root);
  int sm = sum(root);
  int max = maximum(root);
  int ht = height(root);
  cout << sz << endl;
  cout << sm << endl;
  cout << max << endl;
  cout << ht << endl;
}