#include <iostream>
#include <vector>
using namespace std;

int n;
int k;
vector < pair < int , int > > things; // ���Կ� ��ġ  
int dp[101][100001]; // ù��°���� i��° ������� j���Ա����� �ִ� ��ġ.   

int main(){
	cin >> n >> k;
	
	for(int i = 0; i < n; i++){
		int w, v;
		cin >> w >> v;
		things.push_back({w, v});
	}
	
	// �賶 dp
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= k; j++){

			int w = things[i-1].first;
			int v = things[i-1].second;
			// �ش� ������ ���� ���ϴ�  ��� 
			if(j < w ){
				dp[i][j] = dp[i-1][j];
			}
			// �ش� ������ ���� �� ���ִ� ��� 
			// ���� ���Ǳ��� ������ j������ ���� vs ���� ���Ǳ��� ������ j-w���Կ��� ���� ���� ����. 
			else{
				dp[i][j] = max(dp[i-1][j] , dp[i-1][j-w] + v);
			} 
			// �ش� ������ ��� �ִ°�� 
		}
	} 
	
	cout << dp[n][k];
	
} 
