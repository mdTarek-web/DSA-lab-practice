#include <iostream>
#include <stack>
using namespace std;

void reverseWords(string str) {

    stack<char> s;

    for (int i = 0; i < str.length(); i++) {

        // If character is not space
        if (str[i] != ' ') {
            s.push(str[i]);
        }

        // If space is found
        else {
            while (!s.empty()) {
                cout << s.top();
                s.pop();
            }

            cout << " ";
        }
    }

    // Reverse the last word
    while (!s.empty()) {
        cout << s.top();
        s.pop();
    }
}

int main() {

    string str = "Hello World";

    reverseWords(str);

    return 0;
}