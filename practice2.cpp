#include <iostream>
#include <vector>
using namespace std;

vector<int> findAllOccurrences(int arr[], int n, int target) {

    vector<int> indices;

    for (int i = 0; i < n; i++) {

        if (arr[i] == target) {
            indices.push_back(i);
        }
    }

    return indices;
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

    vector<int> result = findAllOccurrences(arr, n, target);

    cout << "Indices: ";

    for (int index : result) {
        cout << index << " ";
    }

    return 0;
}