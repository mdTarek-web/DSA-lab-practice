#include <iostream>
#include <stack>
using namespace std;

int priority(char op) {

    if (op == '*' || op == '/') {
        return 2;
    }

    if (op == '+' || op == '-') {
        return 1;
    }

    return 0;
}

void infixToPostfix(string exp) {

    stack<char> s;

    for (char ch : exp) {

        // If it is a number
        if (ch >= '0' && ch <= '9') {
            cout << ch << " ";
        }

        // If it is an operator
        else if (ch == '+' || ch == '-' ||
                 ch == '*' || ch == '/') {

            while (!s.empty() &&
                   priority(s.top()) >= priority(ch)) {

                cout << s.top() << " ";
                s.pop();
            }

            s.push(ch);
        }
    }

    // Print remaining operators
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
}

int main() {

    string exp = "3+5*2";

    infixToPostfix(exp);

    return 0;
}