#include <iostream>
#include <vector>
#define maxSize 1000000000
using namespace std;

long long dp[1001][10]; // i길이, 마지막 비밀번호 j.  
int t;

int temp[10][4] = {
	{7, maxSize, maxSize, maxSize},
	{2, 4, maxSize, maxSize},
	{1, 3, 5, maxSize},
	{2, 6, maxSize, maxSize},
	{1, 5, 7, maxSize},
	{2, 4, 6, 8},
	{3, 5, 9, maxSize},
	{4, 8, 0, maxSize},
	{5, 7, 9, maxSize},
	{6, 8, maxSize, maxSize},
};

int main(){
		
	//dp[1] 계산 
	for(int i = 0; i < 10; i++){
		dp[1][i] = 1;
	}
	
	//전체 dp 계산
	for(int i = 2; i < 1001; i++){
		for(int j = 0; j < 10; j++){
			for(int z = 0; z < 4; z++){
				int near = temp[j][z];
				if(near == 1e9){
					continue;
				}
				dp[i][j] += dp[i-1][near] % 1234567;
			}
		}
	} 
	
	cin >> t;
	
	for(int i = 0; i < t; i++){
		int num;
		cin >> num;
		int ans = 0;
		for(int j = 0; j < 10; j++){
			ans += dp[num][j] % 1234567;
		}
		cout << ans % 1234567 << "\n";
	}
	
	
} 
