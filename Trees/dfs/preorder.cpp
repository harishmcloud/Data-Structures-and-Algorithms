#include <bits/stdc++.h>
using namespace std;

struct Tree {
    int data;
    Tree *left, *right;

    Tree(int val) : data(val), left(nullptr), right(nullptr) {};
};

void preorder(Tree* root) {
    /*
        root - left - right
    */
   if(root == nullptr) return;
   cout << root -> data << " ";
   preorder(root -> left);
   preorder(root -> right);
}

int main() {

    Tree* root = new Tree(1);
    root -> left = new Tree(2);
    root -> right = new Tree(3);
    root -> left -> left = new Tree(4);
    root -> left -> right = new Tree(5);
    root -> right -> left = new Tree(6);
    root -> right -> right = new Tree(7);

    preorder(root);
    delete root;
    return 0;
}