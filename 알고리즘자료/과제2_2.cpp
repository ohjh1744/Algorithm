#include <iostream>
using namespace std;

int n;
int arr[100001];
int arr_1[100001];
int arr_2[100001];

int merge_swap_ct;
int merge_comp_ct;

int quick_swap_ct;
int quick_comp_ct;

int heap_swap_ct;
int heap_comp_ct;

void merge(int A[], int left, int middle, int right)
{
	int i = left;
	int j = middle + 1;
	int t = 1;
	int temp[right-left+1];
	
	while(i <= middle && j <= right)
	{
		merge_comp_ct++;
		if(A[i] <= A[j]){
			merge_swap_ct++;
			temp[t++] = A[i++];
		}
		else{
			merge_swap_ct++;
			temp[t++] = A[j++];
		}
	}
	
	while(i <= middle){
		merge_swap_ct++;
		temp[t++] = A[i++];
	}
	
	while(j <= right){
		merge_swap_ct++;
		temp[t++] = A[j++];
	}
	
	i = left, t = 1;
	while(i <= right){
		merge_swap_ct++;
		A[i++] = temp[t++];
	}
}

void merge_sort(int A[], int left, int right)
{
	if(left < right){
		int middle = (left + right) / 2;
		merge_sort(A, left, middle);
		merge_sort(A, middle+1, right);
		merge(A, left, middle, right);
	}
 
}

int partition(int A[], int left, int right)
{
	int pivot = A[right];
	int i = left - 1;
	for(int j = left; j <= right-1; j++){
		quick_comp_ct++;
		if(A[j] <= pivot){
			i++;
			quick_swap_ct++;
			int temp = A[i];
			A[i] = A[j];
			A[j] = temp;
		}
	}
	
	quick_swap_ct++;
	int temp = A[i+1];
	A[i+1] = A[right];
	A[right] = temp;
	return i+1; 
}

void quick_sort(int A[], int left, int right)
{
	if(left < right){
		int p = partition(A, left, right);
		quick_sort(A, left, p-1);
		quick_sort(A, p+1, right);
	}
}

void down_heap(int A[], int i, int n)
{
	int left = i*2;
	int right = i*2+1;
	int largest = i;
	
	if(left <= n){
		heap_comp_ct++;
		if(A[left] > A[largest]){
			largest = left;
		}
	}
	
	if(right <= n){
		heap_comp_ct++;
		if(A[right] > A[largest]){
			largest = right;
		}
	}
	
	if(largest != i){
		heap_swap_ct++;
		int temp = A[i];
		A[i] = A[largest];
		A[largest] = temp;
		down_heap(A, largest, n);
	}
}

void heap_sort(int A[], int n)
{
	for(int i = n/2; i >=1; i--){
		down_heap(A, i , n);
	}
	
	for(int i = n; i >= 2; i--){
		heap_swap_ct++;
		int temp = A[i];
		A[i] = A[1];
		A[1] = temp;
		down_heap(A, 1, i-1);
	}
}




int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++){
		int num;
		cin >> num;
		arr[i] = num;
		arr_1[i] = num;
		arr_2[i] = num;
	}
	
	merge_sort(arr, 1, n);
	cout << "comp: " << merge_comp_ct << ", swap: " << merge_swap_ct << "\n";
	quick_sort(arr_1, 1, n);
	cout << "comp: " << quick_comp_ct << ", swap: " << quick_swap_ct << "\n";
	heap_sort(arr_2, n);
	cout << "comp: " << heap_comp_ct << ", swap: " << heap_swap_ct << "\n";

	
}
