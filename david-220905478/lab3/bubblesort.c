#include<stdio.h>
#include<stdlib.h>


void swap(int* a, int*b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void printArr(int* a, int size){
	int i;
	for (i = 0; i<size; i++){
		printf(" %d ", a[i]);
	}
	printf("\n");
}

void main(){
	int n;
	printf("give values for n");
	scanf("%d", &n);

	int i;
	//int* arr = (int*)malloc(sizeof(int)*n);
	// for (i = 0; i < n;i++){printf("give element");
	// 	scanf("%d", &arr[i]);
	// }

	int arr[] = {5,1,12,9,24,11,4,6, 8, 15, 7};


	int j;
	int comparisions = 0;
	int swaps = 0; 

	for (i =0; i < n-1; i++){
		for (j = 0; j < n-1-i; j++){
			if (arr[j]>arr[j+1]){
				swap(&arr[j], &arr[j+1]);
				swaps++;
			}
			comparisions++;
		}

	}

	printf("sorted array is: ");
	printArr(arr,n);
	printf("comparisions: %d", comparisions);
	printf("swaps: %d", swaps);
}