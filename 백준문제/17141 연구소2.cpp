#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n , m;
int graph[50][50]; 
bool sel[2500]; // combi ���� ����ϴ� bool 
vector<int> v; // 2�� �� ���� 

int visited[50][50]; // ���ʹ��̷����� ���� 0, �����ȵȰ��� -1 
int dx[4] = {0 , 0, -1, 1};
int dy[4] = {1 , -1, 0, 0};

int ans = 99999999; 

bool spread() //���������� ��� �����̴��� Ȯ�� 
{
	for(int i = 0; i < n; i++){    
		for(int j = 0; j < n; j++){
			if(visited[i][j] == -1){
				return false;
			} 
		}
	}
	return true;
}

int bfs() //�ð� ���ϱ� 
{
	queue < pair < int, int > > q;
	int t_s = 0; 
	for(int i = 0; i < n; i++){    //���� ������ �� ��� visited -1�� �ʱ�ȭ 
		for(int j = 0; j < n; j++){
			if(graph[i][j] != 1){
				visited[i][j] = -1;
			} 
		}
	}
	for(int i = 0 ; i < v.size(); i++){
		if(sel[i] == true){
			int y = v[i] / n;
			int x = v[i] % n;
			q.push({y, x});
			visited[y][x] = 0;
		}
	}
	while(!q.empty()){
		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();
		for(int i = 0; i < 4; i++){
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			if(ny < 0 || nx < 0 || ny >=n || nx >= n){
				continue;
			}
			if(visited[ny][nx] == -1 && graph[ny][nx] != 1){
				q.push({ny, nx});
				visited[ny][nx] = visited[cy][cx] + 1;
				t_s = visited[ny][nx];  //�� �������� �����Ǵ�ĭ�� ��� ��ĭ ������Ű�µ� �ּҰɸ��� �ð�
			}
		}
		
	}
	
	return t_s;
	
}


void combi(int idx, int cnt)
{
	if(cnt == m){
		int spread_time = bfs();
		if(spread()){
			if(ans > spread_time){
				ans = spread_time;
			}
		}
		return;
	}
	
	for(int i = idx; i < v.size(); i++){
		if(sel[i] == true){
		   continue;
		}
		sel[i] = true;
		combi(i, cnt+1);
		sel[i] = false;
	}	
}

int main()
{
	cin >> n >> m;
	int ct = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> graph[i][j];
			if(graph[i][j] == 2){
				v.push_back(ct);
			}
			ct++;
		}
	}

	combi(0, 0);
	
	if(ans == 99999999){
		cout << "-1" << endl;
	}
	else{
		cout << ans << endl;
	}
	
}
