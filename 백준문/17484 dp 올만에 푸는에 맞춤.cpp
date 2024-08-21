#include <iostream>
#include<algorithm>
using namespace std;

int x , y;
int graph[7][7];
int dp[7][7][3]; //마지막방향 
int result = 999999;

int main()
{
	
	cin.tie(0);
	cout.tie(0);
	cin >> y >> x;
	
	for(int i = 0; i <= y+1; i++){
		for(int j = 0; j <= x+1; j++){
			dp[i][j][0] = 999999;
			dp[i][j][1] = 999999;
			dp[i][j][2] = 999999;
		}
	}
	
	
		
	for(int i = 1; i <= y; i++){
		for(int j = 1; j <= x; j++){
			cin  >> graph[i][j];
			if(i == 1){
				dp[i][j][0] = graph[i][j];
				dp[i][j][1] = graph[i][j];
				dp[i][j][2] = graph[i][j];
			}
		}
	}

	
	for(int i = 2; i <= y; i++){
		for(int j = 1; j <= x; j++){			
			dp[i][j][0] = graph[i][j] + min(dp[i-1][j+1][1], dp[i-1][j+1][2]);
			dp[i][j][1] = graph[i][j] + min(dp[i-1][j][0], dp[i-1][j][2]);
			dp[i][j][2] = graph[i][j] + min(dp[i-1][j-1][0], dp[i-1][j-1][1]);
		}
		
		
	}
	
	
	for(int i = 1; i <= x; i++){
		int short_path = min(dp[y][i][0], min(dp[y][i][1], dp[y][i][2]));
		if(result > short_path){
			result = short_path;
		}
    }
    
    cout << result;
	
}
