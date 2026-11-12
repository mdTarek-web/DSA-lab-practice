#include <iostream>
#include <stack>
using namespace std;

bool isBalanced(string str) {

    stack<char> s;

    for (int i = 0; i < str.length(); i++) {

        // Opening brackets
        if (str[i] == '(' ||
            str[i] == '{' ||
            str[i] == '[') {

            s.push(str[i]);
        }

        // Closing bracket ')'
        else if (str[i] == ')') {

            if (s.empty() || s.top() != '(') {
                return false;
            }

            s.pop();
        }

        // Closing bracket '}'
        else if (str[i] == '}') {

            if (s.empty() || s.top() != '{') {
                return false;
            }

            s.pop();
        }

        // Closing bracket ']'
        else if (str[i] == ']') {

            if (s.empty() || s.top() != '[') {
                return false;
            }

            s.pop();
        }
    }

    return s.empty();
}

int main() {

    string str = "()[]{}";

    if (isBalanced(str)) {
        cout << "True";
    }
    else {
        cout << "False";
    }

    return 0;
}