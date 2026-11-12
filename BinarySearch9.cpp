#include <iostream>
#include <cstdlib>
using namespace std;

int findClosest(int arr[], int n, int target)
{
    int low = 0;
    int high = n - 1;
    int closest = arr[0];

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (abs(arr[mid] - target) < abs(closest - target))
        {
            closest = arr[mid];
        }
        else if (abs(arr[mid] - target) == abs(closest - target))
        {
            if (arr[mid] < closest)
            {
                closest = arr[mid];  
            }
        }

        if (arr[mid] == target)
        {
            return arr[mid];
        }
        else if (arr[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return closest;
}

int main()
{
    int arr[] = {1, 3, 8, 10, 15};

    int n = 5;

    int target = 12;

    int result = findClosest(arr, n, target);

    cout << "Output: " << result << endl;

    return 0;
}