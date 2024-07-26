#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> v(0);
	
	for(int i = 1; i<= n; i++){
		int st;
		cin >> st;
		v.insert(v.begin()+st, i);
	}
	
	for(int i = n-1; i >= 0; i--){
		cout << v[i] << " " ;
	}
	
	return 0;
	
	
}

