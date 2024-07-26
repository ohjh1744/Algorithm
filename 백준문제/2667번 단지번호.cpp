#include <bits/stdc++.h>
using namespace std;


int in[25][25];
int visited[25][25];

int dx[4] = {1, -1, 0 , 0};
int dy[4] = {0, 0, 1, -1};
int ct = 0;
  

void dfs(int y, int x)   
{
	ct++;
	visited[y][x] = true;
	for(int i = 0; i < 4 ; i++){
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(nx < 0 || nx >= 25 || ny < 0 || ny >= 25){
			continue;
		}
		if(in[ny][nx] == 1 && visited[ny][nx] == false){
			dfs(ny, nx);
		}
	}	
	
}

int main(){
   
   int n;
   cin >> n ;
   
   vector<int> v;
   
   for(int i = 0; i < n ; i++){
   	for(int j= 0; j < n; j++){
   		scanf("%1d" , &in[i][j]);
	   }
   }
   
   for(int i = 0; i < n; i++){
   	for(int j = 0; j < n; j++){
   		if(in[i][j] == 1 && visited[i][j] == false){
   			dfs(i,j);
   			v.push_back(ct);
   			ct = 0;
		   }
	   }
   }
   
   sort(v.begin(),v.end());
   cout << v.size() << endl;
   
   for(int i =0 ; i< v.size() ; i++){
   	cout << v[i] << endl;
   }
   
   
   
   

      
   
   
}
