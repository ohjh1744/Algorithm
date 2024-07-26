#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n,m;
int py, px;
int hy, hx;

int dy[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
int dx[8] = {-2, -1, 1, 2, -2, -1, 1, 2};
int visited[501][501];
vector < pair < int, int > > v;

void bfs(int y , int x, int ct)
{
	visited[y][x] = true;
	queue < pair < pair < int, int > , int > >  q;
	q.push({{y, x}, ct});
	while(!q.empty()){
		int cy = q.front().first.first;
		int cx = q.front().first.second;
		int c_ct = q.front().second;
		
		q.pop();
		for(int i = 0; i < 8; i++){
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			int n_ct = c_ct+1;
			if(ny < 1 || nx < 1 || ny > n || nx > n){
				continue;
			}
			if(!visited[ny][nx]){
				q.push({{ny, nx}, n_ct});
				visited[ny][nx] = n_ct;
			}
		}
	}
}

int main()
{
	cin >> n >> m;
	cin >> py >> px;
	
	for(int i = 0; i < m; i++){
		cin >> hy >> hx;
		v.push_back({hy, hx});
	}
	
	bfs(py, px, 0);
	
	for(int i = 0; i < v.size(); i++){
		int cy = v[i].first;
		int cx = v[i].second;
		cout << visited[cy][cx] << " ";
	}
	
	return 0;
}
 
