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
	
	//초기화
	//원래 프로이드 와샬은 연결이 안된정점은 무한대, 본인은 0으로 하나 사이클 확인을 위해 본인도 무한대로. 
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
	
	//사이클이 없는경우 
	if(ans == 1e9){
		cout << -1;
	}
	else{
		cout << ans ;
	}
	
}
