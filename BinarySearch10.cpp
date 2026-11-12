#include <iostream>
using namespace std;

int findPeak(int arr[], int n)
{
    int low = 0;
    int high = n - 1;

    while (low < high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] < arr[mid + 1])
        {
            low = mid + 1;
        }
        else
        {
            high = mid;
        }
    }

    return low;
}

int main()
{
    int n;

    cout << "Enter array size: ";
    cin >> n;

    int arr[n];

    cout << "Enter mountain array elements: ";

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int result = findPeak(arr, n);

    cout << "Peak index: " << result << endl;
    cout << "Peak element: " << arr[result] << endl;

    return 0;
} 