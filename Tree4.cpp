#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

void levelOrder(Node* root) {

    if (root == NULL)
        return;

    queue<Node*> q;

    q.push(root);

    cout << "Level Order Traversal: ";

    while (!q.empty()) {

        Node* curr = q.front();

        q.pop();

        cout << curr->data << " ";

        if (curr->left != NULL)
            q.push(curr->left);

        if (curr->right != NULL)
            q.push(curr->right);
    }
}

int main() {

    Node* root = new Node{1, NULL, NULL};

    root->left = new Node{2, NULL, NULL};
    root->right = new Node{3, NULL, NULL};

    root->left->left = new Node{4, NULL, NULL};
    root->left->right = new Node{5, NULL, NULL};

    root->right->right = new Node{6, NULL, NULL};

    levelOrder(root);

    return 0;
}