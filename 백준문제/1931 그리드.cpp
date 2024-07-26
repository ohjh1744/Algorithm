#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <pair<int, int> > v;

int main()
{
	int n, st, fi;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> st >> fi;
		v.push_back({fi, st});
	}
	
	sort(v.begin(), v.end());
	
	int ct = 1;
	
	int t_f = v[0].first;
	int t_s = v[0].second;
	
	for(int i = 1; i < v.size(); i++){
		if(v[i].second >= t_f){
			ct++;
			t_f = v[i].first;
		}
	}
	
	cout << ct << endl;
	
}
