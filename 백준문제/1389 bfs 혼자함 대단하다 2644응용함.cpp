#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m , f_1 , f_2;
vector<int> v[101];
queue<int> q;
int visited[101];
int arr[101];

void bfs(int x)
{
	int ct = 0;
	q.push(x);
	visited[x] = 0;
	
	while(!q.empty()){
		int cx = q.front();
		q.pop();
		for(int i =0; i<v[cx].size(); i++){
			int y = v[cx][i];
			if(!visited[y]){
				q.push(y);
				visited[y] = visited[cx] + 1;
				ct = ct + visited[y];
			}
		}
	}
	arr[x] = ct - visited[x];
		
}

void reset()
{
	for(int i = 1; i<= n; i++){
		visited[i] = 0;
	}
}

int main()
{
	cin >> n >> m;
	
	for(int i=0; i< m; i++){
	   cin >> f_1 >> f_2;
	   v[f_1].push_back(f_2);
	   v[f_2].push_back(f_1);	
	}
	
	for(int i=1; i<=n; i++){
		bfs(i);
		reset();
	}
	
	int result = arr[1];
	int num = 1;
	
	for(int i = 2; i<=n; i++){
		if(result > arr[i]){
			result = arr[i];
			num = i;
		}
	}
	
	cout << num << endl;
	
	
}


