#include <iostream>
#include <vector>
using namespace std;

int n;
int k;
vector < pair < int , int > > things; // 무게와 가치  
int dp[101][100001]; // 첫번째부터 i번째 가방까지 j무게까지의 최대 가치.   

int main(){
	cin >> n >> k;
	
	for(int i = 0; i < n; i++){
		int w, v;
		cin >> w >> v;
		things.push_back({w, v});
	}
	
	// 배낭 dp
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= k; j++){

			int w = things[i-1].first;
			int v = things[i-1].second;
			// 해당 물건을 포함 못하는  경우 
			if(j < w ){
				dp[i][j] = dp[i-1][j];
			}
			// 해당 물건을 포함 할 수있는 경우 
			// 이전 물건까지 포함한 j무게의 무게 vs 이전 물건까지 포함한 j-w무게에서 현재 무게 포함. 
			else{
				dp[i][j] = max(dp[i-1][j] , dp[i-1][j-w] + v);
			} 
			// 해당 물건을 들수 있는경우 
		}
	} 
	
	cout << dp[n][k];
	
} 
