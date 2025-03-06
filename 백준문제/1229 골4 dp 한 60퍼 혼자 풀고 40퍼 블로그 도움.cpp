#include <iostream>
using namespace std;

// 육각수 hn -> 한변에 점이 n개인 육각형의 총 점의 개수 
int h[1000001];

//구한 육각수 개수 
int h_n;

int n;
// 합이 N이 되는 육각수 개수의 최소깂 dp[1] N이1. 
int dp[1000001];

int main(){
	
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
	
	cin >> n;
	
	h[1] = 1;
	h[2] = 6; 
	
	h_n = 2;
	
	//육각수 구하기
	//육각수의 점 개수가 n보다 크지 않을때까지  구하기 
	for(int i = 3; i < 1000001; i++){
		h[i] = ((i * 6) - 6) + (h[i-1] - h[i-1]/(i-1));
		
		if(h[i] > n){
			break;
		}
		
		h_n++;
	} 
	
	//dp 초기화 
	for(int i = 0; i <= n; i++){
		dp[i] = i;
	}

	for(int i = 6; i <= n; i++){
		for(int j = 1; j <= h_n; j++){
			if(i >= h[j]){
				dp[i] = min(dp[i] , dp[i-h[j]] + 1);
			}
		}
	}
	
	cout << dp[n] << "\n";
	
	
}
