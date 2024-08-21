#include <iostream>
#include <algorithm>
using namespace std;

int n, k;
int temp[100001];
int ans;
int main()
{
	cin >> n >> k;
	for(int i = 1; i <= n; i++){
		cin >> temp[i];
	}
	
	for(int i = 1; i <= k; i++){
		ans = ans + temp[i];
	}
	
	int tp = ans;
	for(int i = k+1; i <= n; i++){
		tp = tp - temp[i-k] + temp[i];
		cout << tp << endl; 
		ans = max(ans , tp);
	}
	cout << ans << "\n";
}
