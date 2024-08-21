#include <iostream>
#include <vector>
using namespace std;

vector <int> v;

int main()
{
	int n , k;
	cin >> n >> k;
	
	for(int i = 0; i < n ; i++){
		int coin;
		cin >> coin;
		v.push_back(coin);
	}
	
	int ct = 0;
	
	for(int i = v.size() - 1; i >= 0; i--){
		if(k == 0){
			break;
		}
		
		if(k >= v[i]){
			int m = k / v[i];
			ct = ct + m;
			k = k % v[i];	
		}
	}
	
	cout << ct << endl;
}
