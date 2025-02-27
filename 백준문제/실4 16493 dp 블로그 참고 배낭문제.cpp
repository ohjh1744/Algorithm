#include <iostream>
using namespace std;


// dp 중에 배낭문제 
int n, m;
int chapter[21][2]; // 총 20개까지 0은 날짜, 1은 page수 
int dp[21][201]; // y 는 chapter, x는 일자   i,j -> j일자까지 1~ichapter까지읽는데 최대 페이지 수  


int main(){
	cin >> n >> m;
	
	for(int i = 1; i <= m; i++){
		cin >> chapter[i][0] >> chapter[i][1];
	}
	
	
	for(int i = 1; i <= m; i++){
		for(int j = 1; j <= n; j++){
			//현재 챕터를 읽을 수 없는 경우
			if(chapter[i][0] > j){
				dp[i][j] = dp[i-1][j];
			}
			else{
			   //현재 챕터를 읽을 수 있는 경우
			   // 현재 챕터를 안읽거나 읽는 경우 둘 중하나 큰 값. 
			   dp[i][j] = max(dp[i-1][j] , dp[i-1][j - chapter[i][0]] + chapter[i][1]); 	
			} 
			
			
		}
	}
	
	cout << dp[m][n] << "\n";
	
	
}
