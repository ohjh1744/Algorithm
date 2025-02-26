#include <iostream>
#include <queue>
using namespace std;

int ans;
int n, m;
bool isMelt;
int graph[301][301];  
int visited[301][301];
int temp[301][301];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void bfs(int y, int x){
	
	queue < pair < int, int> > q;
	
	q.push({y, x});
	
	visited[y][x] = true;
	
	while(!q.empty()){
		
		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();

		for(int i = 0; i< 4; i++){
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			
			if(ny < 0 || nx < 0 || ny > n || nx > m){
				continue;
			}
			
			//�ٴٶ�� 
			if(graph[ny][nx] == 0){
				if(temp[cy][cx] > 0){
					temp[cy][cx] -= 1;
				}
			}
			
			//���� �湮���� ���� ������ bfs�� �־��ֱ� 
			// �湮üũ�� ���⼭ ����� q�� ���� ���� �ȵ�. 
			if(visited[ny][nx] == false && graph[ny][nx] != 0){
				visited[ny][nx] = true;
				q.push({ny, nx});
			} 
		}
	}
	
}

bool CheckAllMelt(){
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(graph[i][j] != 0){
				return false;
			}
		}
	}
	return true;
}

// visited  graph�� �̵�. 
void Melt(){
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			graph[i][j] = temp[i][j];
		}
	}
}

void Reset(){
	//1�� ���������� �ʱ�ȭ 
	isMelt = false;
	// �湮 �ʱ�ȭ 
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			visited[i][j] = false;
		}
	}
} 


int main(){
	cin >> n >> m;
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cin >> graph[i][j];
			temp[i][j] = graph[i][j];
		}
	}
	
	while(true){
		
		// bfs�� ���� �� �� ��Ҵٸ� �и��Ȱ;��� 0���. 
		if(CheckAllMelt()){
			cout << 0;
			return 0;
		}
				
	    Reset();
		
		// �� ���� Ȯ���Ͽ� bfs. 
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++){
				if(visited[i][j] == false && graph[i][j] != 0){
				   if(isMelt == true){
				   	  	cout << ans;
				   	  	return 0;
					  }
				   	isMelt = true;
					bfs(i, j);
				}
			}
		}
		
		// ���� ����� graph�� ����. 
		Melt();
		
		// 1�� ���������� ���� 
		ans++;		
	}	
}
