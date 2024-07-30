#include <iostream>
using namespace std;

int partition(int arr[], int l, int r)
{
	int pivot = arr[r];
	int i = l-1;
	for(int j = l; j < r; j++){
		if(arr[j] <= pivot){
			i = i+1;
			int temp = arr[j];
			arr[j] = arr[i];
			arr[i] = temp;
		}
	}
	int temp = arr[r];
	arr[r] = arr[i+1];
	arr[i+1] = temp;
	return i+1;
}

void quick_sort(int arr[], int l, int r)
{
	if(l < r){
		int p = partition(arr, l, r);
		quick_sort(arr, l, p-1);
		quick_sort(arr, p+1, r);
	}
}
