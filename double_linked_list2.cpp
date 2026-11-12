#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

// Insert newValue before targetValue
void insertBefore(Node*& head, int targetValue, int newValue) {

    Node* temp = head;

    // Find the target node
    while (temp != nullptr && temp->data != targetValue) {
        temp = temp->next;
    }

    // Target not found
    if (temp == nullptr) {
        cout << "Value not found!" << endl;
        return;
    }

    // Create new node
    Node* newNode = new Node{newValue, nullptr, nullptr};

    // If target is the first node
    if (temp == head) {
        newNode->next = temp;
        temp->prev = newNode;
        head = newNode;
    }
    else {
        newNode->prev = temp->prev;
        newNode->next = temp;

        temp->prev->next = newNode;
        temp->prev = newNode;
    }
}

// Print the list
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
    Node* n2 = new Node{3, nullptr, nullptr};
    Node* n3 = new Node{4, nullptr, nullptr};

    // Connect nodes
    n1->next = n2;
    n2->prev = n1;

    n2->next = n3;
    n3->prev = n2;

    // Insert 2 before 3
    insertBefore(n1, 3, 2);

    // Display list
    display(n1);

    return 0;
}