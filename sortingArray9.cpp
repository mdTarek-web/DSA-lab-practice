#include<iostream>
using namespace std;

int main()
{
    int n, m;

    cout << "Enter size of first array: ";
    cin >> n;

    cout << "Enter size of second array: ";
    cin >> m;

    int a[n], b[m];

    cout << "Enter first array:\n";

    for(int i=0;i<n;i++)
        cin>>a[i];

    cout << "Enter second array:\n";

    for(int i=0;i<m;i++)
        cin>>b[i];

    int c[n+m];

    // Merge
    for(int i=0;i<n;i++)
        c[i]=a[i];

    for(int i=0;i<m;i++)
        c[n+i]=b[i];

    // Bubble Sort
    for(int i=0;i<n+m-1;i++)
    {
        for(int j=0;j<n+m-i-1;j++)
        {
            if(c[j]>c[j+1])
            {
                swap(c[j],c[j+1]);
            }
        }
    }

    cout<<"Merged & Sorted Array:\n";

    for(int i=0;i<n+m;i++)
        cout<<c[i]<<" ";

    return 0;
}