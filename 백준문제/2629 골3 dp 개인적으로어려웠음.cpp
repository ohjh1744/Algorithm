#include <iostream>
#include <cmath>
using namespace std;


//~i추까지 하여 j무게를 확인가능하면 1, 아니면 0 
int dp[31][15001]; // 추, 확인 가능한  구슬 무게 

int n, m;
int weigh[31]; // 추의 무게 

int main(){
	cin >> n;
	
	for(int i = 1; i <= n; i++){
		cin >> weigh[i];
	}
	
	dp[1][weigh[1]] = 1;
	
	for(int i = 2; i <= n; i++){
		// 현재 추의 무게와 구하려는 무게가 같다면  
		dp[i][weigh[i]] = 1;
		for(int j = 1; j <= 15000; j++){
			// 이전 추까지 사용해서 j 무게를 이미 구했다면 
			if(dp[i-1][j] == 1){
				// j+ 현재 추 무게의 값도 구할 수 있음. 
				dp[i][j + weigh[i]] = 1;			 
				dp[i][j] = 1;
				dp[i][abs(j - weigh[i])] = 1;
			}
		}
	}

	
	cin >> m;
	
	for(int i = 0; i < m; i++){
		int ball;
		cin >> ball;
		
		if(ball > 15000){
			cout << "N ";
		} 			
		else if(dp[n][ball] == 1){
			cout << "Y ";
		}
		else{
			cout << "N ";
		}		
	}
	
}
