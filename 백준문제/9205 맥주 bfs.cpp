#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n;
int visited[104];
int arr[104][2];
queue< pair< int, int> > q; // if문조건에 맞다면, q에 push  

void bfs()
{
	q.push({arr[0][0], arr[0][1]});
    visited[0] = true;
    
	while(!q.empty()){
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();
		
		if(cx == arr[n+1][0] && cy == arr[n+1][1]){
			cout << "happy" << endl;
			return;
		}
		
		for(int i = 1; i < n+2; i++){
			int nx = abs(cx - arr[i][0]);
			int ny = abs(cy - arr[i][1]);
			if(visited[i] == 0 && nx + ny <= 1000){
				visited[i] = true;
				q.push({arr[i][0] , arr[i][1]});
			}
		}
	}
    cout << "sad" << endl;
}

void reset()
{
	for(int i = 0; i < n + 2; i++){
		arr[i][0] = 0;
		arr[i][1] = 0;
		visited[i] = 0;
	}
}


int main()
{
	int t;
	cin >> t;
	for(int i = 0; i < t; i++){
		reset();
		cin >> n;
		
		for(int j = 0; j < n + 2; j++){
			cin >> arr[j][0] >> arr[j][1] ; //집부터 편의점~도찰 
		}
		
		bfs();
		
			
	}
	
}

