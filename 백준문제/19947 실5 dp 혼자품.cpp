#include <iostream>
#include <math.h>
using namespace std;


int dp[11];
float plusMoney[3] = {0.05, 0.2, 0.35};
int year[3] = {1, 3, 5};
int h, y; 

int main(){
	cin >> h >> y;
	
	dp[0] = h;
	dp[1] = h + (h * 0.05);
	
	for(int i = 2; i <= y; i++){
		for(int j = 0; j <= 2; j++){
			if(i- year[j]>= 0){
				dp[i]= max( dp[i] , dp[i-year[j]] + int((trunc(dp[i-year[j]] * plusMoney[j]))) );
			}
		}
	}
	
	cout << dp[y];
}
