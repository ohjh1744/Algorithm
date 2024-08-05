#include <string>
#include <vector>
#include <iostream>

using namespace std;

int parent[201];
int r[201];

void make_set(int n){
	for(int i = 0; i < n; i++){
		parent[i] = i;
	}
}

int find_set(int u){
	if(u == parent[u]){
		return u;
	}
	else{
		return parent[u] = find_set(parent[u]);
	}
}

void merge(int u, int v){
	u = find_set(u);
	v = find_set(v);
	
	if( u > v){
		parent[v] = u;
	}
	else{
		parent[u] = v;
		if(r[u] == r[v]){
			r[v] = r[v] + 1;
		}
	}
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    make_set(n);
    for(int i = 0; i < computers.size(); i++){
        for(int j = 0; j < computers[i].size(); j++){
            if(i == j){
                continue;
            }
            if(computers[i][j] == 1){
                if(find_set(i) != find_set(j)){
                    merge(i, j);
                }
            }
        }
    }
    
    int v[n+1][1];
    
    for(int i = 0; i < n; i++){
        v[i][0] = 0;
    }
    for(int i = 0; i < n; i++){
        int root = find_set(i);
        v[root][0] += 1;
    }
    
    for(int i = 0; i < n; i++){
        if(v[i][0] > 0){
            answer += 1;
        }
    }
    
    return answer;
}
