#include <bits/stdc++.h>
using namespace std;
// dy[i] == i�����϶� ���� �� �ִ� �ִ� �ູ�� 
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
            // �λ� ����
            if(h + Lost[i] < 100){
                // max(�λ� x,�λ� o)
                // ���� ���� ü���� ���� ���Ե��� ���� ���� �ִ� ���[h+Lost[i]]�� ���� �λ��� ����� ���ؼ� ��
                dp[i][h] = max(dp[i-1][h], dp[i-1][h+Lost[i]] + Joy[i]);
            }
            // �λ� �Ұ���          ���� ��, ���� �� �� ū ��
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
