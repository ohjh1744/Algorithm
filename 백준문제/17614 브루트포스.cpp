#include <iostream>
#include <vector>
using namespace std;


int main()
{
	vector <int> v;
	
	int n;
	cin >> n;
	
	int ct = 0;
	
	for(int i = 1; i <= n; i++){
		int num = i;
		while(num != 0){
			int m = num % 10;
			v.push_back(m);
			num = num / 10;
		}
		for(int j = 0; j < v.size(); j++){
			if(v[j] == 3 || v[j] == 6 || v[j] == 9){
				ct++;
			}
		}
		
		v.clear();
	}
	
	cout << ct;


}
