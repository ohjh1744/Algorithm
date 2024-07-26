#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector < pair < int, int > > v;

int main()
{
	int n, m;
	cin >> n >> m;
	
	int pack, other = 0;
	
	for(int i = 0; i < m; i++){
		cin >> pack >> other;
        v.push_back({pack, other});
	}
	
	int ans_1 = 9999999; // 패키지로살때  
	int ans_2 = 9999999; // 단일로 살때 
	int ans_3 = 9999999; // 패키지+ 단일 

	for(int i = 0; i < v.size(); i++){
		ans_1 = min(ans_1, v[i].first);
		ans_2 = min(ans_2, v[i].second);		
	}
	
	int pk_ct = n/6;
	int ot_ct = n%6;
	int s_pk = 9999999;
	int s_ot = 9999999;
	
	for(int i = 0; i < v.size(); i++){
		s_pk = min(s_pk, v[i].first);
		s_ot = min(s_ot, v[i].second);		
	}
	ans_3 = 9999999;
	if(n > 6){
		ans_1 = ans_1 * (pk_ct+1);
		ans_3 = s_pk * pk_ct + s_ot * ot_ct; 
	}
	ans_2 = ans_2 * n;	
	
	
    int ans = min(min(ans_1, ans_2) , ans_3);
    cout << ans << endl;
    
    
	
}
