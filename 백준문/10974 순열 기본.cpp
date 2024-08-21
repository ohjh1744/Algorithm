#include <iostream>
#include <vector>
using namespace std;

int n;

int arr[8];
bool sel[8];
vector <int> v;

void dfs(int cnt)
{
	if(cnt == n){
		for(int i = 0;i< v.size(); i++){
			printf("%d ", v[i]);
		}
		printf("\n");
		return;
	}
	
	
	for(int i = 0; i < n; i++){
		if(sel[i] == true){
			continue;
		}
		sel[i] = true;
		v.push_back(arr[i]);
		dfs(cnt + 1);
		v.pop_back();
		sel[i] = false;
	}
}


int main()
{
	scanf("%d", &n);
	
	for(int i = 0; i < n; i++){
		arr[i] = i+1;
	}
	
	dfs(0);
    return 0;
}
