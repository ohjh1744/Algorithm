#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n;
char graph[6][6];
vector <int> v; // X공간 저장 0 2 3 6 ~
vector <int> student; // 학생 위치 저장 
bool visited[36]; //dfs에서 사용하는 방문처리 

int b_visited[6][6];
int dx[4] = {0, 0 , -1, 1};
int dy[4] = {-1, 1, 0, 0};  //북 남 서 동 
bool cant_escape; 


void bfs() // 선생님 감시 피할수있는지 없는지 
{
    queue < pair < int, int > >	q;
    for(int i = 0; i < student.size(); i++){
    	int y = student[i] / n;
    	int x = student[i] % n;
    	q.push({y, x});
	}
	while(!q.empty()){       // 북, 남 방향 
		int cy = q.front().first;
		int cx = q.front().second;
		b_visited[cy][cx] = true;
		q.pop();
		for(int i = 0; i < 2; i++){
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			if(ny < 0 || nx < 0 || ny >= n || nx >= n){
				continue;
			}
			if(graph[ny][nx] == 'O'){
				continue;
			}
			if(!b_visited[ny][nx] && graph[ny][nx] == 'X'){
				q.push({ny, nx});
			}
			if(!b_visited[ny][nx] && graph[ny][nx] == 'S'){
				q.push({ny, nx});
			}
			if(!b_visited[ny][nx] && graph[ny][nx] == 'T'){
				q.push({ny, nx});
				cant_escape = true;
			}
		}
	}
	for(int i = 0; i < n; i++){   //방문 초기화 
		for(int j = 0; j < n; j++){
			b_visited[i][j] = 0;
		}
	}
	for(int i = 0; i < student.size(); i++){
    	int y = student[i] / n;
    	int x = student[i] % n;
    	q.push({y, x});
	}
	while(!q.empty()){       // 서, 남 방향 
		int cy = q.front().first;
		int cx = q.front().second;
		b_visited[cy][cx] = true;
		q.pop();
		for(int i = 2; i < 4; i++){
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			if(ny < 0 || nx < 0 || ny >= n || nx >= n){
				continue;
			}
			if(graph[ny][nx] == 'O'){
				continue;
			}
			if(!b_visited[ny][nx] && graph[ny][nx] == 'X'){
				q.push({ny, nx});
			}
			if(!b_visited[ny][nx] && graph[ny][nx] == 'S'){
				q.push({ny, nx});
			}
			if(!b_visited[ny][nx] && graph[ny][nx] == 'T'){
				q.push({ny, nx});
				cant_escape = true;
			}
		}
	}
	for(int i = 0; i < n; i++){   //방문 초기화 
		for(int j = 0; j < n; j++){
			b_visited[i][j] = 0;  
		}
	}

}

bool finish = false; //dfs함수 끝내기 
void dfs(int itmp , int ct) //조합 장애물 3개자리 찾기 
{
	if(finish){
		return;
	}
	if(ct == 3){
		for(int i = 0; i < v.size(); i++){  //장애물설치 
			if(visited[i] == true){
				cant_escape = false;
				int y = v[i] / n;
				int x = v[i] % n;
				graph[y][x] = 'O';
			}
		}
		bfs();
		if(cant_escape == false){
			finish = true;
		}
        
		for(int i = 0; i < v.size(); i++){ // 장애물 치우기 
			if(visited[i] == true){
				int y = v[i] / n;
				int x = v[i] % n;
				graph[y][x] = 'X';
			}
		}
		return;
	}
	
	
	for(int i = itmp; i < v.size(); i++){
		if(visited[i] == true){
			continue;
		}
		visited[i] = true;
		dfs(i , ct + 1);
		visited[i] = false;
	}
}

int main()
{
	cin >> n;
	for(int i = 0 ;i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> graph[i][j];
			if(graph[i][j] == 'X'){
				v.push_back(i*n+j);
			}
			if(graph[i][j] == 'S'){
				student.push_back(i*n+j);
			} 
		}
	}
	dfs(0, 0);
	if(finish){
		cout << "YES";
	}
	else{
		cout << "NO";
	}
	
}
