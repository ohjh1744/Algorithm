#include <iostream>
using namespace std;

int a[1001];
int dp[1001];


int main()
{
	int n;
	cin >> n;
	for(int i= 1; i<=n; i++){
		cin >> a[i] ; 
		dp[i] = 2e9; //무한범위 
	}
	
	dp[1] = 0; //1번쨰 칸은 점프 0번필요 
	for(int i=2; i<=n; i++){ // 각칸마다 몇번의 점프가 필요한지 반복문 
		for(int j= 1; j< i; j++){
			if(j+a[j] >= i){ // 각칸에서 i번째 칸을 갈수잇는지 구하는 조건문 
				dp[i] = min(dp[i], dp[j]+1);
			}
		}
	}	
	
	if(dp[n] == 2e9){
		cout << "-1" << endl;
	}
	else {
		cout << dp[n] << endl;
	}
	
	
	
}
