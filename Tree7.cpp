#include <iostream>
#include <climits>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

bool validateBST(Node* root, long long minVal, long long maxVal)
{
    if (root == NULL)
        return true;

    if (root->data <= minVal || root->data >= maxVal)
        return false;

    return validateBST(root->left, minVal, root->data)
        && validateBST(root->right, root->data, maxVal);
}

bool isValidBST(Node* root)
{
    return validateBST(root, LLONG_MIN, LLONG_MAX);
}

int main()
{
    Node* root = new Node{50, NULL, NULL};

    root->left = new Node{30, NULL, NULL};
    root->right = new Node{70, NULL, NULL};

    root->left->left = new Node{20, NULL, NULL};
    root->left->right = new Node{40, NULL, NULL};

    root->right->left = new Node{60, NULL, NULL};
    root->right->right = new Node{80, NULL, NULL};

    if (isValidBST(root))
        cout << "Valid BST";
    else
        cout << "Invalid BST";

    return 0;
}