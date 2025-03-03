#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm> 
using namespace std;

unordered_map <string, int> mp;
vector <string> v;
int n, m;


bool compare(string a, string b){
	//1. 자주 나오는 단어  
	if(mp[a] != mp[b]){
		return mp[a] > mp[b]; 
	}
	
	//2.  길이가 긴것
	if(a.length() != b.length()){
		return a.length() > b.length();
    } 
    
    // 3. 사전 순  
    return a < b;

}


bool isLonger(string a, string b){
	if(a.length() > b.length()){
		return true;
    }
	else{
		return false;
	}
}

int main(){
	
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> m;
	
	for(int i = 0; i < n; i++){
		
		string s;
		
		cin >> s;
		
		if(s.length() < m){
			continue;
		}
		
		v.push_back(s);
		
		if(mp.find(s) == mp.end()){
			mp[s] = 1;
		}
		else{
			mp[s]++;
		}
	}
	
	if(v.empty()){
		return 0;
	}
	

	sort(v.begin(), v.end(), compare); 
	
	//중복 제거
	v.erase(unique(v.begin(), v.end()), v.end());
	
	for(int i = 0; i < v.size(); i++){
		cout << v[i] << "\n";
	}
	
	
		
}
