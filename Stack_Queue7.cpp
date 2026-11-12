#include <iostream>
#include <stack>
using namespace std;

int findMiddle(stack<int> s) {

    int n = s.size();

    int middle = n / 2;

    for (int i = 0; i < middle; i++) {
        s.pop();
    }

    return s.top();
}

int main() {

    stack<int> s;

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    cout << findMiddle(s);

    return 0;
}