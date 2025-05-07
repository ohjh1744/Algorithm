#include <iostream>
#include <map>
using namespace std;

map<string, int> mp;
int n;
int ans;
int main(){
	cin >> n;
	
	for(int i = 0; i < n; i++){
		string s;
		cin >> s;
		if(s == "ENTER"){
			mp.clear();
		}
		else{
			if(mp.find(s) == mp.end()){
				mp[s]++;
				ans++;
			}
		}
	}
	
	cout << ans;
}
