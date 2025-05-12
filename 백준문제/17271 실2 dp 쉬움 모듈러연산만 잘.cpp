#include <iostream>
using namespace std;

int n, m;
long long dp[10001];

// ��ⷯ ���꿡�� �ð� �� ��
// dp ��ü�� �ذ� ����� 
int main(){
	cin >> n >> m;
	
	dp[0] = 1;
	
	for(int i = 1; i <= n; i++){
		if(i < m){
			dp[i] = 1;
		}
		else{
			int temp = (dp[i-1] + dp[i-m]) % 1000000007;
			dp[i] = (dp[i]  + temp) % 1000000007;
		}
	}
	
	cout << dp[n];
}
