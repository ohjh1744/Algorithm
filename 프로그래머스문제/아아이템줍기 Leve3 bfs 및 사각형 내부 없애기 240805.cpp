#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int graph[101][101];
int visited[101][101];
int dx[4] ={1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void bfs(int characterX, int characterY, int itemX, int itemY){
	visited[characterY][characterX] = true;
	queue < pair < int, int > > q;
	q.push({characterY, characterX});
	
	while(!q.empty()){
		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();
		if(cy == itemY && cx == itemX){
			return;
		}
		for(int i = 0; i < 4; i++){
			int ny = cy + dy[i];
			int nx= cx + dx[i];
			
			if(ny <= 0 || nx <= 0 || ny >= 101 || nx >= 101 ){
				continue;
			}
			if(!visited[ny][nx] && graph[ny][nx] == 1){
				visited[ny][nx] = visited[cy][cx] + 1;
				q.push({ny, nx});
			}
		}
		
	}
}
int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
     	int answer = 0;
	
	for(int i = 0; i < 101; i++){
		for(int j = 0; j < 101; j++){
			graph[i][j] = 0;
		}
	}
    
    for(int i = 0; i < rectangle.size(); i++){
    	int l_x = rectangle[i][0];
    	int l_y = rectangle[i][1];
    	int r_x = rectangle[i][2];
    	int r_y = rectangle[i][3];
    
			
    	for(int i = l_y*2; i <= r_y*2; i++){
    		for(int j = l_x*2; j <= r_x*2; j++){
    			if(i == l_y*2 || i == r_y*2 || j == l_x*2 || j == r_x*2){
    				graph[i][j] = 1;
				}
			}
		}			
	}  
	
	for(int i = 0; i < rectangle.size(); i++){
    	int l_x = rectangle[i][0];
    	int l_y = rectangle[i][1];
    	int r_x = rectangle[i][2];
    	int r_y = rectangle[i][3];
    
			
    	for(int i = l_y*2+1; i < r_y*2; i++){
    		for(int j = l_x*2+1; j < r_x*2; j++){
    			graph[i][j] = 0;
			}
		}			
	} 

    bfs(characterX * 2, characterY * 2,itemX * 2, itemY * 2);
    answer = visited[itemY*2][itemX*2] / 2;
    return answer;
}
