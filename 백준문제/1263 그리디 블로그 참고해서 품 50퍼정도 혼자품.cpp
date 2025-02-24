#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int ans= 99999999;
vector < int > v;

bool compare(int a, int b){
	return a > b;
}

int main(){
	

	v.push_back(5);
	
	v.push_back(4);
	
	v.push_back(2);
	
	v.push_back(6);
	
	v.push_back(3);
	
	sort(v.begin(), v.end(), compare);
	
	for(int i = 0; i < v.size(); i++){
		cout << v[i] << endl;
	}
	
	
}
