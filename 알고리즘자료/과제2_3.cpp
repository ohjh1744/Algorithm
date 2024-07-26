#include <iostream>
using namespace std;

int n;
int arr[100001];
long long ans;

void merge(int A[], int left, int middle, int right)
{
	int i = left;
	int j = middle + 1;
	int t = 1;
	int temp[right-left+1];
	
	while(i <= middle && j <= right)
	{
		if(A[i] <= A[j]){ 
			temp[t++] = A[i++];
		}
		else{
			ans = ans + (middle - i+1);
			temp[t++] = A[j++];
		}
	}
	
	while(i <= middle){
		temp[t++] = A[i++];
	}
	
	while(j <= right){
		temp[t++] = A[j++];
	}
	
	i = left, t = 1;
	while(i <= right){
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

int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> arr[i];
	}
	merge_sort(arr, 1, n);
	cout << ans << "\n";
}
