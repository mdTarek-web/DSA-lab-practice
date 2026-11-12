#include <iostream>
using namespace std;

#define SIZE 3

int queue[SIZE];
int front = 0;
int rear = 0;

void enqueue(int value) {
    queue[rear] = value;
    rear = (rear + 1) % SIZE;
}

int dequeue() {
    int value = queue[front];
    front = (front + 1) % SIZE;
    return value;
}

void display() {
    int i = front;

    while (i != rear) {
        cout << queue[i] << " ";
        i = (i + 1) % SIZE;
    }
}

int main() {

    enqueue(1);
    enqueue(2);

    cout << dequeue() << endl;

    enqueue(3);

    display();

    return 0;
}