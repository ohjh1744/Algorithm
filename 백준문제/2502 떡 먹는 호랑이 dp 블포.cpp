#include <iostream>
using namespace std;

int d, k;
int a[31];
int b[31];
int ans1, ans2;

// 첫날 a 다음날 b 세번째날 a+b 네번째날 a + 2b 식으로 생각하면 풀림 
int main()
{
	cin >> d >> k;
	a[1] = 1;
	b[1] = 0;
	b[2] = 1;
	a[2] = 0;
	for(int i = 3 ; i <= d; i++){
		 a[i] = a[i-2] + a[i-1];
		 b[i] = b[i-2] + b[i-1];
	}
	
	for(int i = 1; i <= 100000; i++){
		int num = k - (a[d] * i);
		if(num % b[d] != 0){
			continue;
		}
		ans1 = i;
		ans2 = num / b[d];
		cout << ans1 << "\n";
		cout << ans2 << "\n";
		break;
	}
	
	return 0;
	
}
