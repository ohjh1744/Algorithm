#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector< int > v[1001];
int visited[1001];
int a, b, n, m;

void bfs(int start){
	visited[start] = 1;
	queue < int > q;
	q.push(start);
	while(!q.empty()){
		int cn = q.front();
		q.pop();
		
		if(cn == b){
			break;
		}
		
		for(int i = 0; i < v[cn].size(); i++){
			int nn = v[cn][i];
			if(visited[nn] == false){
				q.push(nn);
				visited[nn] = visited[cn] + 1;
			}
		}
	}
}

int main(){
	cin >> a >> b;
	cin >> n >> m;
	
	for(int i = 0; i < m; i++){
		int num1, num2;
		cin >> num1 >> num2;
		v[num1].push_back(num2);
		v[num2].push_back(num1);
	}
	
	bfs(a);
	
	if(visited[b] == false){
		cout << -1;
	}
	else{
		cout << visited[b] - 1;
	}
	
}
