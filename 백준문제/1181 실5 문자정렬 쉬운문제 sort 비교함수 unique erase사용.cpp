#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> v;
int n;

bool compare(string a, string b){
	if(a.length() < b.length()){
		return true;
	}
	else{
		if(a.length() == b.length()){
			for(int i = 0; i < a.length(); i++){
				if(a[i] == b[i]){
					continue;
				}
				else if(a[i] < b[i]){
					return true;
				}
				else if(a[i] > b[i]){
					return false;
				}
			}
		}
		return false;
	}
}


int main(){
	cin >> n;
	for(int i = 0; i < n; i++){
		string s;
		cin >> s;
		v.push_back(s);
	}
	
	sort(v.begin(), v.end(), compare);
	
	v.erase(unique(v.begin(), v.end()), v.end());
	
	for(int i = 0; i < v.size(); i++){
		cout << v[i] << "\n";
	}
} 
