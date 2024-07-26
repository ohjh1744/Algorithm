#include <iostream>
#include <queue>
using namespace std;

int n, r1, c1 , r2, c2;
int visited[200][200];



int dy[] = { -2, -2, 0, 0, 2, 2 };
int dx[] = { -1, 1, -2, 2, -1, 1 };

void bfs(int y, int x) // ct =0
{
	visited[y][x] = true;	
	queue< pair< pair< int , int> ,int > > q;
	q.push(make_pair(make_pair(y,x), 0));
	
	while(!q.empty()){
		int cy = q.front().first.first;
		int cx = q.front().first.second;
		int c_ct = q.front().second;
		
		if(cy == r2 && cx == c2){
			cout << c_ct << endl;
			return;
		}
		
		q.pop();
		for(int i = 0; i < 6; i++){
			int ny = cy + dy[i];  
			int nx = cx + dx[i];
			if(ny < 0 || nx < 0 || ny >= n || nx >= n){
				continue;
			}
			if(!visited[ny][nx]){
				visited[ny][nx] = true;
				q.push(make_pair(make_pair(ny, nx), c_ct+1 ));
			}
		}
	}
	cout << "-1" << endl;
	
}

int main()
{
	cin >> n;
	cin >> r1 >> c1 >> r2 >> c2;
	bfs(r1, c1);
}


