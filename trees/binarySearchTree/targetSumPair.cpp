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

bool flag1 = 0;
bool flag2 = 0;
void  targetSumPair(Node* root, int target) {
	stack<ITpair> lf;
	stack<ITpair> rt;

	ITpair it1(root,1);
	ITpair it2(root,1);

	lf.push(it1);
	rt.push(it2);
	int val1 = 0;
	int val2 = 0;
	while(true) {
		while(flag1 == 0) {
        ITpair val = lf.top();

        if (lf.top().state == 1) {
            lf.top().state++;
            if (lf.top().node->left != NULL)
            lf.push({lf.top().node->left , 1});
        } 
        else if (lf.top().state == 2) {
             lf.top().state++;
            if (lf.top().node->right != NULL)
            lf.push({lf.top().node->right , 1});
           	val1 = val.node->data;
			   flag1 = 1;
               
        }
        else {
            lf.pop();
        }
    }

	while(flag2 == 0) {
        ITpair val = rt.top();

        if (rt.top().state == 1) {
            rt.top().state++;
            if (rt.top().node->right != NULL)
            rt.push({rt.top().node->right , 1});
        } 
        else if (rt.top().state == 2) {
             rt.top().state++;
            if (rt.top().node->left != NULL)
            rt.push({rt.top().node->left , 1});
           	val2 = val.node->data;
           //	cout << val2 << " &&";
			      flag2 = 1;
          
        }
        else {
            rt.pop();
        }
    }
     if (val1 >= val2) return;
    
    if (val1 + val2 == target) {
        cout << val1 << " " << val2 << endl;
		flag1 = 0;
		flag2 = 0;
    }
   
    
	if (val1 + val2 < target) {
		flag1 = 0;
	} else if (val1 + val2 > target) {
		flag2 = 0;
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

  int target;
  cin >> target;

  Node* root = construct(arr);
  targetSumPair(root, target);
  
  
 
}