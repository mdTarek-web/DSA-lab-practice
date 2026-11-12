#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

void removeDuplicates(Node* head) {

    Node* current = head;

    while (current != nullptr && current->next != nullptr) {

        if (current->data == current->next->data) {

            Node* duplicate = current->next;

            current->next = duplicate->next;

            if (duplicate->next != nullptr) {
                duplicate->next->prev = current;
            }

            delete duplicate;
        }
        else {
            current = current->next;
        }
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
    Node* n3 = new Node{2, nullptr, nullptr};
    Node* n4 = new Node{3, nullptr, nullptr};
    Node* n5 = new Node{3, nullptr, nullptr};

    // Connect nodes
    n1->next = n2;
    n2->prev = n1;

    n2->next = n3;
    n3->prev = n2;

    n3->next = n4;
    n4->prev = n3;

    n4->next = n5;
    n5->prev = n4;

    // Remove duplicates
    removeDuplicates(n1);

    // Display
    display(n1);

    return 0;
}