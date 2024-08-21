#include <iostream>
using namespace std;

//https://yabmoons.tistory.com/116

long long dp[101][101]; // ��ĭ�� �ü��ִ� ��� 
int graph[101][101];
int n;

int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cin >> graph[i][j];
		}
	}
	dp[1][1] = 1;
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(dp[i][j] == 0 || (i == n && j == n)){
				continue;
			}
			int jump = graph[i][j];
			//�����ϱ� �� �ڸ����� ���� ��� + �����ϰ� ������ �ڸ����� ���� ���
			if(j + jump <= n){
				dp[i][j + jump] = dp[i][j + jump] + dp[i][j];  
			} 
			if(i+ jump <= n){
				dp[i + jump][j] = dp[i + jump][j] + dp[i][j];
			}			
		}
	}
	
	cout << dp[n][n] << "\n";
	
	
}
