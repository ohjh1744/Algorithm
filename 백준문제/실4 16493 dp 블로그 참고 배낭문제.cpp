#include <iostream>
using namespace std;


// dp �߿� �賶���� 
int n, m;
int chapter[21][2]; // �� 20������ 0�� ��¥, 1�� page�� 
int dp[21][201]; // y �� chapter, x�� ����   i,j -> j���ڱ��� 1~ichapter�����дµ� �ִ� ������ ��  


int main(){
	cin >> n >> m;
	
	for(int i = 1; i <= m; i++){
		cin >> chapter[i][0] >> chapter[i][1];
	}
	
	
	for(int i = 1; i <= m; i++){
		for(int j = 1; j <= n; j++){
			//���� é�͸� ���� �� ���� ���
			if(chapter[i][0] > j){
				dp[i][j] = dp[i-1][j];
			}
			else{
			   //���� é�͸� ���� �� �ִ� ���
			   // ���� é�͸� ���аų� �д� ��� �� ���ϳ� ū ��. 
			   dp[i][j] = max(dp[i-1][j] , dp[i-1][j - chapter[i][0]] + chapter[i][1]); 	
			} 
			
			
		}
	}
	
	cout << dp[m][n] << "\n";
	
	
}
