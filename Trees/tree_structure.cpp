#include <bits/stdc++.h>
using namespace std;

struct Tree {
    int data;
    Tree* left;
    Tree* right;

    Tree(int val) : data(val), left(nullptr), right(nullptr) {};
};

int main() {
    // Tree root(5); // stack obj

    Tree* root = new Tree(5); // heap obj
    cout << root->data;

    delete(root);
    return 0;
}