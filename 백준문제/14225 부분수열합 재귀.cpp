#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;

int temp[21];
bool b[2000001]; //만들수있는 수인지 없는지 체크 
void dfs(int num, int ct)
{
	if(ct == n + 1){
		b[num] = true;
		return;
	}
	dfs(num + temp[ct], ct+1);
	dfs(num , ct+1);
}


int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> temp[i];
	}
	dfs(temp[0] , 0);

	for(int i = 1; i <= 2000000; i++){
		if(b[i] == false){
			cout << i << "\n";
			break;
		}
		
	}
	
	return 0;
}
