#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

bool isIdentical(Node* root1, Node* root2) {

    if (root1 == NULL && root2 == NULL)
        return true;

    if (root1 == NULL || root2 == NULL)
        return false;

    return (root1->data == root2->data)
        && isIdentical(root1->left, root2->left)
        && isIdentical(root1->right, root2->right);
}

int main() {

    // Tree 1
    Node* root1 = new Node{1, NULL, NULL};

    root1->left = new Node{2, NULL, NULL};
    root1->right = new Node{3, NULL, NULL};

    // Tree 2
    Node* root2 = new Node{1, NULL, NULL};

    root2->left = new Node{2, NULL, NULL};
    root2->right = new Node{3, NULL, NULL};

    if (isIdentical(root1, root2))
        cout << "The trees are identical";
    else
        cout << "The trees are not identical";

    return 0;
}