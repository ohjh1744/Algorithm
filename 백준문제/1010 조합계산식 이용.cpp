#include <iostream>
using namespace std;

int n, m; // mÁß¿¡ n »Ì±â mCn
long long ans = 1;

int main()
{
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	
	for(int i =0; i < t; i++){
		int temp = 1;
		cin >> n >> m;
		for(int j = m; j > m-n; j--){
			ans = ans * j;
			ans = ans / temp;
			temp++;
		}
		
		cout << ans << endl;
		ans = 1;
	} 
}
