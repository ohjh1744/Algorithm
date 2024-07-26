#include <iostream>
#include <algorithm>
using namespace std;

int inf = 10000000;
int n;
int graph[51][51];
int point[51]; // 점수값 저장 

void floyd(){
	for(int k = 1; k <= n; k++){
		for(int i = 1; i <= n; i++){
			for(int j = 1 ; j <= n; j++){
				if(graph[i][j] > graph[i][k] + graph[k][j]){
					graph[i][j] = graph[i][k] + graph[k][j];
				}
			}
		}
	}
}

int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(i==j){
				graph[i][j] = 0;
			}
			else{
				graph[i][j] = inf;
			}
		}
	}
	while(true){
		int f1, f2;
		cin >> f1 >> f2;
		if(f1 == -1){
			break;
		}
		graph[f1][f2] = 1;
		graph[f2][f1] = 1;
	}
	
	floyd();
	
	int min_point = 100;
	
	for(int i = 1; i <=n; i++){
		for(int j = 1; j <=n; j++){
			point[i] = max(point[i], graph[i][j]);
		}
		min_point = min(min_point, point[i]);
	}
	
	cout << min_point << " ";
	int cnt = 0;
	for(int i = 1; i <=n; i++){
		if(point[i] == min_point){
			cnt++;
		}
	}
	cout << cnt << endl;
	for(int i = 1; i <=n; i++){
		if(point[i] == min_point){
			cout << i << " ";
		}
	}
	
}
