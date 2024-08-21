#include <iostream>
using namespace std;

int temp[15001];
int n, m;
int ans;
int main()
{
	cin >> n;
	cin >> m;
	for(int i = 1; i <= n; i++){
		int num;
		cin >> num;
		temp[i] = num;
	}
	
	int start = 1;
	int end = 2;
	int total = temp[start] + temp[end];
	
	while(start < n){
		if(total == m){
			ans++;
		}
		if(end == n){
			total -= temp[start];
			start++;
			total += temp[start];
			total -= temp[end];
			end = start + 1;
			total += temp[end];
		}
		else{
			total -= temp[end];
			end++;
			total += temp[end];
		}
	
	}
	
	cout << ans << endl;
	

}
