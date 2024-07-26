#include <iostream>
#include <vector>
using namespace std;


vector <int> v[10001];
int visited[10001];
int h_ct = 0;
int maxx = 0;
int n,m;
int temp[10001];

void dfs(int x)
{
	h_ct++;
	visited[x] = 1;
	for(int i =0; i<v[x].size(); i++){
		int y = v[x][i];
		if(!visited[y]){
			dfs(y);
		}
	}
	
}



void reset()
{
	h_ct =0;
	for(int i = 1; i <= n; i++){
		visited[i] = 0;
	}
}



int main()
{
	scanf("%d %d", &n , &m);
	
	
	for(int i=0; i < m; i++){
	  int a, b;
	  scanf("%d %d", &a , &b);
	  v[b].push_back(a);
	}
	
	
	for(int i = 1; i <= n; i++){
		dfs(i);
		if(maxx < h_ct){
			maxx = h_ct;
		}
		temp[i] = h_ct;
		reset();
	}
	
	for(int i = 1; i <= n; i++){
		if(temp[i] == maxx){
			printf("%d ", i);
		}
	}
	
	
	return 0;
	
	
	
	
}
