#include <iostream>
#include <algorithm> 
using namespace std;

int main()
{
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin >> n;
	
	long long num[100001];
	
	for(int i = 0; i < n; i++){
	   cin >> num[i];
	}
	
	sort(num , num + n);
	
	int ct = 1;
	int ans_ct = 0;
	long long ans = 0;
	
	for(int i = 0 ; i < n; i++){
		if(num[i] == num[i+1]){
			ct++;
		}
		else{
			ct = 1;
		}
		
		if(ans_ct < ct){
			ans_ct = ct;
			ans = num[i];
		}
	}
	cout << ans << endl;
		
}
