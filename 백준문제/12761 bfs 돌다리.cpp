#include <iostream>
#include <queue>
using namespace std;

int A, B, n , m;
bool visited[100001];

int bfs(int x)
{
	queue< pair<int, int> >q;
	q.push({x , 0});
	visited[x] = true;
	
	while(!q.empty()){
		int cx = q.front().first;
		int ct = q.front().second;
		q.pop();
		if(cx == m){
			return ct;
		}
		
		if(cx + 1 < 100001 && !visited[cx+1]){
			visited[cx+ 1] = true;
			q.push({cx+1 , ct+1});
		}
		if(cx - 1 >= 0 && !visited[cx-1]){
			visited[cx - 1] = true;
			q.push({cx-1 , ct+1});
		}
		if(cx + A < 100001 && !visited[cx+A]){
			visited[cx + A] = true;
			q.push({cx+ A , ct+1});
		}
		if(cx - A >= 0 && !visited[cx-A]){
			visited[cx - A] = true;
			q.push({cx-A , ct+1});
		}
		if(cx + B < 100001 && !visited[cx+B]){
			visited[cx + B] = true;
			q.push({cx+B , ct+1});
		}
		if(cx - B >= 0 && !visited[cx-B]){
			visited[cx - B] = true;
			q.push({cx-B , ct+1});
		}
		if(cx * A < 100001 && !visited[cx*A]){
			visited[cx*A] = true;
			q.push({cx*A , ct+1});
		}
		if(cx * B < 100001 && !visited[cx*B]){
			visited[cx*B] = true;
			q.push({cx*B , ct+1});
		}
	}
	return -1;
	
}

int main()
{
	cin >> A >> B >> n >> m;
	cout << bfs(n) << endl;
	return 0;
}

