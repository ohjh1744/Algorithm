#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
vector <long long> v;
long long ans;

int main()
{
	cin >> n;
	for(int i = 0; i < n; i++){
		int num;
		cin >> num;
		v.push_back(num);
    }
    
    sort(v.rbegin(), v.rend());
    
    for(int i = 0; i < n; i++){
		long long num = v[i] - (i+1 - 1);
		if(num < 0){
			num = 0;
		}
		ans = ans + num;
    }
    
    cout << ans << "\n";
}
