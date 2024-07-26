#include <iostream>
using namespace std;

// �迭 1���� n���� �����Ѵ������� 0���� 
void counting_sort(int arr[], int k, int n)
{
	int counted[k+1];
	for(int i = 1; i <= k; i++){
		counted[i] = 0;
	}
	
	for(int i = 1; i < n; i++){
		int key = arr[i];
		counted[key]++;
	}
	
	int sorted[n+1];
	for(int i = 1; i <= n; i++){
		sorted[i] = 0;
	}
	
	for(int i = n; i >= 1 ; i--){
		int key = arr[i];
		sorted[counted[key]] = key;
		counted[key]--;
	}	
	
} 
