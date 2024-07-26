#include <iostream>
#include <algorithm>
using namespace std;

int dir[3] = {0 , 1 , 2};
int n;
int temp[1001];
int ans;

int main()
{
	cin >> n ;
	for(int i = 1; i <= n; i++){
		cin >> temp[i];
	}
	
	int ct = 0; //먹을수 있는 우유개수 
	int milk = 0; // 최근에 먹은 우유 
	
	for(int i = 1; i < n; i++){
		if(temp[i] != 0){
			continue;
		}
		ct = 1;
		milk = temp[i];
		for(int j = i+1; j <= n; j++){
			if(milk == 2 && temp[j] == 0){
				ct++;
				milk = temp[j];
			}
			else if(temp[j] == milk + 1){
				ct++;
				milk = temp[j];
			}
		}
		ans = max(ans, ct);
	}
	
	cout << ans << "\n"; 
	
}
