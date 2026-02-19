#include <bits/stdc++.h>
using namespace std;

struct Tree {
    int data;
    Tree* left, *right;

    Tree(int val) : data(val), left(nullptr), right(nullptr) {};
};

int height(Tree* root) {
    if(root == nullptr) return 0;

    int lh = height(root -> left);
    int rh = height(root -> right);
    if(abs(lh-rh) > 1) return -1;
    if(lh == -1 || rh == -1) return -1;

    return 1+max(lh, rh);
}

bool isBalanced(Tree* root) {
    /*
        A height-balanced binary tree is a binary tree in which
        the depth of the two subtrees of every node
        never differs by more than one.
    */

    int h = height(root);
    if(h == -1) return false;
    return true;
}

int main() {
    
    Tree* root = new Tree(3);
    root -> left = new Tree(9);
    root -> right = new Tree(20);
    root -> right -> left = new Tree(15);
    root -> right -> right = new Tree(7);

    cout << (isBalanced(root) ? "true" : "false") << '\n';

    delete root;
    return 0;
}