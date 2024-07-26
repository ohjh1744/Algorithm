#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n;
char graph[6][6];
vector <int> v; // X���� ���� 0 2 3 6 ~
vector <int> student; // �л� ��ġ ���� 
bool visited[36]; //dfs���� ����ϴ� �湮ó�� 

int b_visited[6][6];
int dx[4] = {0, 0 , -1, 1};
int dy[4] = {-1, 1, 0, 0};  //�� �� �� �� 
bool cant_escape; 


void bfs() // ������ ���� ���Ҽ��ִ��� ������ 
{
    queue < pair < int, int > >	q;
    for(int i = 0; i < student.size(); i++){
    	int y = student[i] / n;
    	int x = student[i] % n;
    	q.push({y, x});
	}
	while(!q.empty()){       // ��, �� ���� 
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
	for(int i = 0; i < n; i++){   //�湮 �ʱ�ȭ 
		for(int j = 0; j < n; j++){
			b_visited[i][j] = 0;
		}
	}
	for(int i = 0; i < student.size(); i++){
    	int y = student[i] / n;
    	int x = student[i] % n;
    	q.push({y, x});
	}
	while(!q.empty()){       // ��, �� ���� 
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
	for(int i = 0; i < n; i++){   //�湮 �ʱ�ȭ 
		for(int j = 0; j < n; j++){
			b_visited[i][j] = 0;  
		}
	}

}

bool finish = false; //dfs�Լ� ������ 
void dfs(int itmp , int ct) //���� ��ֹ� 3���ڸ� ã�� 
{
	if(finish){
		return;
	}
	if(ct == 3){
		for(int i = 0; i < v.size(); i++){  //��ֹ���ġ 
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
        
		for(int i = 0; i < v.size(); i++){ // ��ֹ� ġ��� 
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
