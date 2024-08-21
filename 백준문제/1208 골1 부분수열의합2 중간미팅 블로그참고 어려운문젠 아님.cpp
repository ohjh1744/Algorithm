#include <iostream>
#include <map>
using namespace std;

int n, s;
map <int, int > mp;
int temp[41];
long long ans;

void l_dfs(int sum, int ct)
{
	if(ct == n/2){
		mp[sum]++;
		return; 
	}
	l_dfs(sum + temp[ct], ct+1);
	l_dfs(sum, ct+1);
}

void r_dfs(int sum, int ct)
{
	if(ct == n){
		ans = ans + mp[s-sum];
		return;
	}
	r_dfs(sum + temp[ct], ct+1);
	r_dfs(sum, ct+1);
}

int main()
{
	cin >> n >> s;
	for(int i = 0; i < n; i++){
		cin >> temp[i];
	}
	
	l_dfs(0 , 0);
	r_dfs(0  , n/2); 
	if(s == 0){
		cout << ans-1 << "\n";
	}
	else{
		cout << ans << "\n";
	}
}
