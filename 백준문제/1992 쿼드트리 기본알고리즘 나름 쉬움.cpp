#include <iostream>
using namespace std;


int n;
int graph[65][65];

// 쿼드트리 시간복잡도 n^2 * (1/2) * logn
// 1/2는 log밑이4라서 log밑을 2로바꾸면서 생김. 
void dfs(int y, int x, int s){
	
	if(s == 1){
		cout << graph[y][x] ;
		return;
	}
	
	bool Onlyzero = true;
	bool Onlyone = true;
	
	for(int i = y; i < y + s; i++){
		for(int j = x; j< x+s; j++){
			if(graph[i][j] == 1){
				Onlyzero = false;
			}
			else if(graph[i][j] == 0){
				Onlyone = false;
			}
		}
	}
	
	if(Onlyzero){
		cout << "0";
		return;
	}
	if(Onlyone){
		cout << "1";
		return;
	}
		
	cout << "(";
	dfs(y, x, s/2);
	dfs(y, x + (s/2) , s/2);
	dfs(y+ (s/2), x, s/2);
	dfs(y+ (s/2), x+ (s/2), s/2);
	cout << ")";
}


int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			scanf("%1d", &graph[i][j]);
		}
	}
	
	dfs(1, 1, n);	
	
}
