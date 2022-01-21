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
  s += to_string(node->data) + " Child: ";
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

vector<int> rootNodeToPath(Node* node, int data)
{

  if (node->data == data)
  {
    vector<int> base;
    base.push_back(data);
    return base;
  }

  vector<int> ans;
  for (Node* child : node->children)
  {
    vector<int>recAns = rootNodeToPath(child, data);
    if (recAns.size() > 0)
    {
      recAns.push_back(node->data);
      return recAns;
    }
  }
  return ans;
}


int distanceNodes(Node* node, int data1, int data2)
{
    vector<int> path1 = rootNodeToPath(node,data1);
    vector<int> path2 = rootNodeToPath(node,data2);
    
    
    int i=path1.size()-1;
    int j=path2.size()-1;
    
    
        while (path1[i] == path2[j] && i>=0 && j>=0)
        {
            i--;
            j--;
        }
    
    i++;
    j++;
    

    
    return i+j;
}

bool treesSimilar(Node* node1,Node* node2) {
    
    if (node1->children.size() != node2->children.size()) 
        return false;
        
    for (int idx=0; idx<node1->children.size(); idx++) {
        bool val = treesSimilar(node1->children[idx],node2->children[idx]);
            if (val) return true;
            else return false;
        }
    
    
    
    return true;
}


void solve()
{
  int n1;
  cin >> n1;
  vector<int>arr1(n1, 0);
  for (int i = 0; i < arr1.size(); i++)
  {
    cin >> arr1[i];
  }

  int n2;
  cin >> n2;
  vector<int>arr2(n2, 0);
  for (int i = 0; i < arr2.size(); i++)
  {
    cin >> arr2[i];
  }

  Node* root1 = constructor01(arr1);
  Node* root2 = constructor01(arr2);
  bool ans = treesSimilar(root1,root2);
  if (ans == 1) cout<<"true";
  else cout<<"false";
  //cout << ans << endl;
}

int main()
{
  solve();
  return 0;
}