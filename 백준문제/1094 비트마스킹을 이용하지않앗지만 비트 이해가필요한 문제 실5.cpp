#include <iostream>
using namespace std;

unsigned long long n;
unsigned long long ans; 

//https://dkwjdi.tistory.com/232
//���� ������ ������ ������ ���������� ���� ����. 
// �ð����⵵�� �ִ� while���� �ִ� 39���ϵ�, 500000000000 < 2�� 39�� 
int main()
{
	cin >> n;
	int ct = 0;
	while(n > 0){
		unsigned long long r = n % 2;
		if(r== 1){
			ct++;
		}
		n = n/2;			
	}
	
	cout << ct << "\n";
	
}
