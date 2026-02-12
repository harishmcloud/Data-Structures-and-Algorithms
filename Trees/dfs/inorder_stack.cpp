#include <bits/stdc++.h>
using namespace std;

struct Tree {
    int data;
    Tree* left, *right;

    Tree(int val) : data(val), left(nullptr), right(nullptr) {};
};

void inOrder(Tree* root) {
    /*
        left - root - right
    */
   stack<Tree*> st;
   Tree* curr = root;

   while(curr || !st.empty()) {  // init stack is empty for that (curr != nullptr)
        while(curr) {
            st.push(curr); // left
            curr = curr -> left;
        }
        curr = st.top();
        cout << curr -> data << " ";
        st.pop();
        curr = curr -> right;
    }
}

int main() {

    Tree* root = new Tree(1);
    root -> left = new Tree(2);
    root -> right = new Tree(3);
    root -> left -> left = new Tree(4);
    root -> left -> right = new Tree(5);
    root -> right -> left = new Tree(6);
    root -> right -> right = new Tree(7);

    inOrder(root);

    delete root;
    return 0;
}