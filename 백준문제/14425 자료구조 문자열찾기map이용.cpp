#include <iostream>
#include <map>
using namespace std;

map <string , bool > mp;

int main()
{
	int n , m;
	cin >> n >> m;
	string s;
	for(int i = 0; i < n; i++){
		cin >> s;
		mp.insert({s, true});
	}
	
	int ct = 0;
	string s2;
	for(int i = 0; i < m; i++){
		cin >> s2;
		if(mp[s2] == true){
			ct++;
		}
	}
	cout << ct << endl;
}
