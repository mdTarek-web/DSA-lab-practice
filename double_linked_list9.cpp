#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

bool bidirectionalSearch(Node* head, int value) {

    if (head == nullptr) {
        return false;
    }

    // Find the last node
    Node* tail = head;

    while (tail->next != nullptr) {
        tail = tail->next;
    }

    // Two pointers
    Node* left = head;
    Node* right = tail;

    while (left != nullptr && right != nullptr) {

        // Search from head side
        if (left->data == value) {
            return true;
        }

        // Search from tail side
        if (right->data == value) {
            return true;
        }

        // Move both pointers
        left = left->next;
        right = right->prev;
    }

    return false;
}

int main() {

    // Create nodes
    Node* n1 = new Node{1, nullptr, nullptr};
    Node* n2 = new Node{2, nullptr, nullptr};
    Node* n3 = new Node{3, nullptr, nullptr};
    Node* n4 = new Node{4, nullptr, nullptr};
    Node* n5 = new Node{5, nullptr, nullptr};

    // Connect nodes
    n1->next = n2;
    n2->prev = n1;

    n2->next = n3;
    n3->prev = n2;

    n3->next = n4;
    n4->prev = n3;

    n4->next = n5;
    n5->prev = n4;

    // Search for 4
    if (bidirectionalSearch(n1, 4)) {
        cout << "Found";
    }
    else {
        cout << "Not Found";
    }

    return 0;
}