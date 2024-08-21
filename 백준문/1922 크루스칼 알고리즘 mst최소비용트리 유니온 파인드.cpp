#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector < pair < int, pair < int , int > > > v;
int parent[1001];
int ans;
//부모찾기 
int find_parent(int x)
{
	if(x == parent[x]){
		return x;
	}
	else{
		return parent[x] = find_parent(parent[x]);
	}
}

// 부모가 같은지 확인 
bool Same_parent(int x, int y)
{
	x = find_parent(x);
	y = find_parent(y);
	if(x == y){
		return true;
	}
	else{
		return false;
	}
}

// 유니온이란 합치라는 뜻 부모가 서로 다르면 연결해줘라 
void merge(int x, int y)
{
	x = find_parent(x);
	y = find_parent(y);
	if(x != y){
		parent[y] = x;
	}
	
}

// 크루스칼 알고리즘 mst 최소비용트리, 유니온 파인드. 
//비용이 적은 순서대로 a, b노드가 서로 연결안되어잇으면(부모가다르면 ) 이음.
//연결돼잇음 거르기. 
int main()
{
	cin >> n ;
	cin >> m;
	for(int i = 1; i <= m; i++){
		int a, b, c;
		cin >> a >> b >> c;
		v.push_back({c, {a , b}});
	}
	
	for(int i = 1; i <= n; i++){
		parent[i] = i;
	}
	
	sort(v.begin(), v.end()); 
		
	for(int i = 0; i < v.size(); i++){
		if(Same_parent(v[i].second.first, v[i].second.second) == false){
			merge(v[i].second.first, v[i].second.second);
			ans = ans + v[i].first;
		}
	}

}
