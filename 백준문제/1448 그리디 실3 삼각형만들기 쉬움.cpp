#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector <int > v;
int n;
int b;

int main()
{
	cin >> n;
	for(int i = 0; i < n; i++){
		int num;
		cin >> num;
		v.push_back(num);
	}
	
	sort(v.rbegin(), v.rend());
	for(int i = 0; i < n-2; i++){
		int s = v[i+1] + v[i+2];
		if(v[i] < s){
			cout << v[i] + s << "\n";
			return 0;
		}
	}
	b= true;
	if(b){
		cout << -1 << "\n";
	}
}

