#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <string> nlist;
vector <string> ans;

int ct = 0;


int main()
{
	cin.tie(0);
	cout.tie(0);
	int n, m;
	string name;
	
	cin >> n >> m;
	
	for(int i = 0; i < n+m ; i++){
		cin >> name;
		nlist.push_back(name);
	}
		
	sort(nlist.begin(), nlist.end());
	
	for(int i = 0; i < n+m-1; i++){
		if(nlist[i] == nlist[i+1]){
			ct++;
			ans.push_back(nlist[i]);
		}
	}	
	
	cout << ct << endl;
	
	for(int i = 0 ; i < ans.size(); i++){
		cout << ans[i] << endl;
	}
	
	
}
