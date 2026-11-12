#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

void reverseList(Node*& head) {

    Node* temp = nullptr;
    Node* current = head;

    while (current != nullptr) {

        // Swap prev and next
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;

        // Move to the next node
        current = current->prev;
    }

    // Update head
    if (temp != nullptr) {
        head = temp->prev;
    }
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

    // Connect nodes
    n1->next = n2;
    n2->prev = n1;

    n2->next = n3;
    n3->prev = n2;

    // Reverse the list
    reverseList(n1);

    // Display reversed list
    display(n1);

    return 0;
}