#include <iostream>
using namespace std;

int n;
int temp[1000001];

int partition(int* arr, int left, int right)
{
	int i = left-1;
	for(int j = left; j <= right-1; j++){
		if(arr[j] < arr[right]){
			i++;
			int temp = arr[j];
			arr[j] = arr[i];
			arr[i] = temp;
		}
	}
	
	int temp = arr[right];
	arr[right] = arr[i+1];
	arr[i+1] = temp;
	
	return i+1;
}


void quick_sort(int* arr, int left, int right)
{
	if(left < right){
		int pivot = partition(temp, left, right);
		quick_sort(temp, left, pivot-1);
		quick_sort(temp, pivot+1, right);
	}
	
}


int main()
{
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> temp[i];
	}
	
	quick_sort(temp, 0, n-1);
	
	for(int i = 0; i < n ; i++){
		cout << temp[i] << "\n";
	}
	
}
