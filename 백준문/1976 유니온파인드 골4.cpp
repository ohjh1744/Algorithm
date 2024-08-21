#include <iostream>
using namespace std;

int n , m;
int parent[201];
int travel[1001];
bool b = true;

int find_parent(int x)
{
	if(x == parent[x]){
		return x;
	}
	else{
		return parent[x] = find_parent(parent[x]);
	}
}

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

void merge(int x, int y)
{
	x = find_parent(x);
	y = find_parent(y);
	if(x != y){
		parent[y] = x;
	}
	
}

int main()
{
	cin >> n;
	cin >> m;
	
	//make-set 
	for(int i = 1; i <= n; i++){
		parent[i] = i;
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			int num;
			cin >> num;
			if(num == 1){
				if(Same_parent(i , j) == false){
					merge(i, j);
				}
			}
		}
	}
	
	for(int i = 1; i <= m; i++){
		cin >> travel[i];
	}
	
	int start = parent[travel[1]];
	
	for(int i = 2; i <= m; i++){
		if(start != find_parent(travel[i])){
			b = false;
			break;
		}
	}
	
	if(b){
		cout << "YES" << "\n";
	}
	else{
		cout << "NO" << "\n";
	}
		
}
