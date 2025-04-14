#include <iostream>
using namespace std;

int dp[1000001]; // i를 구하는데 필요한 최소 연산 수  
int a, k;
 
int main(){
	cin >> a >> k;
	
	
	for(int i = a+1; i <= k; i++){
		//짝수이면서 연산2를 사용가능한경우 
		if(i %2 == 0 && i/2 >= a){
			dp[i] = min(dp[i-1], dp[i/2]) + 1;
		}
		else{
			dp[i] = dp[i-1] + 1;
		}
	}
	
	cout << dp[k]; 
}
