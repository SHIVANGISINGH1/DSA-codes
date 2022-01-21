#include<bits/stdc++.h>
#include<climits>
using namespace std;

class Node

{

public:

  int data = 0;

  vector<Node*> children;



  Node(int data)

  {

    this->data = data;

  }

};

void display(Node* node)
{
  string s = "";
  s += to_string(node->data) + " -> ";
  for (Node* child : node->children)
  {
    s += to_string(child->data) + ", ";
  }

  cout << s << "." << endl;

  for (Node* child : node->children)
  {
    display(child);
  }
}

Node* constructor01(vector<int>& arr)

{

  if (arr.size() == 0)

    return NULL;



  vector<Node*> stack;

  stack.push_back(new Node(arr[0]));



  Node* root = stack[0];



  for (int i = 1; i < arr.size(); i++)

  {

    if (arr[i] != -1)

    {

      Node* node = stack.back();

      Node* nnode = new Node(arr[i]);



      node->children.push_back(nnode);

      stack.push_back(nnode);

    }

    else

      stack.pop_back();

  }

  return root;

}


Node* getTail(Node* node) {
    
    while(node->children.size() == 1) {
        node = node->children[0];
    }
    
    return node;
}

Node* linearize(Node* node)
{   
    for (int idx=0; idx<node->children.size(); idx++) {
        Node* next = linearize(node->children[idx]);
    }
    
    while(node->children.size() > 1) {
        Node* lc = node->children[node->children.size()-1];//60
        node->children.erase(node->children.begin() + node->children.size()-1);
        Node* sl = node->children[node->children.size()-1];
        Node* slc = getTail(sl);
        slc->children.push_back(lc);
    }
    
}

Node* linearize2(Node* node) {
    if (node->children.size() == 0) return node;
    
    Node* lkt = linearize2(node->children[node->children.size() - 1]);
    
    while(node->children.size() > 1) {
        Node* lc = node->children[node->children.size()-1];
        node->children.erase(node->children.begin() + node->children.size()-1);
        Node* sl = node->children[node->children.size()-1];
        Node* slt = linearize2(sl);
        slt->children.push_back(lc);
    }
    
    return lkt;
}

void solve()
{
  int n;
  cin >> n;
  vector<int>arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  Node* root = constructor01(arr);

  linearize2(root);
  display(root);

}

int main()
{
  solve();
  return 0;
}