#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

void rotateLeft(Node*& head) {

    // Empty list or only one node
    if (head == nullptr || head->next == nullptr) {
        return;
    }

    // Store the first node
    Node* first = head;

    // Move head to the second node
    head = head->next;

    // New head has no previous node
    head->prev = nullptr;

    // Go to the last node
    Node* last = head;

    while (last->next != nullptr) {
        last = last->next;
    }

    // Put first node at the end
    last->next = first;
    first->prev = last;

    // First node becomes the last node
    first->next = nullptr;
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

    // Rotate left by one
    rotateLeft(n1);

    // Display
    display(n1);

    return 0;
}