#include <iostream>
#include <algorithm>
using namespace  std;

int n;
int temp[1001];
int dp[1001]; //몇번째 칸의 최대길이 

// 참고 https://bitwise.tistory.com/215
int main()
{
	cin >> n;
	int num;
	for(int i = 1; i <= n; i++){
		cin >> num;
		temp[i] = num;
		dp[i] = 1;
	}
	
	int result = 0;
	
	for(int i = 1;i <= n; i++){
		for(int j= 1; j <= i; j++){
			if(temp[i] > temp[j] && dp[j]+1 > dp[i]){
				dp[i] = dp[j] + 1;
			}
		}
		result = max(result, dp[i]);

	}

	cout << result << "\n";
}
