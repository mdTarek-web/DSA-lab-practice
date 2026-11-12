#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

bool findPath(Node* root, int target, vector<int>& path) {

    if (root == NULL)
        return false;

    path.push_back(root->data);

    if (root->data == target)
        return true;

    if (findPath(root->left, target, path) ||
        findPath(root->right, target, path))
        return true;

    // Target not found in this subtree; backtrack
    path.pop_back();

    return false;
}

void printPath(Node* root, int target) {

    vector<int> path;

    if (!findPath(root, target, path)) {
        cout << "Node not found" << endl;
        return;
    }

    cout << "Path: ";

    for (int i = 0; i < (int)path.size(); i++) {

        if (i > 0)
            cout << " -> ";

        cout << path[i];
    }

    cout << endl;
}

int main() {

    Node* root = new Node{1, NULL, NULL};

    root->left = new Node{2, NULL, NULL};
    root->right = new Node{3, NULL, NULL};

    root->left->left = new Node{4, NULL, NULL};
    root->left->right = new Node{5, NULL, NULL};

    int target = 5;

    printPath(root, target);

    return 0;
}