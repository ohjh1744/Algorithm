#include <iostream>
using namespace std;

int n , s;
int arr[20];

int ans = 0;

void dfs(int sum, int count)
{
	cout << sum << " " << count << endl;
	if(count >= n){
		if(sum == s){
		  ans++;
	    }
	    return;
	}
	
	dfs(sum + arr[count] , count+1);
	dfs(sum , count + 1);
	
}


int main()
{
	cin.tie(0);
	cout.tie(0);
	cin >> n >> s;
	
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	
	dfs(0, 0);
	if(s == 0){
		ans = ans-1;
	}
	cout << ans << endl;
	
	
}



