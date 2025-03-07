#include <iostream>
using namespace std;

int graph[1001][1001];
int dp[1001][1001];
int m, n;
int ans;
bool isAllObstacle = true;

// 블로그 참고
// 좀 어려웠지만 계속 생각하다보면 풀수 있는 문제
//  

int main(){
	cin >> m >> n;
	
	
	for(int i = 1; i <= m; i++){
		for(int j = 1; j<= n; j++){
			int input;
			cin >> input;
			//1, 2 장애물들은 -1로 통일 
			if(input > 0){
				graph[i][j] = -1;
			}
			else{
				graph[i][j] = 0;
				isAllObstacle = false;
			}
		}
	}
	
	//모두 장애물이면 정사각형 농장 못만듬. 
	if(isAllObstacle == true){
		cout << 0;
		return 0;
	}
	
	//n이나 m이 1인경우 만들 수 있는 농장크기는 무조건 1x1. 
	if(n == 1 || m == 1){
		cout << 1;
		return 0;
	} 
	
	// 각 공간 자체가 1m 크기이므로  1로 다 초기화. 
	for(int i = 1; i <= m; i++){
		for(int j = 1; j <=n; j++){
			dp[i][j] = 1;
		}
	}
	
	for(int i = 2; i <= m; i++){
		for(int j = 2; j<= n; j++){
			
			int left = graph[i][j-1];
			int up = graph[i-1][j];
			int diag = graph[i-1][j-1];
			int cnode = graph[i][j];
			
			// 현재 공간을 포함해 정사각형 농장이 될려면, 현재공간, 왼, 위, 대각선위 모두 땅이어야함. 
			if(left == 0 && up ==  0 && diag == 0 && cnode == 0){
			    // 대각선, 위, 왼 중 가장 작은 값 + 1 
			    dp[i][j] = min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1])) + 1;				
			}
			
			ans = max(ans, dp[i][j]);
		}
	}
	

	cout << ans;
}
