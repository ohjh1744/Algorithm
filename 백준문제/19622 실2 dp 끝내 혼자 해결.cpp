#include <iostream>
using namespace std;

int dp[100001]; // i회의를 선택했을때 가장 큰 인원 
int n;
int ans = 0;
int main(){
 	cin >> n;
 	for(int i = 1; i <= n; i++){
 		int start, end, cost;
 		cin >> start>> end >> cost;
 		dp[i] = cost;
 		
 		// i번째 회의는 i-1, i+1를 제외한 회의들과는 겹치지 않으므로 
 		// i번째 회의를 선택할 수 있는 경우는 i-2와 i-3. 
 		// 사실상 start 와 end는 필요가x. 
		if(i >= 3){
 			dp[i] = max(dp[i-2] + cost, dp[i-3] + cost);
		}
		
		if(ans < dp[i]){
			ans = dp[i];
		} 
		
	}
	
	cout << ans;

}
