#include <bits/stdc++.h>
using namespace std;

struct Tree {
    int data;
    Tree *left, *right;

    Tree(int val) : data(val), left(nullptr), right(nullptr) {};
};

vector<vector<int>> bfs(Tree* root) {
    vector<vector<int>> ans;
    queue<Tree*> q;

    q.push(root);

    while(!q.empty()) {
        vector<int> lvl;
        int currSize = q.size();
        while(currSize--) {
            Tree* curr = q.front();
            q.pop();
            if(curr -> left) {
                q.push(curr -> left);
            }
            if(curr -> right) {
                q.push(curr -> right);
            }
            lvl.push_back(curr -> data);
        }
        ans.push_back(lvl);
    }
    return ans;
}

int main() {

    Tree* root = new Tree(1);
    root -> left = new Tree(2);
    root -> right = new Tree(3);
    root -> left -> left = new Tree(4);
    root -> left -> right = new Tree(5);
    root -> right -> left = new Tree(6);
    root -> right -> right = new Tree(7);

    vector<vector<int>> ans = bfs(root);
    
    for(auto x: ans) {
        for(int y: x) {
            cout << y << " ";
        }
        cout << '\n';
    }
    
    delete root;
    return 0;
}