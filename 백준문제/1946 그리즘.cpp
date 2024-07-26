#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	cout.tie(0);
	cin.tie(0);
	int t;
	int n, a, b;
	cin >> t;
	
	for(int i = 0; i < t; i++){
		cin >> n;
		
		vector < pair< int, int> > v;
		
		for(int j = 0; j < n; j++){
			cin >> a >> b;
		    v.push_back({a, b});
		}
		
		sort(v.begin(), v.end());
		int ans = 1;
		int max = v[0].second;
		
		
		for(int z = 1 ; z < v.size(); z++){
			if(v[z].second < max){
				ans++;
				max = v[z].second; 
			}
		}
		cout << ans << "\n";	
		
	}
}
