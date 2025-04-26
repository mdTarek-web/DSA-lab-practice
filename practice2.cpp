#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    string s;
    cin >> s;

    
    string numbers = "";

    for (int i = 0; i < s.length(); i += 2) {
        numbers += s[i];
    }

    sort(numbers.begin(), numbers.end());

    for (int i = 0; i < numbers.length(); ++i) {
        cout << numbers[i];
        if (i != numbers.length() - 1) {
            cout << "+";
        }
    }

    cout << endl;
    return 0;
}


