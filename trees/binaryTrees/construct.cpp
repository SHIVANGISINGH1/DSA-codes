#include<bits/stdc++.h>
using namespace std;

class Node {
    public:

    int data;
    Node* left;
    Node* right;

    Node(int data,Node* left,Node* right) {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};

class Pair {
    public:
    Node* node;
    int state;

    Pair(Node* node,int state) {
        this->node = node;
        this->state = state;
    }
};


void displayTree(Node* node) {
    if (node == NULL) {
        return ;
    }

    string str = "";

    str+= node->left == NULL ? "." : to_string(node->left->data);
    str += "<-" + to_string(node->data) + "->";
    str+= node->right == NULL ? "." : to_string(node->right->data);

    cout << str << endl;

    displayTree(node->left);
    displayTree(node->right);

}
int main() {
    int arr[] = {50, 25, 12, -1, -1, 37, 30, -1, -1, -1,75, 62, -1, 70, -1, -1, 87, -1, -1};

    
    stack<Pair> st;
    Node* root = new Node(arr[0],NULL,NULL);
    
    Pair rp = Pair(root,1);

    
    int idx=0;
    st.push(rp);

    while(st.size() > 0) {

        if (st.top().state == 1) {
            st.top().state = st.top().state + 1;
            idx++;
            int val = arr[idx];

            if (val != -1) {
                Node* lf = new Node(val,NULL,NULL);
                st.top().node->left = lf;

                Pair lp = Pair(lf,1);
                st.push(lp);
            } else {
                st.top().node->left = NULL;
            }

           
        }
        else if (st.top().state == 2) {
            st.top().state = st.top().state + 1;
            idx++;
            int val = arr[idx];

            if (val != -1) {
                Node* rt = new Node(val,NULL,NULL);
                st.top().node->right = rt;

                Pair rtp = Pair(st.top().node->right,1);
                st.push(rtp);
            } else {
                st.top().node->right = NULL;
            }

        }
        else if (st.top().state == 3) {
            st.pop();
        }
    }

    displayTree(root);
}