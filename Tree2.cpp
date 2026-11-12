#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

int checkBalanced(Node* root) {

    if (root == NULL)
        return -1;

    int leftH = checkBalanced(root->left);

    if (leftH == -2)
        return -2;

    int rightH = checkBalanced(root->right);

    if (rightH == -2)
        return -2;

    if (abs(leftH - rightH) > 1)
        return -2;

    return 1 + max(leftH, rightH);
}

bool isBalanced(Node* root) {

    return checkBalanced(root) != -2;
}

int main() {

    Node* root = new Node{1, NULL, NULL};

    root->left = new Node{2, NULL, NULL};
    root->right = new Node{3, NULL, NULL};

    root->left->left = new Node{4, NULL, NULL};

    if (isBalanced(root)) {
        cout << "The tree is balanced";
    }
    else {
        cout << "The tree is not balanced";
    }

    return 0;
}