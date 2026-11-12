#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

void kthSmallestHelper(Node* root, int& k, int& result) {

    if (root == NULL)
        return;

    kthSmallestHelper(root->left, k, result);

    k--;

    if (k == 0) {
        result = root->data;
        return;
    }

    kthSmallestHelper(root->right, k, result);
}

int kthSmallest(Node* root, int k) {

    int result = -1;

    kthSmallestHelper(root, k, result);

    return result;
}

int main() {

    Node* root = new Node{50, NULL, NULL};

    root->left = new Node{30, NULL, NULL};
    root->right = new Node{70, NULL, NULL};

    root->left->left = new Node{20, NULL, NULL};
    root->left->right = new Node{40, NULL, NULL};

    root->right->left = new Node{60, NULL, NULL};
    root->right->right = new Node{80, NULL, NULL};

    int k = 3;

    cout << "3rd smallest element: "
         << kthSmallest(root, k);

    return 0;
}