#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

bool visited[10000]; 
vector<int> graph[10000];

int ct = 0;


void dfs(int x){
	visited[x] = true;
	ct++;
	for( int i =0; i < graph[x].size(); i++){
		int y = graph[x][i];
		if(!visited[y]){
			dfs(y);
		}
		
	}
}



int main()
{
   int num , pair , pair_1, pair_2;
   cin >> num;
   cin >> pair;
   
   vector<int> v[num+1];
   
   for(int i =0; i< pair; i++){
   	 cin >> pair_1 >> pair_2;
   	 v[pair_1].push_back(pair_2);	
	 v[pair_2].push_back(pair_1);
   }
   
   for(int i = 0; i< num; i++){
	  sort(v[i+1].begin(), v[i+1].end());	
	}
	
	for(int i = 0; i < v[1].size(); i++){
		cout << v[1][i] ;
	}
	
    for(int i=1; i <= num; i++){
		for(int j=0; j<v[i].size(); j++){
			 graph[i].push_back(v[i][j]);
		}
	}
	
	dfs(1); 	
	cout << ct-1;
	
		
   
   
}
