#include <iostream>
#include <map>
using namespace std;

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	
	int n , m;
    cin >> n >> m;
    map<string , string> mp;
    
    for(int i = 0; i < n; i++){
    	string address, password;
    	cin >> address >> password;
    	mp[address] = password;
	}
	
	for(int i = 0; i < m; i++){
		string f_add;
		cin >> f_add;
		if(mp.find(f_add) != mp.end()){
			cout << mp[f_add] << "\n";
		}
	}
    
}
