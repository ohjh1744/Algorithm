#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
int parent[300001];
int r[300001];

vector<pair < int, int > > v;

int find_set(int u){
	if(parent[u] == u){
		return u;
	}
	else{
		return parent[u] = find_set(parent[u]);
	}
}

void make_set(int u){
	parent[u] = u;
}

void DoUnion(int u, int v){
	u = find_set(u);
	v = find_set(v);
	if(r[u] > r[v]){
		parent[v] = u;
	}
	else{
		parent[u] = v;
		if(r[u] == r[v]){
			r[v] = r[v] + 1;
		}
	}
}

int main(){
	cin >> n;
	
	for(int i = 0; i < n-2; i++){
		int from, end;
		cin >> from >> end;
		v.push_back({from, end});
	}
	
	// 초기화 
	for(int i = 1; i <= n; i++){
		make_set(i);
	}
	
	// 간선 정보에 따라 그래프 만들기 
	for(int i = 0; i < v.size(); i++){
		int fn = find_set(v[i].first);
		int en = find_set(v[i].second);
		if(fn != en){
			DoUnion(fn , en);
		}
	}
	
	// 무너진 다리 확인하기 
	int from =  find_set(1);  
	for(int i = 2; i <= n; i++){
		int end = find_set(i);
		if(from != end){
			cout << from << " " << end;
			break; 
		}
	}
	
}
