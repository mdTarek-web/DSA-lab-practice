#include <iostream>
using namespace std;

int findFirstOccurrence(int arr[], int n, int target) {

    for (int i = 0; i < n; i++) {

        if (arr[i] == target) {
            return i;
        }
    }

    return -1;
}

int main() {

    int n;

    cout << "Enter array size: ";
    cin >> n;

    int arr[n];

    cout << "Enter array elements: ";

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int target;

    cout << "Enter target: ";
    cin >> target;

    int result = findFirstOccurrence(arr, n, target);

    cout << "First occurrence index: " << result << endl;

    return 0;
}