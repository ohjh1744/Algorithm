#include <iostream>
#include <algorithm>
using namespace std;

int dp[1001];
char temp[1001];
int n;

int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++){
	    cin >> temp[i];
	    dp[i] = 999999999;
	}
	
	dp[1] = 0;
	for(int i = 1; i <= n; i++){
		char c = temp[i];		
		if(c == 'B'){
			for(int j = i+1; j <= n; j++){
				if(temp[j] == 'O'){
					dp[j] = min(dp[j] , dp[i] + ((j-i)*(j-i)));
				}
			}
		}
		else if(c == 'O'){
			for(int j = i+1; j <= n; j++){
				if(temp[j] == 'J'){
					dp[j] = min(dp[j] , dp[i] + ((j-i)*(j-i)));
				}
			}
		}
		else if(c == 'J'){
			for(int j = i+1; j <= n; j++){
				if(temp[j] == 'B'){
					dp[j] = min(dp[j] , dp[i] + ((j-i)*(j-i)));
				}
			}	
		}	
	}
	
	if(dp[n] == 999999999){
		cout << "-1" << "\n";
	}
	else{
		cout << dp[n] << "\n";
	}
	
}
