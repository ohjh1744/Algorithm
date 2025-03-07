#include <iostream>
using namespace std;

int graph[1001][1001];
int dp[1001][1001];
int m, n;
int ans;
bool isAllObstacle = true;

// ��α� ����
// �� ��������� ��� �����ϴٺ��� Ǯ�� �ִ� ����
//  

int main(){
	cin >> m >> n;
	
	
	for(int i = 1; i <= m; i++){
		for(int j = 1; j<= n; j++){
			int input;
			cin >> input;
			//1, 2 ��ֹ����� -1�� ���� 
			if(input > 0){
				graph[i][j] = -1;
			}
			else{
				graph[i][j] = 0;
				isAllObstacle = false;
			}
		}
	}
	
	//��� ��ֹ��̸� ���簢�� ���� ������. 
	if(isAllObstacle == true){
		cout << 0;
		return 0;
	}
	
	//n�̳� m�� 1�ΰ�� ���� �� �ִ� ����ũ��� ������ 1x1. 
	if(n == 1 || m == 1){
		cout << 1;
		return 0;
	} 
	
	// �� ���� ��ü�� 1m ũ���̹Ƿ�  1�� �� �ʱ�ȭ. 
	for(int i = 1; i <= m; i++){
		for(int j = 1; j <=n; j++){
			dp[i][j] = 1;
		}
	}
	
	for(int i = 2; i <= m; i++){
		for(int j = 2; j<= n; j++){
			
			int left = graph[i][j-1];
			int up = graph[i-1][j];
			int diag = graph[i-1][j-1];
			int cnode = graph[i][j];
			
			// ���� ������ ������ ���簢�� ������ �ɷ���, �������, ��, ��, �밢���� ��� ���̾����. 
			if(left == 0 && up ==  0 && diag == 0 && cnode == 0){
			    // �밢��, ��, �� �� ���� ���� �� + 1 
			    dp[i][j] = min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1])) + 1;				
			}
			
			ans = max(ans, dp[i][j]);
		}
	}
	

	cout << ans;
}
