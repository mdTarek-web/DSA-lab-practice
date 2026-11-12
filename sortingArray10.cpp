#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int start[n], finish[n];

    cout << "Enter Start and Finish Time:\n";

    for(int i = 0; i < n; i++)
    {
        cin >> start[i] >> finish[i];
    }

    // Bubble Sort by Duration 
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < n - i - 1; j++)
        {
            int d1 = finish[j] - start[j];
            int d2 = finish[j + 1] - start[j + 1];

            if(d1 > d2)
            {
                swap(start[j], start[j + 1]);
                swap(finish[j], finish[j + 1]);
            }
        }
    }

    cout << "Sorted Tasks:\n";

    for(int i = 0; i < n; i++)
    {
        cout << "(" << start[i] << "," << finish[i] << ") ";
    }

    return 0;
}