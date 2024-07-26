#include <iostream>
#include <algorithm>
using namespace std;


int dp[51][1001]; // i번째 m크기만큼 볼륨 가능 
int v[51];
int n, s, m;
int ans;

int main()
{
	cin >> n >> s >> m;
	for(int i = 1; i <= n; i++){
		cin >> v[i];
	}
	dp[0][s] = 1;
	
	for(int i = 1 ; i <= n; i++){
		for(int j = 0; j <= m; j++){
			if(dp[i-1][j] == 1){
				if(j + v[i] <= m){
					dp[i][j+v[i]] = 1;
				}
				if(j - v[i] >= 0){
					dp[i][j-v[i]] = 1;
				}
			}
		} 
	}
	ans = -1;
	for(int i = 0; i <= m; i++){
		if(dp[n][i] == 1){
			ans = max(ans , i);
		} 
	}

	cout << ans << "\n";
	
}
//https://luv-n-interest.tistory.com/1257 참고
 
