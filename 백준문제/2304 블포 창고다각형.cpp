#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	
	vector< pair< int, int> > v;
	
	for(int i = 0; i < n ; i++){
	   int l , h ;
	   cin >> l >> h ;
	   v.push_back({l, h});
	}
	
	sort(v.begin(), v.end());
	int h_max = 0;
	int highest = v[0].second;
	
	for(int i = 0; i < v.size(); i++ ){
	   if(v[i].second >= highest){
	   	    highest = v[i].second;
			h_max = i;
	   } 
	}
	
	int ans = 0;
	
	int st_ll = v[0].first;
	int st_lh = v[0].second;
	
	for(int i = 1; i <= h_max; i++){ //h_max 3 
		if(v[i].second >= st_lh){
			ans = ans + ((v[i].first - st_ll) * st_lh);
			st_ll = v[i].first;
			st_lh = v[i].second;
		}
	}
	
	int st_rl = v.back().first;
	int st_rh = v.back().second;
	
	for(int i = v.size()-1; i >= h_max; i--){ //h_max 3 
		if(v[i].second >= st_rh){
			ans = ans + ((st_rl - v[i].first) * st_rh);
			st_rl = v[i].first;
			st_rh = v[i].second;
		}
	}
	ans = ans + v[h_max].second;
	
	cout << ans << endl;	
	
}
