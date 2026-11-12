#include <iostream>
#include <queue>
using namespace std;

class Stack {
private:
    queue<int> q1, q2;

public:

    void push(int x) {

        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }

        q1.push(x);

        while (!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }
    }

    int pop() {

        if (q1.empty()) {
            return -1;
        }

        int x = q1.front();
        q1.pop();

        return x;
    }

    int peek() {

        if (q1.empty()) {
            return -1;
        }

        return q1.front();
    }

    bool isEmpty() {
        return q1.empty();
    }

    void display() {

        while (!q1.empty()) {
            cout << q1.front() << " ";
            q1.pop();
        }

        cout << endl;
    }
};

int main() {

    Stack s;

    s.push(1);
    s.push(2);

    cout << s.pop() << endl;

    cout << s.peek() << endl;

    cout << boolalpha << s.isEmpty() << endl;

    return 0;
}