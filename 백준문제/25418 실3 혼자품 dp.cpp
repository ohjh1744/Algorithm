#include <iostream>
using namespace std;

int dp[1000001]; // i�� ���ϴµ� �ʿ��� �ּ� ���� ��  
int a, k;
 
int main(){
	cin >> a >> k;
	
	
	for(int i = a+1; i <= k; i++){
		//¦���̸鼭 ����2�� ��밡���Ѱ�� 
		if(i %2 == 0 && i/2 >= a){
			dp[i] = min(dp[i-1], dp[i/2]) + 1;
		}
		else{
			dp[i] = dp[i-1] + 1;
		}
	}
	
	cout << dp[k]; 
}
