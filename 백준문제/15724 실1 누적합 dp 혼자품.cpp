#include <iostream>
#include <vector>
using namespace std;

int n, m;
int k;
int graph[1025][1025];
int dp[1025][1025];

int main(){
	
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cin >> graph[i][j];
		}
	}
	
	cin >> k;

	
	
	// 누적합 구하기 
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(i == 1){
				dp[i][j] = dp[i][j-1] + graph[i][j];
			} 
			else if(j == 1){
				dp[i][j] = dp[i-1][j] + graph[i][j];
			}
			else{
				dp[i][j] = dp[i][j-1] + dp[i-1][j] - dp[i-1][j-1] + graph[i][j];	
			}
			
		}
	}
	
	for(int i = 0; i < k; i++){
		int y1,x1,y2,x2;
		cin >> y1 >> x1 >> y2 >> x2;
		
		int ans = dp[y2][x2] - dp[y1-1][x2] - dp[y2][x1-1] + dp[y1-1][x1-1];
		
		cout << ans << "\n";
	}
	
	
}
