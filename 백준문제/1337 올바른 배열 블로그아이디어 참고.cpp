#include <iostream>
#include <algorithm>
using namespace std;


int n;
int temp[55];
int ct;
int ans = 1;
int main()
{
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> temp[i];
	}
	
	sort(temp, temp+n);
	
	for(int i = 0; i < n; i++){
		ct = 1;
		for(int j = i+1; j < i+5; j++){
			if(temp[j] - temp[i] < 5 && temp[j] - temp[i] > 0){
				ct++;
			}
		}
		ans = max(ct, ans);
	}
	
	cout << 5 - ans << "\n";
}
