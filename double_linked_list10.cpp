#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

void insertSorted(Node*& head, int value) {

    // Create new node
    Node* newNode = new Node{value, nullptr, nullptr};

    // Case 1: Empty list
    if (head == nullptr) {
        head = newNode;
        return;
    }

    // Case 2: Insert before head
    if (value <= head->data) {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        return;
    }

    // Find correct position
    Node* current = head;

    while (current->next != nullptr &&
           current->next->data < value) {
        current = current->next;
    }

    // Insert newNode after current
    newNode->next = current->next;
    newNode->prev = current;

    if (current->next != nullptr) {
        current->next->prev = newNode;
    }

    current->next = newNode;
}

void display(Node* head) {

    Node* temp = head;

    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main() {

    Node* n1 = new Node{1, nullptr, nullptr};
    Node* n2 = new Node{3, nullptr, nullptr};
    Node* n3 = new Node{5, nullptr, nullptr};

    n1->next = n2;
    n2->prev = n1;

    n2->next = n3;
    n3->prev = n2;

    // Insert 4
    insertSorted(n1, 4);

    display(n1);

    return 0;
}