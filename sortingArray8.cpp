#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int arr[n];

    for(int i=0;i<n;i++)
        cin>>arr[i];

    int freq[n];

    // Frequency Count
    for(int i=0;i<n;i++)
    {
        freq[i]=0;

        for(int j=0;j<n;j++)
        {
            if(arr[i]==arr[j])
                freq[i]++;
        }
    }

    // Bubble Sort
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(freq[j] < freq[j+1] ||
                (freq[j]==freq[j+1] && arr[j] > arr[j+1]))
            {
                swap(freq[j],freq[j+1]);
                swap(arr[j],arr[j+1]);
            }
        }
    }

    // Output
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";

    return 0;
}