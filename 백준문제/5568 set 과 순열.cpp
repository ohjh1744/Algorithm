#include <iostream>
#include <set>
#include <vector>
using namespace std;

int n, k;
string temp[10];
set<string> st;


vector<string> v;
bool check[10];

void dfs(int ct) //증복없는순열 
{
	if(ct == k){
		string s = "";
		for(int i = 0; i < v.size(); i++){
			s = s + v[i];
		}
		st.insert(s);
		return;
	}
	for(int i = 0; i < n; i++){
		if(check[i] == true){
			continue;
		}
		check[i] = true;
		v.push_back(temp[i]);
		dfs(ct+1);
		v.pop_back();
		check[i] = false;
	}
}

int main()
{
	cin >> n;
	cin >> k;
	for(int i = 0; i < n; i++){
		cin >> temp[i];
	}
	dfs(0);
	
	set <string> :: iterator it;
	cout << st.size() << endl; 
	
}
