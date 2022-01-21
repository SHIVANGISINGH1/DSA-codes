#include <iostream>
#include <vector>

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
  return node == nullptr ? -1 : max(height(node->left), height(node->right)) + 1; // for no of edges: -1, and in terms of no of nodes return 0;
}

// n2 solution 
int diameter(Node* node)
{  
    if (node == NULL) return 0;
 
    
    // calculating the diameter from the left (factor 2)
    int d1 = diameter(node->left);
    // calculating the diameter from the right (factor 3)
    int d2 = diameter(node->right);
    // calculating the height as sum of deepest node on left and right 
    int f1 = height(node->left) + height(node->right) + 2;
    
    int dia = max(f1,max(d1,d2));
    
    return dia;
}


class diaPair {
    public:
    int ht;
    int dia;
};

diaPair diameter2(Node* node) {
    
    if (node == NULL) {
        diaPair bp;
        bp.ht = -1;
        bp.dia = 0;
        return bp;
    }
    diaPair pair1 = diameter2(node->left);
    diaPair pair2 = diameter2(node->right);
    
    diaPair np ;
    
    np.ht = max(pair1.ht,pair2.ht) + 1;
    int fac = pair1.ht + pair2.ht + 2;
    
    np.dia = max(fac,max(pair1.dia,pair2.dia));
    
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

    diaPair d1;
  
    d1 = diameter2(root);
    cout << d1.dia;



}