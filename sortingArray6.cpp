#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int arr[n];

    for(int i=0;i<n;i++)
        cin>>arr[i];

    int even[n], odd[n];
    int e=0,o=0;

    // Separate even and odd index elements
    for(int i=0;i<n;i++)
    {
        if(i%2==0)
            even[e++]=arr[i];
        else
            odd[o++]=arr[i];
    }

    // Sort even index values (Ascending)
    for(int i=0;i<e-1;i++)
    {
        for(int j=0;j<e-i-1;j++)
        {
            if(even[j]>even[j+1])
                swap(even[j],even[j+1]);
        }
    }

    // Sort odd index values (Descending)
    for(int i=0;i<o-1;i++)
    {
        for(int j=0;j<o-i-1;j++)
        {
            if(odd[j]<odd[j+1])
                swap(odd[j],odd[j+1]);
        }
    }

    // Put them back
    e=0;
    o=0;

    for(int i=0;i<n;i++)
    {
        if(i%2==0)
            arr[i]=even[e++];
        else
            arr[i]=odd[o++];
    }

    // Output
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";

    return 0;
}    