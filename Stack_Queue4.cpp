#include <iostream>
#include <stack>
using namespace std;

class Queue {
    stack<int> s1, s2;

public:

    void enqueue(int x) {
        s1.push(x);
    }

    int dequeue() {

        if (s1.empty() && s2.empty()) {
            return -1;
        }

        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }

        int x = s2.top();
        s2.pop();

        return x;
    }

    bool isEmpty() {
        return s1.empty() && s2.empty();
    }

    void display() {

        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }

        stack<int> temp = s2;

        while (!temp.empty()) {
            cout << temp.top() << " ";
            temp.pop();
        }

        cout << endl;
    }
};

int main() {

    Queue q;

    q.enqueue(1);
    q.enqueue(2);

    cout << q.dequeue() << endl;

    q.display();

    cout << boolalpha << q.isEmpty() << endl;

    return 0;
}