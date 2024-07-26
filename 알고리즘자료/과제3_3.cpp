#include <iostream>
#include <algorithm>
using namespace std;

string a;
string b;
string c;


int dp[101][101][101];

int main()
{
	cin >> a;
	cin >> b;
	cin >> c;
	a = " " + a;
	b = " " + b;
	c = " " + c; 
	
	for(int i = 1; i <int(a.length()); i++){
		for(int j = 1; j < int(b.length()); j++){
			for(int k = 1; k < int(c.length()); k++){
				if(a[i] == b[j] && b[j] == c[k]){
					dp[i][j][k] = dp[i-1][j-1][k-1] + 1;
				}
				else{
					dp[i][j][k] = max(max(dp[i-1][j][k], dp[i][j-1][k]), dp[i][j][k-1]);
				}
			}
		}
	}
	
	cout << dp[int(a.length())-1][int(b.length())-1][int(c.length())-1] << "\n";
	
	
	
}
