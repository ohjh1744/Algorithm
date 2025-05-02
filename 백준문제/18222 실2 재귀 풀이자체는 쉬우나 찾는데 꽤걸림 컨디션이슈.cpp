#include <iostream>
using namespace std;

long long k;

// k번째 값은 k - 2의 거듭제곱값을  반전시킨것과 동일.
// k값을 넘지 않는 가장 큰 k-2의 거듭제곱값을 구하면 됨. 
int sol(long long n){
	if(n == 1){
		return 0;
	}
	else{
		long long x = 1;
		
		while(x*2 < n){
			x = x*2;
		}
		
		return 1 - sol(n - x);
	}
}

int main(){
	
	cin >> k;
	
	cout << sol(k);
}
