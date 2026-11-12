#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

void printLastK(Node* head, int k) {

    if (head == nullptr || k <= 0) {
        return;
    }

    // Go to the last node
    Node* temp = head;

    while (temp->next != nullptr) {
        temp = temp->next;
    }

    // Move backward k-1 times
    for (int i = 1; i < k; i++) {
        if (temp->prev != nullptr) {
            temp = temp->prev;
        }
    }

    // Print from this node to the end
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

    // Print last 2 elements
    printLastK(n1, 2);

    return 0;
}