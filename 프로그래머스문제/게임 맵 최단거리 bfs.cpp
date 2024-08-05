#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int visited[101][101];
int dx[4] = {1,-1,0 ,0};
int dy[4] = {0, 0, -1, 1};
int n, m;

int bfs(int y, int x, vector<vector<int> > maps){
	
    n = maps.size();
    m = maps[0].size();
	for(int i = 0; i <= n; i++){
		for(int j = 0; j <=m; j++){
			visited[i][j] = 0;
		}
	}
	visited[y][x] = true;
	queue< pair < int, int > > q;
	q.push({y, x});
	
	while(!q.empty()){
		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();
		
		if(cy == n-1 && cx == m-1){
			return visited[cy][cx];
		}
		for(int i = 0; i < 4; i++){
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			
			if(ny < 0 || nx < 0 || ny >= n || nx >= m )
			{
				continue;
			}
            if(maps[ny][nx] == 0){
                continue;
            }			
			if(!visited[ny][nx]){
                q.push({ny, nx});
				visited[ny][nx] = visited[cy][cx] + 1;
			}
		}
	}
    return -1;
}

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    answer = bfs(0, 0, maps);
    return answer;
}
