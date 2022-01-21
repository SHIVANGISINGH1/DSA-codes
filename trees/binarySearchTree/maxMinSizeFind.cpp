#include<bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	Node* left;
	Node* right;
	Node(int val) {
    data = val;
    left = nullptr;
    right = nullptr;
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


int Min(Node* node) {
    int mn = INT_MAX;
 
    if (node == NULL) return INT_MAX;
    
    int v1 = Min(node->left);
    mn = min(node->data,v1);
    
    return mn;
}

int Max(Node* node) {
    int mx = INT_MIN;
    if (node == NULL) return INT_MIN;
    
    int v1 = Max(node->right);
    mx = max(node->data,v1);
    
    return mx;
}

int sum(Node* node) {
    
    if (node == NULL) return 0;
    int add = 0;
    int l1 = sum(node->left);
    int l2 = sum(node->right);
    
    add += l1 + l2 + node->data;
    
    return add;
}


int size(Node* node) {
    if (node == NULL) return 0;
    int len = 0;
    int l1 = size(node->left);
    int l2 = size(node->right);
    
    len += l1 + l2 + 1;
    
    return len;
}


bool find(Node* node, int data) {
    
    if (node == NULL) return false;
    if (node->data == data) return true;
    
    if (data > node->data) {
        bool f1 = find(node->right,data);
        if (f1) return true;
        else return false;
    }
    else {
        bool f2 = find(node->left,data);
        if (f2) return true;
        else return false;
    }
    
    return false;
}


int main() {
	int n;
	cin >> n;
	vector<int> arr(n, 0);
	for (int i = 0; i < n; i++) {
		string x;
		cin >> x;
		if (x == "n") {
			arr[i] = -1;

		}
		else {
				arr[i] = stoi(x);
		}
	}
  	int data;
  	cin >> data;
  	Node* root = construct(arr);
  	cout << size(root) << "\n" << sum (root) << "\n" << Max(root) << "\n" << Min(root) <<  "\n";
  
	if (find(root, data)) {
    	cout << "true" << endl;
  	}
  	else {
    	cout << "false" << endl;
  	}
}