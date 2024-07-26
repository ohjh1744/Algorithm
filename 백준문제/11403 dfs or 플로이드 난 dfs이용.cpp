#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;

int visited[100];
vector<int> g[100];

void dfs(int x)
{

  for(int i =0; i< g[x].size(); i++){
  	int nx = g[x][i];
  	if(!visited[nx]){
  		visited[nx] = 1;
		dfs(nx);
	  }
  }
}

void reset(){
	for(int i =0; i<n; i++){
		visited[i] = 0; 
	}
}


int main()
{
   int t;
   cin >> n;
   for(int i=0; i<n; i++){
   	for(int j=0; j<n; j++){
   		cin >> t;
   		if(t){
   			g[i].push_back(j);   			
		}
	   }
   }
   
   for(int i=0; i <n; i++){
   	reset();
   	dfs(i);
   	for(int j=0 ;j <n ; j++){
   		cout << visited[j] << " ";
	}	
	cout << endl;   
   }
   
   
   
   
   
}
