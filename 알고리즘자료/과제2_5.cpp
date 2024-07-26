#include <iostream>
using namespace std;

int arr[100001];
int n, m;
int ans;

int partition(int A[], int left, int right)
{
	int pivot = A[right];
	int i = left - 1;
	for(int j = left; j <= right-1; j++){
		if(A[j] <= pivot){
			i++;
			int temp = A[i];
			A[i] = A[j];
			A[j] = temp;
		}
	}
	
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



int main()
{
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> arr[i];
	}
	
	quick_sort(arr, 1, n);
	
	int start = 1;
	int end = n;
    int result = arr[start] + arr[end];
    
	while(start < end){
		result = arr[start] + arr[end];
		if(result == m){
			ans++;
			start++;
		}
		if(result > m){
			end--;
		}
		if(result < m){
			start++;
		}
	}
	
	cout << ans << "\n";
	
	
}
