#include <bits/stdc++.h>
using namespace std;

struct Tree {
    int data;
    Tree *left, *right;

    Tree(int val) : data(val), left(nullptr), right(nullptr) {};
};

void inOrder(Tree* root) {
    /*
        left - root - right
    */
    if(root == nullptr) {
        return;
    }
    inOrder(root -> left);
    cout << root -> data << " ";
    inOrder(root -> right);
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

    delete root;   // always delete heap allocated obj
    return 0;
}