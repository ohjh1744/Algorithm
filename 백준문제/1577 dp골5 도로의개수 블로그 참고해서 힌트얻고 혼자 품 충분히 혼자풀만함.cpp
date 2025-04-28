#include <iostream>
#include <vector>
using namespace std;

int n, m, k; //n�� ����, m������ 
long long dp[101][101];
vector < pair < pair < int, int> , pair < int, int > > > v; // �������� �ٸ� ���� 


// �ش� ��ΰ� ���������� Ȯ�� 
bool CheckPath(int cy, int cx, int ny, int nx){
	for(int i = 0; i < v.size(); i++){
		
		int cantCy = v[i].first.first;
		int cantCx = v[i].first.second;
		int cantNy = v[i].second.first;
		int cantNx = v[i].second.second;
		
		if(cy == cantCy && cx == cantCx && ny == cantNy && nx == cantNx){
			return true;
		}
		// �ݴ뵵 Ȯ�� 
		else if(cy == cantNy && cx == cantNx && ny == cantCy && nx == cantCx){
			return true;
		}
	}
	
	// �������� �ƴ� ��ζ�� 
	return false;
}

int main(){
	
	cin >> n >> m;
	cin >> k;
	
	
	for(int i = 0; i < k; i++){
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		v.push_back({{b, a}, {d, c}});
	}
	
	dp[0][0] = 1;
	// �׻� �ִܰŸ� = Ư�� ��ġ���� ���ʰ� ������ Ȯ���ؼ� ���� �ִ°�θ� ���� �����ֱ� 
	for(int i = 0; i <= m ; i++){
		for(int j = 0; j <= n; j++){			
			if(i-1 >= 0){
				if(CheckPath(i-1, j, i, j) == false){
					dp[i][j] += dp[i-1][j];
				}
			}		
			if(j-1 >= 0){
				if(CheckPath(i, j - 1, i, j) == false){
					dp[i][j] += dp[i][j-1];
				}
			}		
		}
	}
	
	
	cout << dp[m][n];
	
}
