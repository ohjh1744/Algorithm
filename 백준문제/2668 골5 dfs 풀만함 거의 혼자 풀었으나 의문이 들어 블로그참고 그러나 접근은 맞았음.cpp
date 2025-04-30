#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int n;
vector<int> v[101];
int visited[101];
int ans;
vector<int>tempV; 
set<int>st;

void dfs(int x, int fx){
	
	visited[x] = true;
	tempV.push_back(x);
	
	int nx = v[x][0];
	
	//첫 시작점 만나는 경우 
	if(nx == fx){
	
		for(int i = 0; i < tempV.size(); i++){
			int num = tempV[i];
			if(st.find(num) == st.end()){
				st.insert(num);
				ans++;
			}
		}		
		return;
	}

	else if(visited[nx] == false){
		dfs(nx, fx);
	}
		
	
}

void clear(){
	tempV.clear();
	for(int i = 1; i <= n; i++){
		visited[i] = false;
	}
}

int main(){
	cin >> n;
	
	for(int i = 1; i <= n; i++){
		int num;
		cin >> num;
		v[i].push_back(num);
	}
	
	for(int i = 1; i <= n; i++){
		clear();
		dfs(i, i);
	}
	
	cout << ans << "\n";
	
	set<int> :: iterator it;
	
	for(it = st.begin(); it != st.end(); it++){
		cout << *it << "\n";
	}
}
