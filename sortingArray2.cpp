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

    if(n%2==1)
    {
        printf("Median = %d",arr[n/2]);
    }
    else
    {
        float median=(arr[n/2]+arr[n/2-1])/2.0;
        printf("Median = %.2f",median);
    }

    return 0;
}