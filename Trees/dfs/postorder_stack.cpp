#include <bits/stdc++.h>
using namespace std;

struct Tree {
    int data;
    Tree *left, *right;

    Tree(int val) : data(val), left(nullptr), right(nullptr) {};
};

void postorder(Tree* root) {
    /*
        left - right - root
    */
    
    // bfs using stack, reverse result
    vector<int> ans;
    stack<Tree*> st;

    if(root == nullptr) return;
    st.push(root);

    while(!st.empty()) {
        Tree* curr = st.top();
        st.pop();
        if(curr -> left) {
            st.push(curr -> left);
        }
        if(curr -> right) {
            st.push(curr -> right);
        }
        ans.push_back(curr -> data);
    }
    reverse(ans.begin(), ans.end());
    for(int x: ans) cout << x << " ";
}

int main() {

    Tree* root = new Tree(1);
    root -> left = new Tree(2);
    root -> right = new Tree(3);
    root -> left -> left = new Tree(4);
    root -> left -> right = new Tree(5);
    root -> right -> left = new Tree(6);
    root -> right -> right = new Tree(7);

    postorder(root);
    return 0;
}