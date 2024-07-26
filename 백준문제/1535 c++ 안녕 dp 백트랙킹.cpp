#include <iostream>
#include <algorithm>
using namespace std;

// 백트랙킹 블로그참고함. . 
int n;
int sad[21];
int happy[21];
int ans;
int dp[101];
void dfs(int ct , int hp, int smile)
{
	if(hp <= 0 || ct >= n){
		if(hp <= 0){
			return;
		}
		else{
			ans = max(ans, smile);
			return;
		}
	}
	
	ans = max(ans, smile);
	
	dfs(ct+1, hp - sad[ct], smile + happy[ct]);
	dfs(ct+1, hp, smile);
}

int main()
{
	cin >> n;
	for(int i = 0 ;i< n; i++){
		int health;
		cin >> health;
		sad[i] = health;
	}
	
	for(int i = 0;i< n; i++){
		int health;
		cin >> health;
		happy[i] = health;
	}
	
	dfs(0, 100, 0);
	cout << ans << endl;

	
}
