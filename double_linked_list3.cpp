#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

// Delete a given node in O(1)
void deleteNode(Node* node) {

    // Connect previous node to next node
    if (node->prev != nullptr) {
        node->prev->next = node->next;
    }

    // Connect next node to previous node
    if (node->next != nullptr) {
        node->next->prev = node->prev;
    }

    // Delete the node
    delete node;
}

void display(Node* head) {
    Node* temp = head;

    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main() {

    // Create nodes
    Node* n1 = new Node{1, nullptr, nullptr};
    Node* n2 = new Node{2, nullptr, nullptr};
    Node* n3 = new Node{3, nullptr, nullptr};
    Node* n4 = new Node{4, nullptr, nullptr};

    // Connect nodes
    n1->next = n2;
    n2->prev = n1;

    n2->next = n3;
    n3->prev = n2;

    n3->next = n4;
    n4->prev = n3;

    // Delete node 3
    deleteNode(n3);

    // Display list
    display(n1);

    return 0;
}