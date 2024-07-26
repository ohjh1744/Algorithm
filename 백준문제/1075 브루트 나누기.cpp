#include <iostream>
using namespace std;

int main()
{
	int n;
	int f;
	int ans = 0;
	
	cin >> n >> f;
	
	n = n / 100;
	n = n * 100;
	
	while((n + ans) % f != 0 && ans < 100){
		ans++;
	}
	
	if(ans < 10){
		printf("0%d", ans);
	}
	else
	   cout << ans; 
}
