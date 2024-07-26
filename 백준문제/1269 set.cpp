#include <iostream>
#include <set>
using namespace std;

set <int> a;
set <int> b;
int n, m;
int ct;
int ans;

int main()
{
	cin >> n >> m;
	
	for(int i = 0; i < n; i++){
		int item;
		cin >> item;
		a.insert(item);
	}
	
	for(int i = 0; i < m; i++){
		int item;
		cin >> item;
		b.insert(item);
		if(a.find(item) != a.end()){
			ct++;
		}
	}
	ans = ans + (a.size() - ct) + (b.size() - ct);
	cout << ans ;
}
