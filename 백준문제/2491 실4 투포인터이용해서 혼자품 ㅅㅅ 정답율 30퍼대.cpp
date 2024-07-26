#include <iostream>
#include <algorithm>
using namespace std;

int n;
int temp[100001];

int ct = 1;
int ans = 0;

int main()
{
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> temp[i];
	}
	
	int start = 0;
	int cp = start;
	int end = 1;
	//커지는 수열확인
	while(end < n){
		if(temp[cp] <= temp[end]){
			cp = end;
			end++;
			ct++;
		}
		else{
			ans = max(ans , ct);
			ct = 1;
			start = end;
			cp = start;
			end++;
		}
	}
	ans = max(ans , ct); 
	
    start = 0;
	cp = start;
	end = 1;
	ct = 1;
	//작아지는 수열확인
	while(end < n){
		if(temp[cp] >= temp[end]){
			cp = end;
			end++;
			ct++;
		}
		else{
			ans = max(ans , ct);
			ct = 1;
			start = end;
			cp = start;
			end++;
		}
	}
	ans = max(ans , ct);
	cout << ans << "\n"; 
	
	
}
