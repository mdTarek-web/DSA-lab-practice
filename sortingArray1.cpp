#include <stdio.h>

int main()
{
    int n, k;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter array elements:\n");

    for(int i=0; i<n; i++)
    {
        scanf("%d",&arr[i]);
    }

    printf("Enter k: ");
    scanf("%d",&k);

    // Bubble Sort
    for(int i=0; i<n-1; i++)
    {
        for(int j=0; j<n-i-1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    printf("%dth smallest element = %d", k, arr[k-1]);

    return 0;
}