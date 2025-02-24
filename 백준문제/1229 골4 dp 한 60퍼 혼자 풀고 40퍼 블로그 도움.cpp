#include <iostream>
using namespace std;

// ������ hn -> �Ѻ��� ���� n���� �������� �� ���� ���� 
int h[1000001];

//���� ������ ���� 
int h_n;

int n;
// ���� N�� �Ǵ� ������ ������ �ּ҃� dp[1] N��1. 
int dp[1000001];

int main(){
	
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
	
	cin >> n;
	
	h[1] = 1;
	h[2] = 6; 
	
	h_n = 2;
	
	//������ ���ϱ�
	//�������� �� ������ n���� ũ�� ����������  ���ϱ� 
	for(int i = 3; i < 1000001; i++){
		h[i] = ((i * 6) - 6) + (h[i-1] - h[i-1]/(i-1));
		
		if(h[i] > n){
			break;
		}
		
		h_n++;
	} 
	
	//dp �ʱ�ȭ 
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
