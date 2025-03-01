#include <iostream>
#include <vector>
using namespace std;

int t; 
long long dp[65][10]; // dp[2][2] => 2자리수중에 마지막 자리수가 2인 경우. 
int max_input;
int input[1001];

int main(){
	
	cin >> t;
	
	for(int i = 0; i < t; i++){
		cin >> input[i];
		
		if(max_input < input[i]){
			max_input = input[i];
		}
	}
	
	// 맨뒤에가 0인 경우는 각 자리수별로 1개의 경우만 존재. 
	for(int i = 0; i < 65; i++){
		dp[i][0] = 1;
	}
	
	// 1자리수의 경우 모두 줄어들지 않는수
	for(int i = 0; i < 10; i++){
		dp[1][i] = 1;
	}
						
		
	//dp
	for(int i = 2; i <= max_input; i++){
		for(int j = 1; j < 10; j++){
			// dp[2][2] 즉, 2자리수에서 마지막자리가 2가 올수있는 경우는
			// 2자리수에서 마지막자리가 1인경우의 수와 1자리수에서 마지막자리가 2인경우
			//이를 점화식으로 표현하면. 
			dp[i][j] = dp[i][j-1] + dp[i-1][j];
		}
	}
	
	//출력
	for(int i = 0; i < t; i++){
		int len = input[i];
		long long ans = 0;
		for(int i = 0; i < 10; i++){
			ans += dp[len][i];
		}
		cout << ans << "\n";
	} 
} 
