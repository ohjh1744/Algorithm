#include <iostream>
using namespace std;

int arr[49];
bool check[49];

void clear()
{
	for(int i = 0; i < 49; i++){
		check[i]  = false;
	}
}

void dfs(int idx, int cnt, int m)
{
	if(cnt == 6){
		for(int i = 0; i < m; i++){
			if(check[i] == true){
				cout << arr[i] << " ";
			}
		}
		cout << endl;
		return;
	}
	
	for(int i = idx; i < m; i++){
		if(check[i] == true){
			continue;
		}
		check[i] = true;
		dfs(i, cnt+1, m);
		check[i] = false;
	}
}

int main()
{
	while(1){
		int num;
		cin >> num;
		if(num == 0){
			break;
		}
		for(int i = 0; i < num; i++){
			int input;
			cin >> input;
			arr[i] = input;
		}
		clear();
		dfs(0, 0, num);
		cout << endl;
	}
}
