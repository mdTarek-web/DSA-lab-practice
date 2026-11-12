#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

void mirror(Node* root) {

    if (root == NULL)
        return;

    // Recursively mirror subtrees first
    mirror(root->left);
    mirror(root->right);

    // Swap left and right children
    Node* temp = root->left;
    root->left = root->right;
    root->right = temp;
}

void inorder(Node* root) {

    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {

    Node* root = new Node{1, NULL, NULL};

    root->left = new Node{2, NULL, NULL};
    root->right = new Node{3, NULL, NULL};

    mirror(root);

    cout << "Mirrored Tree (Inorder): ";
    inorder(root);

    return 0;
}