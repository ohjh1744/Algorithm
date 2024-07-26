#include <iostream>
#include <algorithm> 
using namespace std;

long long arr[500000];
int n;
long long ans;
int main()
{
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	sort(arr, arr+n);
	
	for(int i = 1; i <= n; i++){
		ans = ans + abs(i-arr[i-1]);
	}
	cout << ans << "\n";
}
