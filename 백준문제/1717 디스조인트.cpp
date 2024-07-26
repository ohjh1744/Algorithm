#include<iostream>
using namespace std;


int parent[1000001];
int r[1000001];
int n, m;
int num, a, b;

int find_set(int u)
{
	if(parent[u] == u){
		return u;
	}
	else{
		return parent[u] = find_set(parent[u]);
	}
}

void merge(int u, int v)
{
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

void make_set(int u)
{
	parent[u] = u;
	r[u] = 0;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	
	for(int i = 0; i <= n; i++){
		make_set(i);
	}
	
	for(int i = 0; i < m; i++){
		cin >> num >> a >> b;
		if(num == 0){
			merge(a, b);
		}
		else{
			if(find_set(a) == find_set(b)){
				cout << "YES" << "\n";
			}
			else{
				cout << "NO" << "\n";
			}
	    }
	}
	
}
