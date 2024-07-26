#include <iostream>
#include <algorithm>
using namespace std;

int t[17];
int p[17];
int dp[17];


int main()
{
	int n;
	cin >> n;
	
	for(int i = 1; i <= n ; i++){
		cin >> t[i] >> p[i];
	}
	
	for(int i = n; i >= 1; i--){ // 거꾸로 시작 
		if( t[i]> n-i+1){   
			dp[i] = dp[i+1]; // 당일날 상담일수가 n을 넘기면 그다음일차의 최대이익이 그당일날 최대이익 
		}
		else{ //아니라면 
			dp[i] = max(dp[i+1] , p[i] + dp[i+ t[i]]); // 다음날까지의 최대이익과 당일널얻는 이익과 상담일수후 날까지의 최대이익 비교 
		}
	}
	
	cout << dp[1] << endl;
	
	
}
// 아래께 더 쉬운듯 이해하기 증가하는 부분수열갯수문제랑 비슷풀이 
//https://ongveloper.tistory.com/250
#include <iostream>
#include <algorithm>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int dp[16] = { 0 };
	int pay[16] = { 0 };
	int time[16] = { 0 };
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> time[i] >> pay[i];
		for (int j = 0; j < i; j++) {
			if (time[j] + j <= i &&i+time[i]<=n+1) {
				dp[i] = max(dp[i], dp[j]+pay[i]);
			}
		}
	}
	int answer = 0;
	for (int i = 0; i <= n; i++) {
		answer = max(answer, dp[i]);
	}
	cout << answer;
	

	return 0;
}
