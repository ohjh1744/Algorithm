#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int A, B, C;
vector <int> v;

bool visited[201][201][201];

void bfs()
{
	queue<pair<pair<int, int>, int> > q;
	q.push(make_pair(make_pair(0, 0), C));
	while(!q.empty()){
		int a = q.front().first.first;
		int b = q.front().first.second;
		int c = q.front().second;
		
		q.pop();
		
		if(!visited[a][b][c]){
			visited[a][b][c] = true;
			
			if(a == 0){
				v.push_back(c);
			}
			
			if(a+b > B){
				q.push(make_pair(make_pair(a+b - B, B), c));
			}
			else{
				q.push(make_pair(make_pair(0,a+b), c));
			}
			
			if(a+c > C){
				q.push(make_pair(make_pair(a+c - C, b), C));
			}
			else{
				q.push(make_pair(make_pair(0,b), a+c));
			}
			
			if(b+a > A){
				q.push(make_pair(make_pair(A, b+a-A), c));
			}
			else{
				q.push(make_pair(make_pair(b+a,0), c));
			}
			
			if(b+c > C){
				q.push(make_pair(make_pair(a, b+c-C), C));
			}
			else{
				q.push(make_pair(make_pair(a,0), b+c));
			}
			
			if(c+a > A){
				q.push(make_pair(make_pair(A,b), c+a-A));
			}
			else{
				q.push(make_pair(make_pair(c+a, b), 0));
			}
			
			if(c+b > B){
				q.push(make_pair(make_pair(a,B), c+b-B));
			}
			else{
				q.push(make_pair(make_pair(a, b + c), 0));
			}
						
		}
				
	}
	
	sort(v.begin(), v.end());
	for(int i =0; i<v.size(); i++){
		cout << v[i] << " ";
	}
	
}


int main()
{
	cin.tie(0);
	cout.tie(0); 
	cin.sync_with_stdio(0);
	cin >> A >> B >> C;
	bfs();
	
	return 0;
}
