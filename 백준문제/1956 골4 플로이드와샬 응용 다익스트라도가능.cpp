#include <iostream>
#include <vector>
using namespace std;

int n;
int e;
int graph[401][401];

void floyd(){
	for(int k = 1; k <= n; k++){
		for(int i = 1; i <=n; i++){
			for(int j = 1; j <= n; j++){
				int temp = graph[i][k] + graph[k][j];
				if(graph[i][j] > temp){
					graph[i][j] = temp;
				}
			}
		}
	}
}

int main(){
	cin >> n >> e;
	
	//�ʱ�ȭ
	//���� �����̵� �ͼ��� ������ �ȵ������� ���Ѵ�, ������ 0���� �ϳ� ����Ŭ Ȯ���� ���� ���ε� ���Ѵ��. 
	for(int i = 1; i <=n; i++){
		for(int j = 1; j <= n; j++){
			graph[i][j] = 1e9;
		}
	} 
	
	for(int i = 0; i < e; i++){
		int n, m, d;
		cin >> n >>  m >> d;
		graph[n][m] = d;
	}
	
	floyd();
	
	int ans = 1e9;
	
	for(int i = 1; i <= n; i++){
		if(graph[i][i] < ans){
			ans = graph[i][i];
		}
	} 
	
	//����Ŭ�� ���°�� 
	if(ans == 1e9){
		cout << -1;
	}
	else{
		cout << ans ;
	}
	
}
