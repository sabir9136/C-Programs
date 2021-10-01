#include <stdio.h>
#include <stdlib.h>
#include "uniform.c"
#include "normaldis.c"
int compare=0;
void swap(int* a, int* b) 
{ 
	int t = *a; 
	*a = *b; 
	*b = t; 
} 
int partition (int arr[], int low, int high) 
{ 
	int pivot = arr[high]; 
	int i = (low - 1); 

	for (int j = low; j <= high - 1; j++) 
	{  
		if (arr[j] < pivot) 
		{ 
			i++; 
			compare++; 
			swap(&arr[i], &arr[j]); 
		} 
	} 
	swap(&arr[i + 1], &arr[high]); 
	return (i + 1); 
} 
void quickSort(int arr[], int low, int high) 
{ 
	if (low < high) 
	{ 
		int pi = partition(arr, low, high); 
		quickSort(arr, low, pi - 1); 
		quickSort(arr, pi + 1, high); 
	} 
} 
void printArray(int arr[], int size) 
{ 
	int i; 
	for (i = 0; i < size; i++) 
		printf("%d ",arr[i]); 
	printf("\n"); 
} 
int main() 
{ 
	/*printf("Uniform Dataset\n");
	
	int *arr=generateUD(10,10,10);
	int n = 10;

	quickSort(arr, 0, n - 1); 
	printf("Comparisons: \n",compare); 

	printf("Normal Dataset\n");

	int *arr2=generateND(10,10,10);
	int n2 = 10;
	quickSort(arr2, 0, n2 - 1); 
	printf("Comparisons: \n",compare);
	*/
	printf("Normal Dataset\n");
	
	//int *arr=generateUD(128,10,10);
	int arr_size =65536;

	//printf("Given array is \n");
	//printArray(arr, arr_size);

	clock_t start, end;
    double cpu_time_used=0;
	start = clock();
	int avg=655360/arr_size;
	for(int i=0;i<avg;i++)
	{
		int *arr=generateND(10,10,arr_size);
		quickSort(arr, 0, arr_size - 1);
	}
	end = clock();
	cpu_time_used = ((double) (end) - (double)(start)) / CLOCKS_PER_SEC;
	cpu_time_used/=(double)avg;
	compare/=avg;
	printf("Execution time:%f units\n",cpu_time_used*1000);
	printf("Comparisons:%d\n",compare);
	return 0; 
}
