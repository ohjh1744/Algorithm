#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int parent[500005];
int c_size[500005];

bool cycle_check = false;
int cc;
int gcc = 1;

int find_set(int u)
{
	if(u == parent[u]){
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
	parent[v] = u;
	c_size[u] = c_size[u] + c_size[v]; 
}


int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	cin >> n >> m;
	
	//make_Set
	for(int i = 1; i <= n; i++){
		parent[i] = i;
		c_size[i] = 1;
	}
	
	for(int i = 1; i <= m; i++){
		int from, to;
		cin >> from >> to;
		if(find_set(from) != find_set(to)){
			merge(from, to);
		}
		else{
			cycle_check = true;
		}
	}
	
	for(int i = 1; i <= n; i++){
		if(parent[i] == i){
			cc++;
			gcc = max(gcc, c_size[i]);
		}
	}
	
	
	if(cycle_check){
		cout << "Found" << "\n";
	}
	else{
		cout << "Not found" << "\n";
	}
	cout << cc << "\n";
	cout << gcc << "\n";
		
}
