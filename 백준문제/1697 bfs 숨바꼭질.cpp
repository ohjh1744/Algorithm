#include <iostream>
#include <queue>
#include<algorithm>

using namespace std;

queue<pair<int,int > > q;
int visit[100001];
int result = 0;
int n, k;

bool check(int n){
	if(n < 0 || n > 100000 || visit[n]){
		return false;
	}
	else
	   return true;
}

void bfs(int n)
{
	while(!q.empty()){
		int cn = q.front().first;
		int time = q.front().second;
		q.pop();
		
		if(cn == k){
			result = time;
			break;
		}
		
		if(check(cn-1)){
			q.push({cn-1, time+1});
			visit[cn-1] = true;
		}
		
		if(check(cn+1)){
			q.push({cn+1, time+1});
			visit[cn+1] = true;
		}
		
		if(check(cn*2)){
			q.push({cn*2, time+1});
			visit[cn*2] = true;
		}		
		
	}
}

int main()
{
	cin >> n >> k;
	q.push({n,0});
	visit[n] = true;
	bfs(n);
	
	cout << result;
}


