#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;

    int arr[n];

    for(int i=0;i<n;i++)
        cin>>arr[i];

    // Bubble Sort
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
                swap(arr[j],arr[j+1]);
        }
    }

    int current=1;
    int maximum=1;

    for(int i=1;i<n;i++)
    {
        if(arr[i]==arr[i-1]+1)
        {
            current++;
        }
        else
        {
            current=1;
        }

        if(current>maximum)
            maximum=current;
    }

    cout<<maximum;

    return 0;
}