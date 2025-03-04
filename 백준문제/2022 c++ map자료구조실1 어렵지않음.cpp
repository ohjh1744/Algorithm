#include <iostream>
#include <string>
#include <map>
using namespace std;

int n;
map< string, int> mp;
int ans;
int temp[1001];

int main(){
	
	cin >> n;
	
	for(int i = 1; i <= n; i++){
		string s;
		cin >> s; 
		mp[s] = i;
	}
	
	for(int i = 1; i <= n; i++){
		string s;
		cin >> s;
		temp[i] = mp[s];
	}
	
	for(int i = 1; i <= n-1; i++){
		for(int j = i+1; j <= n; j++){
			if(temp[i] > temp[j]){
				ans++;
				break;
			}
		}
	}
	
	
	cout << ans << "\n";
}
