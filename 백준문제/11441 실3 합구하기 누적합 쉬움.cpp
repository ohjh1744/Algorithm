#include <iostream>
#include <vector>
using namespace std;

int arr[100001]; 
int dp[100001];
int n, m;

int main(){
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	
	for(int i = 1; i <= n; i++){
		cin >> arr[i];
	}
	
	cin >> m;
	
	for(int i = 1; i <= n; i++){
		dp[i] = dp[i-1] + arr[i];
	}
	
	int front , end;
	
	for(int i = 0; i < m; i++){
		cin >> front >> end;
		cout << dp[end] - dp[front] + arr[front] << "\n";
	}
	
}
