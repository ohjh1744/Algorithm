#include <iostream>
#include <vector>
using namespace std;

int t; 
long long dp[65][10]; // dp[2][2] => 2�ڸ����߿� ������ �ڸ����� 2�� ���. 
int max_input;
int input[1001];

int main(){
	
	cin >> t;
	
	for(int i = 0; i < t; i++){
		cin >> input[i];
		
		if(max_input < input[i]){
			max_input = input[i];
		}
	}
	
	// �ǵڿ��� 0�� ���� �� �ڸ������� 1���� ��츸 ����. 
	for(int i = 0; i < 65; i++){
		dp[i][0] = 1;
	}
	
	// 1�ڸ����� ��� ��� �پ���� �ʴ¼�
	for(int i = 0; i < 10; i++){
		dp[1][i] = 1;
	}
						
		
	//dp
	for(int i = 2; i <= max_input; i++){
		for(int j = 1; j < 10; j++){
			// dp[2][2] ��, 2�ڸ������� �������ڸ��� 2�� �ü��ִ� ����
			// 2�ڸ������� �������ڸ��� 1�ΰ���� ���� 1�ڸ������� �������ڸ��� 2�ΰ��
			//�̸� ��ȭ������ ǥ���ϸ�. 
			dp[i][j] = dp[i][j-1] + dp[i-1][j];
		}
	}
	
	//���
	for(int i = 0; i < t; i++){
		int len = input[i];
		long long ans = 0;
		for(int i = 0; i < 10; i++){
			ans += dp[len][i];
		}
		cout << ans << "\n";
	} 
} 
