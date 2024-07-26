#include <iostream>
using namespace std;

int n, k;
int ans;
int main()
{
	cin >> n >> k;
	while(1){
		int i = n;
		int full_s = 0;
		while(i>=1){
			int n_s = i%2;
			i = i /2;
			full_s = full_s + n_s;
		}
		if(full_s > k){
			ans++;
			n++;
		}
		else{
			break;
		}
	}
	cout << ans << endl;
}
