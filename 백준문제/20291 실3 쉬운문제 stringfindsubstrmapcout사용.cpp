#include <iostream>
#include <string>
#include <map>
using namespace std;

int n;
map < string, int> mp;
int main(){
	
	cin >> n;
	
	for(int i= 0; i < n; i++){
		string s;
		cin >> s;
		int point = s.find('.');
		string sub = s.substr(point+1);
		if(mp.find(sub) != mp.end()){
			mp[sub]++;
		}
		else{
			mp[sub] = 1;
		}
	}
	
	map<string, int> :: iterator it;
	
	for(it = mp.begin(); it != mp.end(); it++){
		cout << it->first << " " << it->second << "\n";
	}

}
