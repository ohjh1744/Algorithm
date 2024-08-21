#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

int n, l, r;
int graph[51][51];
int visited[51][51]; 
int dx[4] = {0 , 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int ct; // ��¥�� ���� 
bool b = false; //���� �����ϸ� true 
 
void bfs(int y, int x)   
{
	visited[y][x] = true;
	queue < pair < int, int > > q;
	vector < pair < pair <int, int > , int > >v; // �����α���������� �������  y��x ��ǥ�� �� ����ǥ�ǰ� 
    q.push({y, x});
	while(!q.empty()){
		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();
		v.push_back({{cy, cx} , graph[cy][cx]});
		for(int i = 0; i < 4; i++){
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			if(ny < 1 || nx < 1 || ny > n || nx > n){
				continue;
			}
			if(!visited[ny][nx] && abs(graph[cy][cx] - graph[ny][nx]) >= l && abs(graph[cy][cx] - graph[ny][nx]) <= r){
				q.push({ny, nx});
				visited[ny][nx] = true;   
				b = true; //���� �����ϸ�  
			}
		}
	}
	
	int human = 0;  
	for(int i = 0; i < v.size(); i++){ // ��ǥ�� �� �����ֱ� 
		human = human + v[i].second;
	}
	human = human / v.size();  // �����ֱ� 
	 
	for(int i = 0; i < v.size(); i++){
		graph[v[i].first.first][v[i].first.second] = human; // �α��̵� 
	}

	 
}

void reset()  //�湮�ʱ�ȭ 
{
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			visited[i][j] = false;
		}
	}
}

int main()
{
	cin >> n >> l >> r;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cin >> graph[i][j];
		}
	}
	
	while(1){
		b = false;
		reset();
		for(int i = 1; i <= n; i++){
		    for(int j = 1; j <= n; j++){
		    	if(!visited[i][j]){
		    		bfs(i, j);
				}
		    }
	    }
		if(b == false){ // ������ �������� ������ 
			cout << ct ;
			return 0;
		}
		ct++;	//��¥�� ����	
	}
	  
	  
}
