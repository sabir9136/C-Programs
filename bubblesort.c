#include<stdio.h>

void swap(int *x, int *y)
{
	int temp  = *x;
	*x = *y;
	*y =  temp;	
}

void bsort(int arr[], int n)
{
	for(int i=0; i<n-1; i++)
	{
		for(int j=0; j<n-i-1; j++)
		{
			if(arr[j] > arr[j+1])
				swap(&arr[j], &arr[j+1]);
		} 
	}
}

int main()
{
	int n;
	printf("Eneter the length of array: ");
	scanf("%d", &n);
	int arr[n];
	printf("Enter the elements of array:\n");
	for(int i=0; i<n; i++)
		scanf("%d", &arr[i]);
    bsort(arr, n);
    printf("The sorted array is: \n");
    for(int i=0; i<n; i++)
    	printf("%d ", arr[i]);
    return 0;
}