#include <iostream>
using namespace std;

int a[1001];
int dp[1001];


int main()
{
	int n;
	cin >> n;
	for(int i= 1; i<=n; i++){
		cin >> a[i] ; 
		dp[i] = 2e9; //���ѹ��� 
	}
	
	dp[1] = 0; //1���� ĭ�� ���� 0���ʿ� 
	for(int i=2; i<=n; i++){ // ��ĭ���� ����� ������ �ʿ����� �ݺ��� 
		for(int j= 1; j< i; j++){
			if(j+a[j] >= i){ // ��ĭ���� i��° ĭ�� �����մ��� ���ϴ� ���ǹ� 
				dp[i] = min(dp[i], dp[j]+1);
			}
		}
	}	
	
	if(dp[n] == 2e9){
		cout << "-1" << endl;
	}
	else {
		cout << dp[n] << endl;
	}
	
	
	
}
