#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int h, w; // 세로 , 가로 
int graph[502][502];

int count; // 빗물이 고일수도있는 공간 
int ans;  //빗물이 확실히 고이는 공간 

void bfs(int y, int x)
{
	queue< pair < int , int > > q;
	q.push({y, x+1});
	while(!q.empty()){
		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();

		if(graph[cy][cx] == 1 || cx >= w){  //결국 양옆에 벽이있으면 그안의 count들은 빗물이 고일수있다. 
			if(graph[cy][cx] == 1){
				ans = ans + count;
				count = 0;
				break;
			}
			else if(cx >= w){         // 오른쪽끝까지 갔는데 벽이 없을경우, count는 고인 빗물이 될수없다. 
				count = 0;
				break;
			}
		}
		
		count++;
		int ny = cy;
		int nx = cx + 1;
		q.push({ny, nx});
	}
}

int main()
{
	cin >> h >> w;
	for(int i = 1; i <= w; i++){
		int r;
		cin >> r;
		int n = 0;
		while(n< r){
			graph[h-n][i] = 1;
			n++;
		}
	}
	
	for(int i = 1; i <= h; i++){
		for(int j = 1; j <= w; j++){
			if(graph[i][j] == 1){
				bfs(i, j);
			}
		}
	}
	cout << ans << "\n";
	
}
