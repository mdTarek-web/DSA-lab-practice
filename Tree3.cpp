#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

int diameterHelper(Node* root, int& maxDiam) {

    if (root == NULL)
        return 0;

    int leftH = diameterHelper(root->left, maxDiam);

    int rightH = diameterHelper(root->right, maxDiam);

    // Path through this node
    maxDiam = max(maxDiam, leftH + rightH + 1);

    return 1 + max(leftH, rightH);
}

int diameter(Node* root) {

    int maxDiam = 0;

    diameterHelper(root, maxDiam);

    return maxDiam;
}

int main() {

    // Creating the tree
    Node* root = new Node{1, NULL, NULL};

    root->left = new Node{2, NULL, NULL};
    root->right = new Node{3, NULL, NULL};

    root->left->left = new Node{4, NULL, NULL};
    root->left->right = new Node{5, NULL, NULL};

    cout << "Diameter: " << diameter(root);

    return 0;
} 