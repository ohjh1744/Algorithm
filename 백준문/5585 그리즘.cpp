#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n;
	cin >> n;
	
	int n_2 = 1000 - n; // 1000 - 380 = 620
	int ans = 0; // 동전개수 
	
	int v[] = { 500, 100, 50 , 10, 5, 1};
	
	for(int i = 0; i < 6; i++){
		if(n_2 >= v[i]){
			ans = ans + n_2 / v[i];
		    n_2 = n_2 % v[i];
		}
	}
	
	cout << ans << endl;
	
}
