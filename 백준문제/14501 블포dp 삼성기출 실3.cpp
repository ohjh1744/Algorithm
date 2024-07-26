#include <iostream>
#include <algorithm>
using namespace std;

int t[17];
int p[17];
int dp[17];


int main()
{
	int n;
	cin >> n;
	
	for(int i = 1; i <= n ; i++){
		cin >> t[i] >> p[i];
	}
	
	for(int i = n; i >= 1; i--){ // �Ųٷ� ���� 
		if( t[i]> n-i+1){   
			dp[i] = dp[i+1]; // ���ϳ� ����ϼ��� n�� �ѱ�� �״��������� �ִ������� �״��ϳ� �ִ����� 
		}
		else{ //�ƴ϶�� 
			dp[i] = max(dp[i+1] , p[i] + dp[i+ t[i]]); // ������������ �ִ����Ͱ� ���ϳξ�� ���Ͱ� ����ϼ��� �������� �ִ����� �� 
		}
	}
	
	cout << dp[1] << endl;
	
	
}
// �Ʒ��� �� ����� �����ϱ� �����ϴ� �κм������������� ���Ǯ�� 
//https://ongveloper.tistory.com/250
#include <iostream>
#include <algorithm>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int dp[16] = { 0 };
	int pay[16] = { 0 };
	int time[16] = { 0 };
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> time[i] >> pay[i];
		for (int j = 0; j < i; j++) {
			if (time[j] + j <= i &&i+time[i]<=n+1) {
				dp[i] = max(dp[i], dp[j]+pay[i]);
			}
		}
	}
	int answer = 0;
	for (int i = 0; i <= n; i++) {
		answer = max(answer, dp[i]);
	}
	cout << answer;
	

	return 0;
}
