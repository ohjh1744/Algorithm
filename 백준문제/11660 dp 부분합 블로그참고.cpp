#include <iostream>
using namespace std;

int ori_graph[1025][1025];
int dp[1025][1025];
int n, m;

int main()
{
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cin >> ori_graph[i][j];
			dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + ori_graph[i][j];
		}
	}
	
	for(int i = 1; i <= m; i++){
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		cout << dp[x2][y2] - dp[x1 -1][y2] - dp[x2][y1 - 1] + dp[x1-1][y1-1] << '\n';
	} 
	

}
