#include <iostream>
using namespace std;

int n;
int dp[21][2];  // i까지 오는데  매우 큰점프 사용 x, 1은 이전에 매우 큰 점프 사용 ㅇ 
int arr[21][2]; // 0은 작은점프, 1은 큰점프 
int k;

// 집중력이 안좋은 상태에서 풀은지라 꽤 오래 걸리문제
// 어려운 문제아님 전형적인 dp 문제
// n <= 3 부분에서 에러체크 안해줘서 오래 걸림. 
int main(){
	cin >> n;
	
	for(int i = 1; i <= n-1; i++){
		cin >> arr[i][0] >> arr[i][1]; 
	}
	
	cin >> k;
	
	// 큰수로 초기화 
	for(int i = 0; i <= n ; i++){
		dp[i][0] = 1e9;
		dp[i][1] = 1e9;
	}
	
	dp[1][0] = 0;
	dp[2][0] = arr[1][0];
	dp[3][0] = min(dp[2][0] + arr[2][0] , dp[1][0] + arr[1][1]);
	
	for(int i = 4; i <= n; i++){
		// i-1번째까지 작, 큰 점프만 이용해서  온 경우에서 작은 점프, i-2번째까지 작, 큰점프만 이용해서 온경우에서 큰점프 
		// 위 2가지 상황에서 제일 작은 값 
		dp[i][0] = min(dp[i-1][0] + arr[i-1][0], dp[i-2][0] + arr[i-2][1]);
		// i-1 번째쨍까지  매우큰점프 사용한 경우, i-2번째까지 매우 큰 점프 사용한 경우, i-3번째에서 매우 큰 점프 사용.
		// 위 3가지 상황에서 제일 작은 값 
		dp[i][1] = min(min(dp[i-1][1] + arr[i-1][0],  dp[i-2][1] + arr[i-2][1]) , dp[i-3][0] + k); 
		
	}
	
	if(n <= 3){
		cout << dp[n][0];
	}
	else{
		cout << min(dp[n][0] , dp[n][1]);
	}

}
