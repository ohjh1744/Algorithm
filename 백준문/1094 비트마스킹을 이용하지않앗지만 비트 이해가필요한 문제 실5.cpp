#include <iostream>
using namespace std;

unsigned long long n;
unsigned long long ans; 

//https://dkwjdi.tistory.com/232
//문제 설명이 ㅈ같은 문제라 문제설명은 위에 참고. 
// 시간복잡도는 최대 while문은 최대 39이하돔, 500000000000 < 2의 39승 
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
