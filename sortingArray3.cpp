#include <stdio.h>

int main()
{
    int n;

    printf("Enter number of elements: ");
    scanf("%d",&n);

    int arr[n];

    printf("Enter array elements:\n");

    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    // Bubble Sort
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }

    // First difference
    int minDiff = arr[1] - arr[0];

    // Find smallest difference
    for(int i=1;i<n-1;i++)
    {
        int diff = arr[i+1] - arr[i];

        if(diff < minDiff)
        {
            minDiff = diff;
        }
    }

    printf("Smallest Difference = %d",minDiff);

    return 0;
}