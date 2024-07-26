#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> a;
vector <int> b;

int main()
{
	int n , num_a , num_b;
	cin >> n;
	
	for(int i = 0; i < n ; i++){
		 cin >> num_a;
		 a.push_back(num_a);
	}
	
	for(int i = 0; i < n ; i++){
		 cin >> num_b;
		 b.push_back(num_b);
	}
	
	sort(a.rbegin(), a.rend());
	sort(b.begin(), b.end());
	
	int ans = 0;
	for(int i = 0; i < n ; i++){
		 ans = ans + (a[i] * b[i]);
	}
	cout << ans << endl;
	
}
