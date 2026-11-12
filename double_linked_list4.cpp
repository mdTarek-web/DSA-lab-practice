#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

bool isPalindrome(Node* head) {

    if (head == nullptr) {
        return true;
    }

    // Find the last node
    Node* left = head;
    Node* right = head;

    while (right->next != nullptr) {
        right = right->next;
    }

    // Compare from both sides
    while (left != right && left->prev != right) {

        if (left->data != right->data) {
            return false;
        }

        left = left->next;
        right = right->prev;
    }

    return true;
}

int main() {

    // Create nodes
    Node* n1 = new Node{1, nullptr, nullptr};
    Node* n2 = new Node{2, nullptr, nullptr};
    Node* n3 = new Node{2, nullptr, nullptr};
    Node* n4 = new Node{1, nullptr, nullptr};

    // Connect nodes
    n1->next = n2;
    n2->prev = n1;

    n2->next = n3;
    n3->prev = n2;

    n3->next = n4;
    n4->prev = n3;

    // Check palindrome
    if (isPalindrome(n1)) {
        cout << "true";
    }
    else {
        cout << "false";
    }

    return 0;
} 