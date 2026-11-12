#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

bool isPalindrome(string str) {

    stack<char> s;
    string clean = "";

    // Remove spaces and convert to lowercase
    for (char ch : str) {
        if (ch != ' ') {
            clean += tolower(ch);
        }
    }

    // Push all characters into stack
    for (char ch : clean) {
        s.push(ch);
    }

    // Compare original with reversed
    for (char ch : clean) {

        if (ch != s.top()) {
            return false;
        }

        s.pop();
    }

    return true;
}

int main() {

    string str = "A man a plan a canal Panama";

    if (isPalindrome(str)) {
        cout << "True";
    }
    else {
        cout << "False";
    }

    return 0;
}