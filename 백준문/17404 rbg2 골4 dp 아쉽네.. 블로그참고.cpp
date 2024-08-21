#include <iostream>
#include <algorithm>

//https://tjdahr25.tistory.com/16 ���� 
using namespace std;

int input[1001][3];
int dp[1001][3];
int n;
int ans = 100000000;

int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++){
		int r, g, b;
		cin >> r >> g >> b;
		input[i][0] = r;
		input[i][1] = g;
		input[i][2] = b;
	}	
	
	// i�� ù���� r g b �� ���  
	for(int i = 0; i < 3; i++){
		
		//t�� ù���� r�϶� ���������, g�϶� ��������� ,b�϶� ���������  
		for(int t = 0; t < 3; t++){
			if(t == i){
				dp[1][t] = input[1][t];
			}
			else{  //���� ù���� r�϶� ���� ������츦 �����ϱ�����, i=1�϶� ù���� g�϶� �������� ��� ���� 
				dp[1][t] = 1000*1000+1;
			}
		}
		
		for(int j = 2; j <= n; j++){
			dp[j][0] = min(dp[j-1][1] , dp[j-1][2]) + input[j][0];
		    dp[j][1] = min(dp[j-1][0] , dp[j-1][2])+ input[j][1];
		    dp[j][2] = min(dp[j-1][0] , dp[j-1][1])+ input[j][2];
		}
		
		// ex)ù�� r�϶� ù�����򻩰� ������ ����� ������ ���� 
		for(int z = 0; z < 3; z++){
		    if(z == i){
		    	continue;
			}
			ans = min(ans , dp[n][z]); 
		}
	}
	
	cout << ans << "\n"; 
	
}
