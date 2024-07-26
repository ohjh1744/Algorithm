#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//https://astrid-dm.tistory.com/439 참고 
int dp[10001];  //n 까지의 최소거리
vector < pair < int, int > > v[10001]; // 시작지점, 거리 
int n, d;
int main()
{
	cin >> n >> d;
	for(int i = 0; i < n; i++){
		int start, end, l;
		cin >> start >> end >> l;
		v[end].push_back({start, l}); 
	}
	
	for(int i = 1; i <= d; i++){
		dp[i] = i;
		if(v[i].empty()){
			dp[i] = dp[i-1] + 1;
		}
		else{
			for(int j = 0; j < v[i].size(); j++){
				dp[i] = min(dp[i] , min(dp[i-1] + 1 , dp[v[i][j].first] + v[i][j].second));
			}
		}
		cout <<  i << " " << dp[i] << endl;
	}
	
	cout << dp[d] << "\n";
	
}
