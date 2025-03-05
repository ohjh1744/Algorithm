#include <iostream>
#include <vector>
#include <queue>
using namespace std;


int n;
int graph[101][101];
int visited[101][101];
int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};
int ans = 1e9;

void reset()
{
   for(int i = 1; i <= n; i++ ){
      for(int j= 1; j<=n; j++){
         visited[i][j] = 0;
      }
   }
}

void bfs(int y, int x, int k){
   visited[y][x] = 1;
   queue < pair < int, int > > q;
   q.push({y, x});
   
   while(!q.empty()){
      int cy = q.front().first;
      int cx = q.front().second;   
       q.pop();
      //다른 대륙이라면 
      // 2를 빼주는 이유는 시작지점과 도착지점이 대륙이기에 바다동선만 구하기위해서 
      if(graph[cy][cx] != 0 && graph[cy][cx] != k){
         int len = visited[cy][cx] -2;
         if(ans > len){
            ans = len;
         }
      }
            
      for(int i = 0; i< 4; i++){
         int ny = cy + dy[i];
         int nx = cx + dx[i];
         if(ny < 1 || nx < 1 || ny > n || nx > n){
             continue;
          }
          //바다나 다른 대지라면 큐에 추가 
          if(visited[ny][nx] == 0 && graph[ny][nx] != k){
             visited[ny][nx] = visited[cy][cx] + 1;
             q.push({ny, nx});
         }
      }
   }
}

// 육지 수 다르게  
void dfs(int y, int x, int k){
   
   visited[y][x] = true;   
   graph[y][x] = k;
   
   for(int i = 0; i< 4; i++){
      int ny = y + dy[i];
      int nx = x + dx[i];
      if(ny < 1 || nx < 1 || ny > n || nx > n){
         continue;
      }
      if(visited[ny][nx] == false && graph[ny][nx] == 1){
         dfs(ny, nx, k);
      }
   }
}

int main(){
   cin >> n;
   
   for(int i = 1; i <= n; i++ ){
      for(int j= 1; j<=n; j++){
         cin >> graph[i][j];
      }
   }
   
   int k = 2;
   
   // 대륙별 지정 숫자 다르게 바꿔주기 
   for(int i = 1; i <= n; i++ ){
      for(int j= 1; j<=n; j++){
         if(visited[i][j] == false && graph[i][j] == 1){
            dfs(i, j, k);
            k++;
         }
      }
   }

   // 방문 초기화 
   reset();
   
   
   while(k > 1){
   	    // 대륙 마지막 index부터 시작하기위함. 
   	    k--;
   	    for(int i = 1; i <=n; i++){
   		    for(int j = 1; j <= n; j++){
   			    if(k == graph[i][j]){
   			       bfs(i, j, k);
			       reset();	
		        }	   
		    }
	    }
    }
   
   
   cout << ans;

}
