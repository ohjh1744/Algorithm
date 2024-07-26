#include<iostream>
using namespace std;

int n;
int arr[10001];
int arr_1[10001];
int arr_2[10001];



void selection_sort(int A[], int n)
{
	int comp_ct = 0;
    int swap_ct = 0;
	for(int i = n; i >= 2; i--){
		int k = 1;
		for(int j = 2; j <= i; j++){
			comp_ct++;
			if(A[j] > A[k]){
				k = j;
			}
		}
		
		if(k != i){
			swap_ct++;
	        int temp = A[i];
		    A[i] = A[k];
		    A[k] = temp;
		}		
	}
	
	cout << "comp: " << comp_ct << ", swap: " << swap_ct << "\n";
}

void bubble_sort(int A[], int n)
{
	int comp_ct = 0;
    int swap_ct = 0;
	for(int i = n; i >=2; i--){
		for(int j = 1; j <= i-1; j++){
			comp_ct++;
			if(A[j] > A[j+1]){
				swap_ct++;
				int temp = A[j];
		        A[j] = A[j+1];
		        A[j+1] = temp;
			}
		}
	}
	
	cout << "comp: " << comp_ct << ", swap: " << swap_ct << "\n";
}

void insertion_sort(int A[], int n)
{
	int comp_ct = 0;
    int swap_ct = 0;
	for(int i = 2; i <=n; i++){
		int loc = i-1;
		int item = A[i];
		while(loc >= 1){
			comp_ct++;
			if(item < A[loc]){
				swap_ct++;
				A[loc+1] = A[loc];
				loc--;
			}
			else{
				break;
			}
		}
		swap_ct++;
		A[loc + 1] = item;
	}
	
	cout << "comp: " << comp_ct << ", swap: " << swap_ct << "\n";
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
	
	selection_sort(arr, n);
	bubble_sort(arr_1, n);
	insertion_sort(arr_2, n);
	
}
