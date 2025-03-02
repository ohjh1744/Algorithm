#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
string dp[251];

//큰수 계산 string을 통해 
string sum(string s1, string s2){
	int s1_len = s1.length();
	int s2_len = s2.length();
	string result = "";
	
	int i = s1_len - 1;
	int j = s2_len - 1;
	int carry = 0;
	
	while(i >= 0 || j >= 0|| carry > 0){
		// carry로 인해 배열의 끝을 넘어서는 경우 0으로 처리. 
		int num1 = (i >= 0) ? s1[i] -'0' : 0;
		int num2 = (j >= 0) ? s2[j] -'0' : 0;
		
		int sum = num1 + num2 + carry;
		result += (sum % 10) + '0';
		carry = sum/ 10;
		
		i--;
		j--;
	}
	reverse(result.begin(), result.end());
	
	return result;
}

int main(){
	
	dp[0] = "1";
	dp[1] = "1";
	dp[2] = "3";
	
	for(int i = 3; i < 251; i++){
		dp[i] = sum(dp[i-1], sum(dp[i-2], dp[i-2]));
	}
	
	
	while(cin >> n){
		cout << dp[n] << "\n";
	}
} 
