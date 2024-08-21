#include <iostream>
#include <algorithm>
using namespace std;

int n, k;
int temp[200001];
int check[100001]; // n수가 몇개 들어있는지 수열에 
int ans;

int main()
{
	cin >> n >> k;
	for(int i = 0; i < n; i++){
		cin >> temp[i];
	}
	
	int st = 0;
	int end = 1;
	check[temp[0]] = 1;
	int l = 1;
	
	while(end <= n){
		ans = max(ans, l);
		if(check[temp[end]] >= k){
			check[temp[st]]--;
			l--;
			st++;
		}
		
		else if(check[temp[end]] < k){
			check[temp[end]]++;
			l++;
			end++;
		}
	}
	
	cout <<ans << "\n";
}
