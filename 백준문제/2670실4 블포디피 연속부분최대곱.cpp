#include <iostream>
#include <algorithm>
using namespace std;

int n;
double temp[10001];
double dp[10001];
double ans;

//float���� double�� �ؾ���. double�� ǥ���ϴ� �� �� ����.
 
int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> temp[i];
	}
	
	dp[1] = temp[1];
	
	for(int i = 2;  i <= n; i++){
		dp[i] = max(dp[i-1] * temp[i] , temp[i]);
		ans = max(ans, dp[i]);
	}
	
	printf("%.3lf" , ans);
}
