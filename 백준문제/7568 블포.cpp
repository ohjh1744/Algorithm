#include <iostream>
#include <vector> 
using namespace std;

int main()
{
	int n;
	vector<pair< int, int > > v;
	
	cin >> n;
	
	for(int i = 0; i < n; i++){
		int w, h;
		cin >> w >> h;
		v.push_back({w, h});
	}
	
	for(int i = 0; i < n; i++){
		int cw = v[i].first;
		int ch = v[i].second;
		int ct = 0;
		for(int j = 0; j < n; j++){
			if(cw == v[j].first && ch == v[j].second){
				continue;
			}
			if(cw < v[j].first && ch < v[j].second){
				ct++;
			}
		}
		cout << ct+1 << " ";
		
	}
	
}
