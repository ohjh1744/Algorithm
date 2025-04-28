#include <iostream>
#include <vector>
using namespace std;

int n, m, k; //n은 가로, m은세로 
long long dp[101][101];
vector < pair < pair < int, int> , pair < int, int > > > v; // 공사중인 다리 저장 


// 해당 경로가 공사중인지 확인 
bool CheckPath(int cy, int cx, int ny, int nx){
	for(int i = 0; i < v.size(); i++){
		
		int cantCy = v[i].first.first;
		int cantCx = v[i].first.second;
		int cantNy = v[i].second.first;
		int cantNx = v[i].second.second;
		
		if(cy == cantCy && cx == cantCx && ny == cantNy && nx == cantNx){
			return true;
		}
		// 반대도 확인 
		else if(cy == cantNy && cx == cantNx && ny == cantCy && nx == cantCx){
			return true;
		}
	}
	
	// 공사중이 아닌 경로라면 
	return false;
}

int main(){
	
	cin >> n >> m;
	cin >> k;
	
	
	for(int i = 0; i < k; i++){
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		v.push_back({{b, a}, {d, c}});
	}
	
	dp[0][0] = 1;
	// 항상 최단거리 = 특정 위치에서 왼쪽과 위쪽을 확인해서 갈수 있는경로면 각각 더해주기 
	for(int i = 0; i <= m ; i++){
		for(int j = 0; j <= n; j++){			
			if(i-1 >= 0){
				if(CheckPath(i-1, j, i, j) == false){
					dp[i][j] += dp[i-1][j];
				}
			}		
			if(j-1 >= 0){
				if(CheckPath(i, j - 1, i, j) == false){
					dp[i][j] += dp[i][j-1];
				}
			}		
		}
	}
	
	
	cout << dp[m][n];
	
}
