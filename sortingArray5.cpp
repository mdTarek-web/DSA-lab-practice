#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;

    cout << "Enter number of strings: ";
    cin >> n;

    string arr[n];

    cout << "Enter strings:\n";

    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // Bubble Sort by Length
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < n - i - 1; j++)
        {
            if(arr[j].length() > arr[j+1].length())
            {
                string temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    cout << "\nSorted Strings:\n";

    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
} 