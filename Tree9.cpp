#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

bool printAncestors(Node* root, int target) {

    if (root == NULL)
        return false;

    if (root->data == target)
        return true;

    // If target found in left or right subtree,
    // print current node
    if (printAncestors(root->left, target) ||
        printAncestors(root->right, target)) {

        cout << root->data << " ";

        return true;
    }

    return false;
}

int main() {

    Node* root = new Node{1, NULL, NULL};

    root->left = new Node{2, NULL, NULL};
    root->right = new Node{3, NULL, NULL};

    root->left->left = new Node{4, NULL, NULL};
    root->left->right = new Node{5, NULL, NULL};

    int target = 5;

    cout << "Ancestors of " << target << ": ";

    printAncestors(root, target);

    return 0;
}