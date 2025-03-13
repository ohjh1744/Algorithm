#include <iostream>
#include <cmath>
using namespace std;


//~i�߱��� �Ͽ� j���Ը� Ȯ�ΰ����ϸ� 1, �ƴϸ� 0 
int dp[31][15001]; // ��, Ȯ�� ������  ���� ���� 

int n, m;
int weigh[31]; // ���� ���� 

int main(){
	cin >> n;
	
	for(int i = 1; i <= n; i++){
		cin >> weigh[i];
	}
	
	dp[1][weigh[1]] = 1;
	
	for(int i = 2; i <= n; i++){
		// ���� ���� ���Կ� ���Ϸ��� ���԰� ���ٸ�  
		dp[i][weigh[i]] = 1;
		for(int j = 1; j <= 15000; j++){
			// ���� �߱��� ����ؼ� j ���Ը� �̹� ���ߴٸ� 
			if(dp[i-1][j] == 1){
				// j+ ���� �� ������ ���� ���� �� ����. 
				dp[i][j + weigh[i]] = 1;			 
				dp[i][j] = 1;
				dp[i][abs(j - weigh[i])] = 1;
			}
		}
	}

	
	cin >> m;
	
	for(int i = 0; i < m; i++){
		int ball;
		cin >> ball;
		
		if(ball > 15000){
			cout << "N ";
		} 			
		else if(dp[n][ball] == 1){
			cout << "Y ";
		}
		else{
			cout << "N ";
		}		
	}
	
}
