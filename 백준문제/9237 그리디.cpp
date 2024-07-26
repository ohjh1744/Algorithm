#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int arr[100000];
int n;
int ans = 0;

int main()
{
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	sort(arr, arr+n, greater<int>());
	for(int i = 0; i < n; i++){
	}

	for(int i = 0; i <n; i++){
		ans = max(ans, i+arr[i]);
	}
	cout << ans +2;

}
 
 
