#include <iostream>
using namespace std;

long long k;

// k��° ���� k - 2�� �ŵ���������  ������Ų�Ͱ� ����.
// k���� ���� �ʴ� ���� ū k-2�� �ŵ��������� ���ϸ� ��. 
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
