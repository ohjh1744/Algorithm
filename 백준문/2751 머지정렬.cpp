#include <iostream>
using namespace std;

int n;
int arr[1000001];

void merge(int left, int middle, int right)
{
	int i = left;
	int j = middle + 1;
	int temp[right-left + 1]; 
	int t = 0;
	while(i <= middle && j <= right){
		if(arr[i] < arr[j]){
			temp[t] = arr[i];
			i++;			
		}
		else{
			temp[t] = arr[j];
			j++;
		}
		t++;
	}
	
	while( i <= middle){
		temp[t] = arr[i];
		i++;
		t++;
	}
	
	while( j <= right){
		temp[t] = arr[j];
		j++;
		t++;
	}
	
	t = 0;
	for(int i = left; i <= right; i++){
		arr[i] = temp[t];
		t++;
	}
	
}

void merge_sort( int left, int right)
{
	if(left < right){
		int middle = (left+right)/2;
		merge_sort(left, middle);
		merge_sort(middle+1, right);
		merge(left , middle, right );
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	merge_sort( 0, n-1);
	
	for(int i = 0; i < n; i++){
		cout << arr[i] << "\n";
	}
	
	
}
