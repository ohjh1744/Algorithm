#include <iostream>
#include <queue>
using namespace std;

int graph[101][101];
int visited[101][101];
int outair[101][101]; //�ٱ����ⰳ�� ��� ���ϴ��� üũ 
int n, m; // n ==y, m ==x
int dy[4] = {0, 0, -1 ,1};
int dx[4] = {1, -1, 0, 0};
int cheese_ct = 0;
int ans;

void reset()
{
	for(int i = 1; i <= n ; i++){
		for(int j = 1; j <= m; j++){
			visited[i][j] = 0;
			outair[i][j] = 0;
		}
	}
	cheese_ct = 0;
}

void bfs(int y , int x)
{
	queue < pair < int , int > > q;
	q.push({y, x});
	while(!q.empty()){
		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();
		for(int i = 0; i < 4; i++){
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			if(ny <= 0 || nx <= 0 || ny > n || nx > m){
				continue;
			}
			
			if(visited[ny][nx] == false && graph[ny][nx] == 0){
				q.push({ny, nx});
				visited[ny][nx] = true; //q�� �����鼭 ���ִ� ������ ���ʿ��� ���԰���������  
			}
			else if(visited[ny][nx] == false && graph[ny][nx] == 1){
				outair[ny][nx]++; //�þ���� ny nx�� ������ ���ⰳ�� ����. 
			}
		}
	}
	
	// ����ġ��� �ٱ����� 0���� ��ȯ
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(outair[i][j] >= 2){
				graph[i][j] = 0;
			}
		}
	} 
	
}


int main()
{
	cin >> n >> m;
	for(int i = 1; i <= n ; i++){
		for(int j = 1; j <= m; j++){
			int num;
			cin >> num;
			graph[i][j] = num;
			if(num == 1){
				cheese_ct++;
			}
		}
	}
	
    while(cheese_ct > 0){
    	reset(); //, �湮�ʱ�ȭ
		bfs(1, 1);		
		ans++; 
    	for(int i = 1; i <= n; i++){
    		for(int j = 1; j <= m; j++){
    			if(graph[i][j] == 1){
    				cheese_ct++;
				}
			}
		}			
	}
	
	cout << ans << "\n";	
	
}
