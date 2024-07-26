#include <bits/stdc++.h>
using namespace std;
// dy[i] == i무게일때 느낄 수 있는 최대 행복량 
int n, cost[21], point[21], dy[101];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> cost[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> point[i];
	}

	for (int i = 0; i <n; i++) {
		for (int j = 100; j >= cost[i]; j--) {
			dy[j] = max(dy[j], dy[j - cost[i]] + point[i]);
			cout << j << " " << j - cost[i] << " " << dy[j - cost[i]] << " " << dy[j] << endl;
		}
	}

	cout << dy[99];

}

https://hyeo-noo.tistory.com/16
#include <iostream>
#include <cstring>
using namespace std;
 
int N;
int Lost[21], Joy[21];
int dp[21][101];
 
void input(){
    cin >> N;
    
    for(int i = 1; i <= N; i++){
        cin >> Lost[i];
    }
    
    for(int i = 1; i <= N; i++){
        cin >> Joy[i];
    }
    memset(dp, 0, sizeof(dp));
}
 
void solve(){
    int result = 0;
    
    for(int i = 1; i <= N; i++){
        for(int h = 0; h <= 100; h++){
            // 인사 가능
            if(h + Lost[i] < 100){
                // max(인사 x,인사 o)
                // 현재 잃은 체력이 아직 포함되지 않은 이전 최대 기쁨[h+Lost[i]]에 현재 인사의 기쁨을 더해서 비교
                dp[i][h] = max(dp[i-1][h], dp[i-1][h+Lost[i]] + Joy[i]);
            }
            // 인사 불가능          원래 값, 이전 값 중 큰 값
            else dp[i][h] = max(dp[i][h], dp[i-1][h]); 
            
            if(dp[i][h] > result) result = dp[i][h];
        }
    }
    cout << result;
}
 
int main(){
    input();
    solve();
    
    return 0;
}
