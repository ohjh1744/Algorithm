#include <iostream>
#include <algorithm>
using namespace std;

int n , m;
int temp1[500000];

void b_search(int arr[], int length, int key)
{
	int start = 0;
	int end = length - 1;
	while(start <= end){
		int mid = (start + end) / 2;
		if(arr[mid] == key){
			cout << "1" << " ";
			return;
		}
		
		if(arr[mid]< key){
			start = mid + 1;
		}
		if(arr[mid] > key){
			end = mid-1;
		}
		
	}
	cout << "0" << " ";
	return;
}

int main()
{
    cout.tie(0); 
	cin.tie(0);
	 
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> temp1[i];
	}
	sort(temp1, temp1 + n);
	cin >> m;
	int f = 0;
	for(int i = 0; i < m; i++){
		cin >> f;
		b_search(temp1, n, f);
	}
	
}
