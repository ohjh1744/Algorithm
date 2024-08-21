#include <iostream>
#include <algorithm>
using namespace std;

int temp[5];
int visited[5];
int n;
int result;
int ans;

void dfs(int itmp, int ct)
{
	if(ct == 3){
		int big = 0;
		int num = 0;
		for(int i = 0; i < 5; i++){
			if(visited[i] == true){
				big = big + temp[i];
			}
		}
		num = big % 10; 
		result = max(result, num);
		return;
	}
	
	for(int i = itmp; i < 5; i++){
		if(visited[i] == true){
			continue;
		}
		visited[i] = true;
		dfs(i, ct+1);
		visited[i] = false;
	}
}

int main()
{
	cin >> n;
	
	int f_num;
	for(int i = 0; i < n; i++){
		
		for(int j = 0; j < 5; j++){
			cin >> temp[j];
		}
		
		dfs(0, 0);
		
		if(i == 0){
			f_num = result;
			ans = 1;
		}
		else{
			if(f_num <= result){
				f_num = result;
				ans = i+1;
			}
		}
		
		result = 0;
	}
	
	cout << ans << "\n";
	
}
