#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> v;
int dp[100000];

int main()
{
	int n , num , big;
	cin >> n;
	
	for(int i = 0 ; i < n; i++){
		cin >> num;
		v.push_back(num);
	}
	
	dp[0] = v.front();
	for(int i = 1; i < v.size(); i++){
		dp[i] = max(v[i], dp[i-1] + v[i]);
	}
	
	sort(dp, dp+n);
	
	cout << dp[n-1] << endl;
	
	
	
	
}
