#include <iostream>
#include <vector>
using namespace std;

int n;
vector <int> v;
int ans = 0;
int minValue;

int main(){
	cin >> n;
	
	for(int i = 0; i < n; i++){
		int num;
		cin >> num;
		v.push_back(num);
	}
	
	minValue = v[0];
	
	for(int i = 1; i < v.size(); i++){
		//얻을수있는 이득 업데이트 
		if(v[i] > minValue){
			ans = max(ans, v[i] - minValue);
		}
		//최소값 업데이트 
		else{
			minValue = v[i];
		}
	}
	
	cout << ans;
} 
