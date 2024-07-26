#include <iostream>
#include <vector>

using namespace std;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1 , -1};

char graph[250][250];
int visited[250][250];

int r, c;  // r 은 x, c는 y
int wolf, shif;  

int ans_w, ans_s;

int space;

void dfs(int y, int x)
{
	space ++;

	if(graph[y][x] == 'v'){
		wolf++;
	}
	else if(graph[y][x] == 'k'){
		shif++;
	}
	
	visited[y][x] = 1;
		
	for(int i = 0; i< 4 ; i++){
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(nx < 0 || ny < 0 || nx >= r || ny >= c){
			continue;
		}
		if(graph[ny][nx] != '#' && visited[ny][nx] == 0){
			visited[ny][nx] = 1;
			dfs(ny, nx);
		}
		
	}
}

void reset()
{
	wolf = 0;
	shif = 0;
	space = 0;
}


int main()
{
	cin >> r >> c;
	
	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
			cin >> graph[j][i] ;
		}
	}
	
	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
			if(graph[j][i] != '#' && visited[j][i] == 0){
				dfs(j, i);
				cout << "양과 늑대의 수, space: " << shif << " " << wolf << " " << space << endl;
				if(wolf >= shif){
					ans_w = ans_w + wolf;
				}
				else{
					ans_s = ans_s + shif;
				}
				reset();
			}
			
		}
	}
	
	cout << ans_s << " " << ans_w;
	
	
}
