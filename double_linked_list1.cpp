#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

void traverseBackward(Node* head) {

    // Go to the last node
    Node* temp = head;

    while (temp->next != nullptr) {
        temp = temp->next;
    }

    // Traverse backward using prev pointer
    while (temp != nullptr) { 
        cout << temp->data << " ";
        temp = temp->prev;
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

    // Traverse backward
    traverseBackward(n1);

    return 0;
}