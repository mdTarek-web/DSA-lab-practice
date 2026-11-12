#include <iostream>
#include <stack>
#include <sstream>
using namespace std;

int evaluatePostfix(string exp) {

    stack<int> s;
    stringstream ss(exp);
    string token;

    while (ss >> token) {

        if (token >= "0" && token <= "9") {
            s.push(stoi(token));
        }

        else {
            int b = s.top();
            s.pop();

            int a = s.top();
            s.pop();

            int result;

            if (token == "+") {
                result = a + b;
            }
            else if (token == "-") {
                result = a - b;
            }
            else if (token == "*") {
                result = a * b;
            }
            else if (token == "/") {
                result = a / b;
            }

            s.push(result);
        }
    }

    return s.top();
}

int main() {

    string exp = "3 5 2 * +";

    cout << evaluatePostfix(exp);

    return 0;
}